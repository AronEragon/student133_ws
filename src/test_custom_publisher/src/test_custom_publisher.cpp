#include <rclcpp/rclcpp.hpp>
#include "test_custom_msg/msg/circle.hpp"
using namespace std::chrono_literals;

class CustomPublisher: public rclcpp::Node {
public:
  CustomPublisher():
    Node("custom_publisher_node"){
    publisher =
        this->create_publisher<test_custom_msg::msg::Circle>
        ("/circle_test", 10);
    timer =
        this->create_wall_timer(1s,
                                std::bind(&CustomPublisher::
                                          timer_callback, this));
  }

private:
  rclcpp::TimerBase::SharedPtr timer;
  rclcpp::Publisher<test_custom_msg::msg::Circle>::SharedPtr
  publisher;
  void timer_callback() {
    test_custom_msg::msg::Circle circle_msg =
        test_custom_msg::msg::Circle();
    circle_msg.center.x=45;
    circle_msg.center.y=25;
    circle_msg.center.z=5;
    circle_msg.radius=12;
    publisher->publish(circle_msg);
  }
};

int main(int argc, char **argv)
{
  rclcpp::init(argc,argv);
  rclcpp::spin(std::make_shared<CustomPublisher>());
  rclcpp::shutdown();
  return 0;
}



/*
* Лабораторная 2 часть 1
создать свой тип сообщения который хранит
три вершины треугольника в формате
geometry_msgs/Point

* Написать узел публикатора, который задает
значение вершинам и публикует сообщение в топик
treangle

* Написать узел подписчика который принемает это сообщение и вычисляет площадь
заданного вершинами треугольника, а затем выводит полученное сообщение в консоль
*/
