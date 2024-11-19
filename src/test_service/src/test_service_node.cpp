#include <rclcpp/rclcpp.hpp>
#include "test_custom_srv/srv/circle_square.hpp"

class TestService: public rclcpp::Node{
public:

  TestService():
    Node("test_service_node"){
    service = this->create_service<test_custom_srv::srv::CircleSquare>
        ("circle_square",std::bind(&TestService::service_callback,this,std::placeholders::_1,
                                                                       std::placeholders::_2 ));
  }

private:
  rclcpp::Service<test_custom_srv::srv::CircleSquare>::SharedPtr service;
  void service_callback(const std::shared_ptr<test_custom_srv::srv::CircleSquare::Request> request,
                        std::shared_ptr<test_custom_srv::srv::CircleSquare::Response> response){
    RCLCPP_INFO_STREAM(this->get_logger(),"Call service with rad "<<request->radius
                                                                 <<" part "<<request-> part);
    response->square = pow(request->radius,2) * M_PI * request->part;
    RCLCPP_INFO_STREAM(this->get_logger(), "Send responce: "<<response->square);
  }
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TestService>());
  rclcpp::shutdown();
}
