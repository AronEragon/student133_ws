#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp> // Сообщения PointCloud2 для представления облаков точек
#include <sensor_msgs/point_cloud2_iterator.hpp> // Итераторы для удобного заполнения PointCloud2
#include <geometry_msgs/msg/point32.hpp> // Сообщение для 3D-точек с координатами float32
#include <geometry_msgs/msg/point.hpp> // Сообщение для 3D-точек с координатами float64
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.hpp>
#include <opencv2/opencv.hpp>
using namespace std::chrono_literals;

class TestPointCloud2 : public rclcpp::Node {
public:
    TestPointCloud2()
        : Node("pointcloud_node"),
        counter(0) // Инициализация счетчика
    {
        publisher = this->create_publisher<sensor_msgs::msg::PointCloud2>("/pointcloud2", 10);

        // Загрузка изображений глубины и RGB
        image_depth = cv::imread("/home/eragon/student133_ws/depth_dataset/depth_16uc1/depth_image_150.png", cv::IMREAD_ANYDEPTH); // Изображение глубины
        image_rgb = cv::imread("/home/eragon/student133_ws/depth_dataset/rgb/rgb_image_150.png"); // Изображение RGB

        timer = this->create_wall_timer(2000ms, std::bind(&TestPointCloud2::timer_callback_custom, this));
    }

private:
    unsigned int counter; // Счетчик вызовов таймера
    cv::Mat image_depth; // Изображение глубины
    cv::Mat image_rgb; // Изображение RGB
    rclcpp::TimerBase::SharedPtr timer; // Таймер для периодического вызова функции
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr publisher; // Издатель сообщений PointCloud2
    std::vector<float> K = { 570.342, 0, 319.5, // Матрица калибровки камеры
                            0, 570.342, 239.5,
                            0, 0, 1 };

    void timer_callback_custom() {
        sensor_msgs::msg::PointCloud2 cloud2; // Сообщение для облака точек
        cloud2.header.frame_id = "depth_cloud_optical"; // Установка системы координат
        cloud2.header.stamp = this->get_clock()->now(); // Установка текущего времени
        cloud2.is_bigendian = false;
        cloud2.is_dense = false;

        unsigned int points_count = 0; // Счетчик точек

        // Определение полей для облака точек
        sensor_msgs::msg::PointField field;
        field.name = "x";
        field.offset = 0;
        field.datatype = sensor_msgs::msg::PointField::FLOAT32;
        field.count = 1;
        cloud2.fields.push_back(field);

        field.name = "y";
        field.offset = sizeof(float);
        field.datatype = sensor_msgs::msg::PointField::FLOAT32;
        field.count = 1;
        cloud2.fields.push_back(field);

        field.name = "z";
        field.offset = 2 * sizeof(float);
        field.datatype = sensor_msgs::msg::PointField::FLOAT32;
        field.count = 1;
        cloud2.fields.push_back(field);

        field.name = "rgb";
        field.offset = 3 * sizeof(float);
        field.datatype = sensor_msgs::msg::PointField::FLOAT32;
        field.count = 1;
        cloud2.fields.push_back(field);

        cloud2.point_step = 16; // 16 / 4

        // Итерация по всем пикселям изображения глубины
        for (int i = 0; i < image_depth.rows; i++) {
            for (int j = 0; j < image_depth.cols; j++) {
                float distance = image_depth.at<cv::uint16_t>(i, j); // Глубина в миллиметрах

                float z = distance / 1000.0f; // Глубина в метрах
                float x = ((j - K[2]) * z) / K[0]; // Координата x
                float y = ((i - K[5]) * z) / K[4]; // Координата y

                uint8_t r = image_rgb.at<cv::Vec3b>(i, j)[2]; // Значение красного канала
                uint8_t g = image_rgb.at<cv::Vec3b>(i, j)[1]; // Значение зеленого канала
                uint8_t b = image_rgb.at<cv::Vec3b>(i, j)[0]; // Значение синего канала

                // Заполнение данных для текущей точки
                cloud2.data.insert(cloud2.data.end(), reinterpret_cast<uint8_t*>(&x), reinterpret_cast<uint8_t*>(&x) + sizeof(float));
                cloud2.data.insert(cloud2.data.end(), reinterpret_cast<uint8_t*>(&y), reinterpret_cast<uint8_t*>(&y) + sizeof(float));
                cloud2.data.insert(cloud2.data.end(), reinterpret_cast<uint8_t*>(&z), reinterpret_cast<uint8_t*>(&z) + sizeof(float));

                // Добавление данных RGB
                cloud2.data.push_back(b);
                cloud2.data.push_back(g);
                cloud2.data.push_back(r);
                cloud2.data.push_back(0); // Альфа-канал (не используется)


                points_count++;
            }
        }

        cloud2.width = image_depth.cols; // Количество точек по ширине
        cloud2.height = image_depth.rows; // Количество точек по высоте
        cloud2.row_step = cloud2.point_step * image_depth.cols; // Размер строки в байтах

        publisher->publish(cloud2); // Публикация облака точек
    }
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TestPointCloud2>());
    rclcpp::shutdown();
    return 0;
}
