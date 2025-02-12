#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
class CircleDetectorNode : public rclcpp::Node
{
public:
    CircleDetectorNode() : Node("circle_detector")
    {
        image_sub = this->create_subscription<sensor_msgs::msg::Image>(
            "/camera", 10, std::bind(&CircleDetectorNode::image_callback, this, std::placeholders::_1));

        circle_pub = this->create_publisher<geometry_msgs::msg::Point>("/circle_detected", 10);
        // Создаём издателя для публикации координат наибольшего круга в топике "/circle_detected".

        processed_image_pub = this->create_publisher<sensor_msgs::msg::Image>("/camera/circle_detection", 10);
        // Создаём издателя для публикации обработанного изображения с выделенными кругами в топике "/camera/circle_detection".

        largest_circle_image_pub = this->create_publisher<sensor_msgs::msg::Image>("/camera/largest_circle", 10);
        // Создаём издателя для публикации изображения с только наибольшим кругом в топике "/camera/largest_circle".
    }

private:
    void image_callback(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        cv_bridge::CvImagePtr cv_ptr; // Указатель для преобразования сообщения ROS Image в OpenCV Mat
        try
        {
            cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
            // Преобразуем входное сообщение ROS (Image) в изображение OpenCV (Mat) с цветовым пространством BGR.
        }
        catch (cv_bridge::Exception &e)
        {
            RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
            // Ловим исключения, если преобразование не удалось, и выводим сообщение об ошибке в лог.
            return;
        }

        cv::Mat gray;
        cv::cvtColor(cv_ptr->image, gray, cv::COLOR_BGR2GRAY);
        // Преобразуем изображение в оттенки серого для упрощения обработки.

        cv::GaussianBlur(gray, gray, cv::Size(9, 9), 2, 2);
        // Применяем размытие Гаусса для уменьшения шума и сглаживания изображения.

        std::vector<cv::Vec3f> circles;
        // Вектор для хранения параметров найденных кругов (x, y, радиус).

        cv::HoughCircles(
            gray, circles, cv::HOUGH_GRADIENT, 1, gray.rows / 8,
            150, 70, 20, 200);
        // Применяем преобразование Хафа для поиска кругов:
        // gray: входное изображение в градациях серого;
        // circles: вектор для хранения найденных кругов;
        // HOUGH_GRADIENT: метод Хафа;
        // 1: масштаб изображения;
        // gray.rows / 8: минимальное расстояние между центрами кругов;
        // 150: порог для Canny;
        // 20, 200: минимальный и максимальный радиусы окружностей.

        geometry_msgs::msg::Point circle_msg;
        // Сообщение ROS для публикации координат центра и радиуса круга.

        cv::Mat largest_circle_image = cv_ptr->image.clone();
        // Копируем исходное изображение для последующей обработки изображения с только наибольшим кругом.

        if (!circles.empty()) // Проверяем, найдены ли круги
        {
            cv::Vec3f largest_circle = circles[0];
            // Предполагаем, что первый найденный круг — наибольший.

            for (const auto &circle : circles)
            {
                cv::Point center(cvRound(circle[0]), cvRound(circle[1]));
                int radius = cvRound(circle[2]);
                // Преобразуем параметры текущего круга (центр и радиус) в целые числа.

                cv::circle(cv_ptr->image, center, radius, cv::Scalar(0, 255, 0), 3);
                // Рисуем текущий круг зелёным цветом на изображении.

                if (circle[2] > largest_circle[2])
                {
                    largest_circle = circle;
                    // Обновляем данные о наибольшем круге, если текущий больше.
                }
            }

            if (largest_circle[2] >= 20 && largest_circle[2] <= 200)
            {
                cv::Point largest_center(cvRound(largest_circle[0]), cvRound(largest_circle[1]));
                int largest_radius = cvRound(largest_circle[2]);
                // Вычисляем параметры наибольшего круга.

                circle_msg.x = largest_circle[0];
                circle_msg.y = largest_circle[1];
                circle_msg.z = largest_circle[2];
                // Заполняем сообщение ROS координатами и радиусом наибольшего круга.

                circle_pub->publish(circle_msg);
                // Публикуем сообщение о наибольшем круге.

                cv::circle(largest_circle_image, largest_center, largest_radius, cv::Scalar(0, 0, 255), 3);
                // Рисуем наибольший круг красным цветом на отдельной копии изображения.

                RCLCPP_INFO(this->get_logger(), "Largest Circle: center=(%.2f, %.2f), radius=%.2f",
                            circle_msg.x, circle_msg.y, circle_msg.z);

            }
        }
        else
        {
            circle_msg.x = 0;
            circle_msg.y = 0;
            circle_msg.z = 0;
            // Если кругов нет, публикуем сообщение с нулевыми параметрами.

            circle_pub->publish(circle_msg);
            RCLCPP_INFO(this->get_logger(), "No circles detected.");
            // Логируем сообщение об отсутствии кругов.
        }


        processed_image_pub->publish(*cv_ptr->toImageMsg());
        // Публикуем обработанное изображение с выделенными всеми кругами.

        std::shared_ptr<cv_bridge::CvImage> largest_circle_msg =
            std::make_shared<cv_bridge::CvImage>(*cv_ptr);
        // Создаём сообщение ROS для изображения с наибольшим кругом.

        largest_circle_msg->image = largest_circle_image;
        largest_circle_image_pub->publish(*largest_circle_msg->toImageMsg());
        // Публикуем изображение с только наибольшим кругом.
    }

    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_sub;
    rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr circle_pub;
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr processed_image_pub;
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr largest_circle_image_pub;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CircleDetectorNode>());
    rclcpp::shutdown();
}
