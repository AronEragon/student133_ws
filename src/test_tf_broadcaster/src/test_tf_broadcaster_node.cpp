#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2/LinearMath/Quaternion.h>

using namespace std::chrono_literals;
class TestTfBroadcaster : public rclcpp::Node
{
public:
    TestTfBroadcaster():
        Node("test_tf_broadcaster_node"),
        r_orbit(3.0),
        theta_orbit(0.0),
        rotation(-1.2)
    {
        tf_broadcaster =
            std::make_unique<tf2_ros::TransformBroadcaster>(*this);
        timer = this->create_wall_timer(30ms,
                                        std::bind(&TestTfBroadcaster::timer_callback,
                                                  this));
    }
private:
    rclcpp::TimerBase::SharedPtr timer;
    std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster;
    double r_orbit, theta_orbit, rotation;
    void timer_callback() {
        geometry_msgs::msg::TransformStamped t;
        t.header.stamp = this->get_clock()->now();
        t.header.frame_id = "world";
        t.child_frame_id = "base_link";
        geometry_msgs::msg::TransformStamped f;
        f.header.stamp = this->get_clock()->now();
        f.header.frame_id = "base_link";
        f.child_frame_id = "front_rangefinder";
        geometry_msgs::msg::TransformStamped r;
        r.header.stamp = this->get_clock()->now();
        r.header.frame_id = "base_link";
        r.child_frame_id = "rear_rangefinder";
        t.transform.translation.x = (r_orbit * sqrt(2) * cos(theta_orbit))/(pow(sin(theta_orbit),2)+1);
        t.transform.translation.y = (r_orbit * sqrt(2) * cos(theta_orbit) * sin(theta_orbit))/(pow(sin(theta_orbit),2)+1);
        t.transform.translation.z = 0;

        f.transform.translation.x = 0.5;
        f.transform.translation.y = 0;
        f.transform.translation.z = 0.2;

        r.transform.translation.x = -0.4;
        r.transform.translation.y = 0;
        r.transform.translation.z = 0.3;
        tf2::Quaternion q;
        tf2::Quaternion z;
        tf2::Quaternion v;
        if ((t.transform.translation.x <= -1.5) and (rotation >= -3.9)) {
            rotation-=0.012;
        }
        if ((t.transform.translation.x >= 1.5) and (rotation <= -1.2)) {
            rotation+=0.012;
        }
        q.setRPY(0, 0, rotation*2);
        z.setRPY(0, 0, 0);
        v.setRPY(0, 0, 1.6*2);
        t.transform.rotation.x = q.x();
        t.transform.rotation.y = q.y();
        t.transform.rotation.z = q.z();
        t.transform.rotation.w = q.w();

        f.transform.rotation.x = z.x();
        f.transform.rotation.y = z.y();
        f.transform.rotation.z = z.z();
        f.transform.rotation.w = z.w();

        r.transform.rotation.x = v.x();
        r.transform.rotation.y = v.y();
        r.transform.rotation.z = v.z();
        r.transform.rotation.w = v.w();

        tf_broadcaster->sendTransform(t);
        tf_broadcaster->sendTransform(f);
        tf_broadcaster->sendTransform(r);

        theta_orbit+=0.01;
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TestTfBroadcaster>());
    rclcpp::shutdown();
}
// #include <rclcpp/rclcpp.hpp>
// #include <geometry_msgs/msg/transform_stamped.hpp>
// #include <tf2_ros/transform_broadcaster.h>
// #include <tf2/LinearMath/Quaternion.h>
// // реализация динамической и статической трансформации
// using namespace std::chrono_literals;

// class TestTfBroadcaster : public rclcpp::Node {
// public:
//     TestTfBroadcaster():
//         Node("test_tf_broadcaster_node"),r_orbit(3.0), theta_orbit(0.0) {

//         tf_broadcaster = std::make_unique<tf2_ros::TransformBroadcaster>(*this); //инициализация tf_broadcaster



//         //Таймер определяет с какой частотой будут публиковаться сообщения
//         timer = this->create_wall_timer(500ms, std::bind(&TestTfBroadcaster::timer_callback, this));
//     }
// private:
//     rclcpp::TimerBase::SharedPtr timer;
//     std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster; //указатель на объект tf_broadcaster
//     double r_orbit, theta_orbit;

//     void timer_callback() {
//         geometry_msgs::msg::TransformStamped t;  //
//         t.header.stamp = this->get_clock()->now();
//         t.header.frame_id = "world";    //"world" неподвижная система координат
//         t.child_frame_id = "base_link"; //"base_link" виртуальный робот
//         //  задание параметров трансформации
//         // перемещение
//         t.transform.translation.x = r_orbit * cos(theta_orbit);
//         t.transform.translation.y = r_orbit * sin(theta_orbit);
//         t.transform.translation.z = 0;
//         //
//         tf2::Quaternion q;
//         // задается кватернион через функцию setRPY
//         q.setRPY(0,0,theta_orbit + M_PI_2);
//         // 0 - тангаж; 0 - крен; theta_orbit + M_PI_2 - угол рыскания; M_PI_2 = Пи/2 - поворот налево
//         // дальше идут поля кватерниона
//         t.transform.rotation.x = q.x();
//         t.transform.rotation.y = q.y();
//         t.transform.rotation.z = q.z();
//         t.transform.rotation.w = q.w();
//         //отправка через публикацию
//         tf_broadcaster->sendTransform(t);


//         theta_orbit+=0.01;//увеличение угла

//     }
// };

// int main(int argc, char **argv)
// {
//     rclcpp::init(argc,argv);
//     rclcpp::spin(std::make_shared<TestTfBroadcaster>());
//     rclcpp::shutdown();
// }
// //source install/setup.bash
// //ros2 run test_tf_broadcaster test_tf_broadcaster_node
// //ros2 run tf2_tools view_frames вводить в основном терминале
