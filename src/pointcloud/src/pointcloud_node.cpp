#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.hpp> // Подключение для транспортировки изображений в ROS 2
#include <opencv2/opencv.hpp>

using namespace std::chrono_literals;

class LabPointCloud : public rclcpp::Node {
public:
    // Конструктор класса
    LabPointCloud()
        : Node("pointcloud_node")
    {
        publisher = this->create_publisher<sensor_msgs::msg::PointCloud>("/pointcloud", 10);

        image_depth = cv::imread("/home/eragon/student133_ws/depth_dataset/depth_16uc1/depth_image_50.png", cv::IMREAD_ANYDEPTH);

        timer = this->create_wall_timer(500ms, std::bind(&LabPointCloud::timer_callback, this));
    }

private:
    cv::Mat image_depth;
    rclcpp::TimerBase::SharedPtr timer;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud>::SharedPtr publisher;

    // Параметры камеры: фокусное расстояние и главная точка (матрица калибровки камеры)
    std::vector<float> K = { 570.342, 0, 319.5,
                            0, 570.342, 239.5,
                            0, 0, 1 };

    void timer_callback() {
        sensor_msgs::msg::PointCloud cloud; // Создание сообщения для облака точек
        cloud.header.frame_id = "depth_cloud_optical"; // Установка системы координат для облака
        cloud.header.stamp = this->get_clock()->now(); // Установка текущего времени для заголовка сообщения

        sensor_msgs::msg::ChannelFloat32 channel; // Канал для хранения интенсивности точек

        // Итерация по всем пикселям изображения глубины
        for (int y = 0; y < image_depth.rows; y++) {
            for (int x = 0; x < image_depth.cols; x++) {
                float distance = image_depth.at<cv::uint16_t>(y, x);


                    geometry_msgs::msg::Point32 point; // Создание точки с координатами x, y, z

                    // Вычисление координаты z в метрах
                    point.z = distance / 1000;
                    // Вычисление координаты x с учетом матрицы калибровки камеры
                    point.x = ((x - K[2]) * point.z) / K[0];
                    // Вычисление координаты y с учетом матрицы калибровки камеры
                    point.y = ((y - K[5]) * point.z) / K[4];

                    unsigned int intense = distance; // Использование значения глубины в качестве интенсивности

                    cloud.points.push_back(point); // Добавление точки в облако
                    channel.values.push_back(intense); // Добавление интенсивности в канал

            }
        }

        channel.name = "intensity"; // Название канала интенсивности
        cloud.channels.push_back(channel); // Добавление канала интенсивности в сообщение облака точек
        publisher->publish(cloud); // Публикация сообщения в топик "/pointcloud"
    }
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<LabPointCloud>());
    rclcpp::shutdown();
    return 0;
}
