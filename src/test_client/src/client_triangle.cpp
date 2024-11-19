#include <rclcpp/rclcpp.hpp>
#include "test_custom_srv/srv/triangle_square.hpp"

using namespace std::chrono_literals;


class PartClient: public rclcpp:: Node{
public:
    PartClient():
        Node("part_client_node"){
        client =
                this-> create_client<test_custom_srv::srv::TriangleSquare>
                ("triangle_square");
        timer = this ->create_wall_timer(5s,
                                         std::bind(&PartClient::timer_callback,
                                                   this));

    }

    private:
    rclcpp::TimerBase::SharedPtr timer;
    rclcpp::Client<test_custom_srv::srv::TriangleSquare>::SharedPtr
    client;

    void timer_callback(){
        //здесь будем вызывать сервис
        //ждем доступности сервиса

        while(!client->wait_for_service(1s)){
            RCLCPP_INFO_STREAM (this->get_logger(),
                                "Waiting for service... ");
        }
        //формируем запрос для сервиса
        test_custom_srv::srv::TriangleSquare::Request::SharedPtr
        request = std:: make_shared<test_custom_srv::srv::TriangleSquare::Request>();
        request ->a = 3.0;
        request ->b = 4.0;
        request ->c = 5.0;
        //отправляем запрос
        client->async_send_request(
                request,
                std::bind(&PartClient::response_callback,
                          this,
                          std::placeholders::_1));
    }


    void response_callback(
        rclcpp::Client<test_custom_srv::srv::TriangleSquare>::SharedFuture
                client_f){
        //получаем статус клиента в асинхронном вызове
            std::future_status status = client_f.wait_for(1s);
            //проверяем статус клиента
            if (status ==std::future_status::ready){
                RCLCPP_INFO_STREAM (this-> get_logger(),
                                    "Response received: "<<client_f.get()->square);
            }
            else{
                RCLCPP_INFO_STREAM (this-> get_logger(),
                                    "Service in progress...");
            }
        }


    };
int main(int argc, char **argv)
{
    rclcpp :: init(argc, argv);
    rclcpp :: spin (std :: make_shared <PartClient>());
    rclcpp :: shutdown();
}

/* Лабораторная работа 2 часть 2
1. создать сервис по вычислению площади треугольника
сервису передабтся длины трех сторон треугольника
он вычисляет по формуле герона его площадь
площадь возвращается в качестве ответа

2.написать к нему узел сервиса и узел клиента
*/
