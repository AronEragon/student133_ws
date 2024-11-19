#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32.hpp>
#include <test_custom_msg/msg/triangle.hpp>

class PartSubscriber : public :: rclcpp ::Node {
public:
    PartSubscriber():
        Node("part_subscriber")
{
    subscriber =
            this -> create_subscription<test_custom_msg::msg::Triangle>
            ("/triangle", 8,
             std :: bind (&PartSubscriber::message_callback,
                          this,
                          std:: placeholders::_1));
}


private:
      rclcpp :: Subscription<test_custom_msg::msg::Triangle> :: SharedPtr
                                                  subscriber;


void message_callback(const test_custom_msg::msg::Triangle &msg)
{
    float square = (fabs((msg.b.x-msg.a.x)*(msg.c.y-msg.a.y)-(msg.c.x-msg.a.x)*(msg.b.y-msg.a.y)))/2;
    RCLCPP_INFO_STREAM(this->get_logger(),
                       "Square: "<<square);
}
};

int main(int argc, char **argv)
{
    rclcpp :: init(argc, argv);
    rclcpp :: spin (std :: make_shared <PartSubscriber>());
    rclcpp :: shutdown();
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
