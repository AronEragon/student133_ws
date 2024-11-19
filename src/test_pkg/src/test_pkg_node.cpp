//Заголовочный файл клиентской библеотеки ROS
#include <rclcpp/rclcpp.hpp>
//Пространство имен для литералов интервалов времени
using namespace std::chrono_literals;

//Класс узла
class TestNode : public rclcpp::Node {
public:
  //Конструктор класса
  TestNode():
        Node("test_node"),
        counter(0)
        //Имя узла
  {
    timer = //Таймер для создания прерывания
        this->create_wall_timer(1s,
                                std::bind(&TestNode::timer_callback,
                                          this));
  }
private:
  //Таймер вызова ф-ции
  rclcpp::TimerBase::SharedPtr timer;
    unsigned int counter;
  //Функция обратного вызова (callback) для таймера
  void timer_callback() {
    //Вывод сообщения в консоль
    RCLCPP_INFO_STREAM(this->get_logger(),
                       "Hello world");
  }
};

int main(int argc, char **argv)
{
rclcpp::init(argc,argv);
rclcpp::spin(std::make_shared<TestNode>());
rclcpp::shutdown();
return 0;
}
