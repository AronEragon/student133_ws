#include<rclcpp/rclcpp.hpp>
#include"test_custom_srv/srv/circle_square.hpp"

using namespace std::chrono_literals;

class TestClient: public rclcpp::Node{
public:
  TestClient():
    Node("test_client_node"){
    client =
        this->create_client<test_custom_srv::srv::CircleSquare>("circle_square");
    timer = this->create_wall_timer(5s,//с какой частотой вызывается функция(сервис)
                                    std::bind(&TestClient::timer_callback,
                                              this));
  }

private:
  rclcpp::TimerBase::SharedPtr timer;
  rclcpp::Client<test_custom_srv::srv::CircleSquare>::SharedPtr
                  client;
  void timer_callback(){
  /* Здесь будем вызывать сервис
   Ждем доступности сервиса */
    while(!client->wait_for_service(1s)){
      RCLCPP_INFO_STREAM(this->get_logger(),
                         "Wait for service ... ");
    }
    //Формируе запрос для сервиса
    test_custom_srv::srv::CircleSquare::Request::SharedPtr //<- auto можно заменить из Piyton
        request =
        std::make_shared<test_custom_srv::srv::CircleSquare::Request>();
    request->radius = 6;
    request->part = 1.0;
    //Отправляем запрос
    client->async_send_request(//асинхронный вызов сервиса
          request,
          std::bind(&TestClient::response_callback,
                    this,
                    std::placeholders::_1));// Связывает сигнал(аргумент) с функцией
  }
//функция для получения статуса
  void response_callback(
      rclcpp::Client<test_custom_srv::srv::CircleSquare>::SharedFuture
      client_f){
    //получаем статус клиента в асинхронном вызове
    auto status = client_f.wait_for(1s); //<- auto можно заменить на std::future_status C++/C
    //проверяем статус клиента
    if(status== std::future_status::ready){//Проверяется поолучен ли ответ и выводится сообщение
      RCLCPP_INFO_STREAM(this->get_logger(),
                         "Response recived: "<<client_f.get()->square);
    }
    else {
      RCLCPP_INFO_STREAM(this->get_logger(),
                         "Service in progress...");
    }


  }
};

int main(int argc, char **argv)
{
  rclcpp::init(argc,argv);
  rclcpp::spin(std::make_shared<TestClient>());
  rclcpp::shutdown();
}


/*
 * Лабораторная работа 2 чатсь 2
 * Создать сервис по вычислениям площади треугольника
 * Сервису передаются длины трех сторон треугольника
 * Он  вычисляет по формуле Герона площадь
 * Площадь возвращается в качестве ответа
 *
 * Написать ему узел сервиса и узел клиента
 */
