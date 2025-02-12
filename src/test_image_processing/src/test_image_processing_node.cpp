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
        image = cv::imread("/home/eragon/Изображения/Znaki-foto.jpg"); // загрузка изображений

        cv::Mat image_gray;
        cv::cvtColor(image, image_gray, cv::COLOR_BGR2GRAY);
        cv::GaussianBlur(image_gray, image_gray, cv::Size(9,9),2,2);
        std::vector<cv::Vec3f> circles;
        cv::HoughCircles(image_gray, circles,CV_HOUGH_GRADIENT,1,image_gray.rows/8,200,100,0,0);
        for(int i = 0; i < circles.size();i++) {
            cv::circle(image,
                       cv::Point(circles[i][0], circles[i][1]),
                        circles[i][2],
                            cv::Scalar(0,255,0),6);
        }

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
//test_image_processing
