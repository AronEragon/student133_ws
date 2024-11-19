#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/int32.hpp>
using namespace std::chrono_literals;

class TestPublisher : public rclcpp::Node {
public:
  TestPublisher():
    Node("test_publisher"),
    counter(1) {
    //Инициализация публикатора
    //Обязательно указать тип сообщения в шаблоне
    //Обязательно указать название топика - "test_topic"

    // publisher = this->create_publisher<std_msgs::msg::String>
    //                         ("msg_tr",8);

    publisher = this->create_publisher<std_msgs::msg::Int32>
                            ("msg_tr",8);



    //Таймер определяет с какой частотой будут публиковаться сообщения
    timer =
        this->create_wall_timer(1s, std::bind(&TestPublisher::timer_callback, this));
  }
private:
  unsigned int counter;
  rclcpp::TimerBase::SharedPtr timer;
  //Объект публикатора
  //Обязательно указать

  // rclcpp::Publisher<std_msgs::msg::String>::SharedPtr
  //               publisher;

  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr
                  publisher;

  void timer_callback() {
    //Объект сособщения

    // std_msgs::msg::String msg;
    // msg.data = "Hello world " + std::to_string(counter++);
    // RCLCPP_INFO_STREAM(this->get_logger(),
    //                    "Published: "<<msg.data);
    // publisher->publish(msg);

    std_msgs::msg::Int32 msg;
        msg.data = (counter++);
        RCLCPP_INFO_STREAM(this->get_logger(),
                           msg.data);
        publisher->publish(msg);
}
};

int main(int argc, char **argv)
{
rclcpp::init(argc,argv);
rclcpp::spin(std::make_shared<TestPublisher>());
rclcpp::shutdown();
}
//Лабораторная работа 1
//1) В узле публикатора создать счетчик колличества отправленных сообщений
//и публиковать это значение в сообщении типа std_msgs::int32 в топик msg_tr;
//2) В узле подписчика создать счетчик принятых сообщений и публиковать это значение
//в сообщениии типа std_msgs::Int32 в топпик msg_rcv
//3) Создать пакет и узел в нем, который будет подписываться на сообщения из
// топиков msg_tr и msg_rcv, вычислять между ними разницу и публиковать эту разницу в сообщении
// типа std_msgs::Int32 топик msg_diff

