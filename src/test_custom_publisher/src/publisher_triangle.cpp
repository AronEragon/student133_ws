#include<rclcpp/rclcpp.hpp>
#include "test_custom_msg/msg/triangle.hpp"

using namespace std:: chrono_literals;

class PartPublisher: public rclcpp :: Node{
public:
    PartPublisher():
        Node("custom_publisher_node"){
        publisher=
                this-> create_publisher<test_custom_msg::msg::Triangle>
                ("/triangle", 10);
        timer=
                this->create_wall_timer(1s,
                                        std::bind(&PartPublisher ::timer_callback, this));
    }
private:
rclcpp::TimerBase::SharedPtr timer;
rclcpp:: Publisher<test_custom_msg::msg::Triangle>::SharedPtr
publisher;
void timer_callback(){
    test_custom_msg::msg::Triangle triangle_msg =
            test_custom_msg::msg::Triangle();

    triangle_msg.a.x = 0;
    triangle_msg.a.y = 0;
    triangle_msg.a.z = 0;

    triangle_msg.b.x = 0;
    triangle_msg.b.y = 6;
    triangle_msg.b.z = 0;

    triangle_msg.c.x = 8;
    triangle_msg.c.y = 0;
    triangle_msg.c.z = 0;

    publisher->publish(triangle_msg);
}

};


int main(int argc, char **argv)
{
    rclcpp :: init(argc, argv);
    rclcpp :: spin (std :: make_shared <PartPublisher>());
    rclcpp :: shutdown();

}
/*Лабораторная 2 часть 1.
1. создать свой тип сообщения, который хранит три вершины треугольника,
 в формате geometry_msgs/Point.

2. Написать узел публикатора, который задает значения вершинам и публикует сообщение
в топик triangle

3. написать узел подписчика, который принимает это сообщение и вычисляет площадь
заданного вершинами треугольника, а затем выводит полученное значение в консоль*/
