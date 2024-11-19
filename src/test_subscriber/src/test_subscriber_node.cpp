#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/int32.hpp>

using namespace std::chrono_literals;
// class TestSubscriber : public rclcpp::Node {
// public:
//   TestSubscriber():
//     Node("test_subscriber")
//   {
//     subscriber =
//         this->create_subscription<std_msgs::msg::String>
//         ("test_topic",8,
//          std::bind(&TestSubscriber::message_callback,
//                    this,
//                    std::placeholders::_1));
//   }
// private:
//   rclcpp::Subscription<std_msgs::msg::String>::SharedPtr
//                                                     subscriber;
//   void message_callback(const std_msgs::msg::String &msg) const
//   {
//     RCLCPP_INFO_STREAM(this->get_logger(),
//                       msg.data);
//   }
// };

class TestSubscriber : public rclcpp::Node {
public:
  TestSubscriber():
    Node("test_subscriber")
  {
    subscriber =
        this->create_subscription<std_msgs::msg::Int32>
        ("msg_tr",8,
         std::bind(&TestSubscriber::message_callback,
                   this,
                   std::placeholders::_1));
    publisher = this->create_publisher<std_msgs::msg::Int32>
                            ("msg_rcv",8);
    //Таймер определяет с какой частотой будут публиковаться сообщения
    timer =
        this->create_wall_timer(1s, std::bind(&TestSubscriber::timer_callback,
                                              this));
  }
//////////////////////////////////////////////////////




private:
  rclcpp::TimerBase::SharedPtr timer;
  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher;
  int counter = 0;

  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr
                                                    subscriber;
  void message_callback(const std_msgs::msg::Int32) /*const*/
  {
    std_msgs::msg::Int32 msg;
    counter++;

  }
  void timer_callback() {
    //Объект сособщения
    std_msgs::msg::Int32 msg;
    msg.data = counter;
        RCLCPP_INFO_STREAM(this->get_logger(), msg.data);
        publisher->publish(msg);
}

};

int main(int argc, char **argv)
{
  rclcpp::init(argc,argv);
  rclcpp::spin(std::make_shared<TestSubscriber>());
  rclcpp::shutdown();
}


//1) В узле публикатора создать счетчик колличества отправленных сообщений
//и публиковать это значение в сообщении типа std_msgs::int32 в топик msg_tr;
//2) В узле подписчика создать счетчик принятых сообщений и публиковать это значение
//в сообщениии типа std_msgs::Int32 в топпик msg_rcv
//3) Создать пакет и узел в нем, который будет подписываться на сообщения из
// топиков msg_tr и msg_rcv, вычислять между ними разницу и публиковать эту разницу в сообщении
// типа std_msgs::Int32 топик msg_diff
