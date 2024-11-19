#include <rclcpp/rclcpp.hpp>
#include <math.h>
/*Параметры (Parameters) это механизм РОС
 * который позволяет устанавливать и изменять в процессе
 * работы узла какие либо значения, определяющие
 * его работу
 *
 * Получение значения параметра в терминале (обычном)
 * ros2 param get /test_param_note num_param
 *
 * Установление значения параметра в терминале (обычном)
 * ros2 param set /test_param_note num_param 25.6
 */

using namespace std::chrono_literals;

double p;

class TestParam : public rclcpp::Node {

private:
  rclcpp::TimerBase::SharedPtr timer;



public:
  TestParam():
    Node("test_param_node")
  {
    //Строковый параметр
    this->declare_parameter("string_param", //имя параметра
                            "test_string"); //значение параметра
    //Числовой параметр
    this->declare_parameter("num1_param", 5.0); //Значение первой стороны треугольника по умолчанию (если не работает launch)
    this->declare_parameter("num2_param", 5.0); //Значение второй стороны треугольника
    this->declare_parameter("num3_param", 5.0); //Значение третьей стороны треугольника

    timer = this->create_wall_timer(1s,
                                    std::bind(&TestParam::timer_callback,
                                              this));

  }

  //получаем значение параметров
  void timer_callback() {
    std::string str_param =
        this->get_parameter("string_param").as_string();
    double num1_param =
        this->get_parameter("num1_param").as_double();
    double num2_param =
        this->get_parameter("num2_param").as_double();
    double num3_param =
        this->get_parameter("num3_param").as_double();
    double p = (num1_param+num2_param+num3_param)/2;
    RCLCPP_INFO_STREAM(this->get_logger(),
                       "Str: "<<str_param<<" num1: "<<num1_param<<" num2: "<<num2_param<<" num3: "<<num3_param<<
                       " Area of ​​a triangle: "<<sqrt(p*(p-num1_param)*(p-num2_param)*(p-num3_param)));
  }
};

int main(int argc, char **argv)
{
  rclcpp::init(argc,argv);
  rclcpp::spin(std::make_shared<TestParam>());
  rclcpp::shutdown();
}

/*Лабораторная работа 3 часть 1
 * Задание:
 * Написать узел. Который принимает в качестве параметров
 * длины сторон треугольника и вычисляет его площадь
 * Вычисление площади осуществляется каждую секунду и выводится в консоль
 * Первоначальные значения параметров передать с помощью launch файла
 * Проверить работу узла при измененных параметрах с помощью
 * утилиты ros2 param
 */




