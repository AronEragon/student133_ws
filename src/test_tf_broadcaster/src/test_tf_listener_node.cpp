#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <tf2_ros/transform_listener.h>
#include <tf2/exceptions.h>
#include <tf2_ros/buffer.h>
#include <tf2/LinearMath/Quaternion.h>
// реализация динамической и статической трансформации
using namespace std::chrono_literals;

class TestTfListener: public rclcpp::Node {
public:
    TestTfListener():
        Node("test_tf_listener_node"),
        target_frame("sensor_link"),
        source_frame("world")

    {

        tf_buffer = std::make_unique<tf2_ros::Buffer>(this->get_clock());
        tf_listener = std::make_shared<tf2_ros::TransformListener>(*tf_buffer);


        //Таймер определяет с какой частотой будут публиковаться сообщения
        timer = this->create_wall_timer(500ms, std::bind(&TestTfListener::timer_callback, this));
    }
private:
    rclcpp::TimerBase::SharedPtr timer;
    std::shared_ptr<tf2_ros::TransformListener> tf_listener;
    std::unique_ptr<tf2_ros::Buffer> tf_buffer;
    std::string target_frame, source_frame;

    void timer_callback() {
        geometry_msgs::msg::TransformStamped t;
        try {
            t = tf_buffer->lookupTransform(source_frame,
                                           target_frame,
                                           tf2::TimePointZero);
            tf2::Quaternion q(
                t.transform.rotation.x,
                t.transform.rotation.y,
                t.transform.rotation.z,
                t.transform.rotation.w);
            tf2::Matrix3x3 m(q);
            double roll, pitch,yaw;
            m.getRPY(roll, pitch, yaw);
            RCLCPP_INFO_STREAM(this->get_logger(),
                               "transformation "<<
                               " x "<<t.transform.translation.x<<
                               " y "<<t.transform.translation.y<<
                               " z "<<t.transform.translation.z<<
                               " roll "<<roll<<
                                   " pitch: "<<
                                   " yaw "<<pitch<<
                                   " yaw "<<yaw);

        }
        catch (const tf2::TransformException &ex){
            RCLCPP_WARN_STREAM(this->get_logger(),
                               "Ther are no transform: "<<ex.what());
            return;
        }
// ros2 run test_tf_broadcaster test_tf_listener_node


    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<TestTfListener>());
    rclcpp::shutdown();
}
//source install/setup.bash
//ros2 run test_tf_broadcaster test_tf_broadcaster_node
//ros2 run tf2_tools view_frames вводить в основном терминале
