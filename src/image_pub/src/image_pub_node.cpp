#include <rclcpp/rclcpp.hpp> // Подключение библиотеки ROS2 для создания узла
#include <sensor_msgs/msg/image.hpp> // Подключение библиотеки для работы с сообщениями изображения в формате ROS2
#include <image_transport/image_transport.hpp> // Подключение библиотеки image_transport для работы с передачей изображений
#include <cv_bridge/cv_bridge.h> // Подключение библиотеки cv_bridge для преобразования между ROS Image и OpenCV Mat
#include <opencv2/opencv.hpp> // Подключение основной библиотеки OpenCV для обработки изображений

// Объявление класса ImagePublisherNode, наследующегося от rclcpp::Node (узел ROS2)
class ImagePublisherNode : public rclcpp::Node
{
public:
    // Конструктор класса ImagePublisherNode
    ImagePublisherNode() : Node("image_publisher_node"), image_idx(0) // Инициализация узла с именем "image_publisher_node" и переменной image_idx_ со значением 0
    {
        image_pub = image_transport::create_publisher(this, "/camera"); // Создание издателя для публикации изображений в топик "/camera"
        timer = this->create_wall_timer( // Создание таймера для вызова функции publish_image через каждые 1200 миллисекунд
            std::chrono::milliseconds(1200), std::bind(&ImagePublisherNode::publish_image, this));

        // Загрузка изображений
        image1 = cv::imread("/home/eragon/student133_ws/Circle_big2.jpg"); // Загрузка первого изображения
        image2 = cv::imread("/home/eragon/student133_ws/Circle2.png"); // Загрузка второго изображения

        if (image1.empty() || image2.empty()) // Проверка, удалось ли загрузить изображения
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to load images"); // Вывод сообщения об ошибке, если изображения не загружены
            rclcpp::shutdown(); // Завершение работы ROS2, если изображения не удалось загрузить
        }
    }

private:
    // Метод publish_image для публикации изображений
    void publish_image()
    {
        // Выбор изображения для публикации (поочерёдно)
        cv::Mat current_image = (image_idx % 2 == 0) ? image1 : image2; // Выбор первого или второго изображения
        image_idx++; // Увеличение счётчика изображений

        // Преобразование изображения OpenCV в сообщение ROS2
        auto msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", current_image).toImageMsg(); // Преобразование Mat в ROS-сообщение
        msg->header.frame_id = "camera_optical"; // Установка идентификатора кадра в заголовке сообщения
        image_pub.publish(msg); // Публикация сообщения
    }

    image_transport::Publisher image_pub; // Издатель для передачи изображений
    rclcpp::TimerBase::SharedPtr timer; // Таймер для периодической публикации изображений
    cv::Mat image1, image2; // Переменные для хранения загруженных изображений
    int image_idx; // Счётчик для чередования изображений
};

// Главная функция
int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ImagePublisherNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
}
