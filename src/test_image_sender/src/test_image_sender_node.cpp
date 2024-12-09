//Заголовочный файл клиентской библеотеки ROS
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.hpp>
#include <opencv2/opencv.hpp>
// opencv4 ???

//Пространство имен для литералов интервалов времени
using namespace std::chrono_literals;

//Класс узла
class TestImageSensor : public rclcpp::Node {
public:
    //Конструктор класса
    TestImageSensor():
        Node("test_image_sensor_node"), //Имя узла
        counter(0)
    {

        /*
        инициализация публикатора с указанием экземпляра класса, "/image" --- название топика где публикуется изображение
        */
        pub = image_transport::create_publisher(this,"/image" );
        image = cv::imread("/usr/share/backgrounds/Blue_flower_by_Elena_Stravoravdi.jpg"); // загрузка изображений
        timer = //Таймер для создания прерывания
            this->create_wall_timer(500ms,
                                    std::bind(&TestImageSensor::timer_callback,
                                              this));
    }
private:
    image_transport::Publisher pub; //публикатор для изображения
    cv::Mat image;
    rclcpp::TimerBase::SharedPtr timer;
    unsigned int counter;
    //Функция обратного вызова (callback) для таймера
    void timer_callback() {
        // объект msg --- сообщение содержащее изображение
        sensor_msgs::msg::Image::SharedPtr msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", image).toImageMsg();
        pub.publish(msg);


    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<TestImageSensor>());
    rclcpp::shutdown();
    return 0;
}
//  source install/setup.bash
