#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/int32.hpp>
using namespace std::chrono_literals;

class TestCounter : public rclcpp::Node {
public:
  TestCounter():
    Node("test_subscriber")
  {
    subscriber1 =
        this->create_subscription<std_msgs::msg::Int32> ("msg_tr",8, std::bind(&TestCounter::message_callback_pub, this, std::placeholders::_1));

    subscriber2 =
        this->create_subscription<std_msgs::msg::Int32>("msg_rcv",8, std::bind(&TestCounter::message_callback_sub, this, std::placeholders::_1));

    publisher = this->create_publisher<std_msgs::msg::Int32>("msg_diff",8);
    timer = this->create_wall_timer(1s, std::bind(&TestCounter::timer_callback, this));
  }



private:

  int sub=0;
  int pub=0;
  rclcpp::TimerBase::SharedPtr timer;

  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher;
  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr
                                                    subscriber1;
  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr
                                                    subscriber2;
   void message_callback_sub(const std_msgs::msg::Int32)
  {
    std_msgs::msg::Int32 msg;
    sub++;

  }
    void message_callback_pub(const std_msgs::msg::Int32)
   {
     std_msgs::msg::Int32 msg;
    pub++;

   }

    void timer_callback() {

      std_msgs::msg::Int32 msg;

      msg.data= pub-sub;
      RCLCPP_INFO_STREAM(this->get_logger(), msg.data);
      publisher->publish(msg);


}
    };


int main(int argc, char **argv)
{
  rclcpp::init(argc,argv);
  rclcpp::spin(std::make_shared<TestCounter>());
  rclcpp::shutdown();

}

//1) В узле публикатора создать счетчик колличества отправленных сообщений
//и публиковать это значение в сообщении типа std_msgs::int32 в топик msg_tr;
//2) В узле подписчика создать счетчик принятых сообщений и публиковать это значение
//в сообщениии типа std_msgs::Int32 в топпик msg_rcv
//3) Создать пакет и узел в нем, который будет подписываться на сообщения из
// топиков msg_tr и msg_rcv, вычислять между ними разницу и публиковать эту разницу в сообщении
// типа std_msgs::Int32 топик msg_diff
