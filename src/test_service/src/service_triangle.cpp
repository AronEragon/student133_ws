#include <rclcpp/rclcpp.hpp>
#include "test_custom_srv/srv/triangle_square.hpp"

class PartService: public rclcpp:: Node{
public:
    PartService():
        Node("part_service_node"){
        service =
                this-> create_service<test_custom_srv::srv::TriangleSquare>
                ("triangle_square",
                 std::bind(&PartService::service_callback,
                           this,
                           std::placeholders::_1,
                           std::placeholders::_2));
    }

    private:
    rclcpp::Service<test_custom_srv::srv::TriangleSquare>::SharedPtr
    service;
    void service_callback(
            const std::shared_ptr<test_custom_srv::srv::TriangleSquare::Request>
            request,
            std::shared_ptr<test_custom_srv::srv::TriangleSquare::Response>
            response){
        RCLCPP_INFO_STREAM(this-> get_logger(),
                           "Call service whih side a "<<request->a<<
                           " side b "<<request->b<<
                           "side c " <<request->c );
        float p = (request->a + request->b + request->c)/2;
        response-> square =sqrt(p*(p-request->a)*(p-request->b)*(p-request->c));
        RCLCPP_INFO_STREAM (this-> get_logger(),
                            "Send response: "<<response-> square);


    }
};

int main(int argc, char **argv)
{
    rclcpp :: init(argc, argv);
    rclcpp :: spin (std :: make_shared <PartService>());
    rclcpp :: shutdown();
}
