//Заголовочный файл клиентской библеотеки ROS
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
//Пространство имен для литералов интервалов времени
using namespace std::chrono_literals;

//Класс узла
class TestBasicPublisher : public rclcpp::Node {
public:
    //Конструктор класса
    TestBasicPublisher():
        Node("test_basic_publisher_node"), //Имя узла
        counter(0)
    {
        publisher = this->create_publisher<std_msgs::msg::String>("/test_topic",10);
        timer = //Таймер для создания прерывания
            this->create_wall_timer(500ms,
                                    std::bind(&TestBasicPublisher::timer_callback,
                                              this));
    }
private:
    //Таймер вызова ф-ции
    rclcpp::TimerBase::SharedPtr timer;
       unsigned int counter;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher;
    //Функция обратного вызова (callback) для таймера
    void timer_callback() {
        std_msgs::msg::String message;
        message.data = "Counter " + std::to_string(counter);
        publisher->publish(message);
        RCLCPP_INFO_STREAM(this->get_logger(),"Publised: "<<message.data);
        counter++;
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<TestBasicPublisher>());
    rclcpp::shutdown();
    return 0;
}
