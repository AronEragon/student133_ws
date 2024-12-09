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
class TestImageReceiver : public rclcpp::Node {
public:
    //Конструктор класса
    TestImageReceiver():
        Node("test_image_receiver_node") //Имя узла

    {
        sub = image_transport::create_subscription(this, "/image",
                                                        std::bind(&TestImageReceiver::image_callback,
                                                             this,
                                                                std::placeholders::_1),"raw");


    }
private:

    cv::Mat image;
    image_transport::Subscriber sub;
    void image_callback(const sensor_msgs::msg::Image::ConstSharedPtr &msg) {
        cv_bridge::CvImagePtr cv_ptr;
        cv_ptr = cv_bridge::toCvCopy(msg, msg->encoding);
        image = cv_ptr->image;
        RCLCPP_INFO_STREAM(this->get_logger(),"Received image: "<<image.cols<<" x "<<image.rows);


    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<TestImageReceiver>());
    rclcpp::shutdown();
    return 0;
}
//  source install/setup.bash
