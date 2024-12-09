#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2/LinearMath/Quaternion.h>
//динамическая трансформация
using namespace std::chrono_literals;
class TestTfBroadcaster : public rclcpp::Node
{
public:
    TestTfBroadcaster():
        Node("test_tf_broadcaster_node"),
        r_orbit(3.0),
        theta_orbit(0.0), // угол орбит
        rotation(1.48) // начальное значение угла вращения
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



        // для "base_link" движение по 8

        t.transform.translation.x = (r_orbit * cos(theta_orbit));
        //  t.transform.translation.x = (r_orbit * sqrt(2) * cos(theta_orbit))/(pow(sin(theta_orbit),2)+1);

        t.transform.translation.y = (r_orbit * cos(theta_orbit) * sin(theta_orbit));
        // t.transform.translation.y = (r_orbit * sqrt(2) * cos(theta_orbit) * sin(theta_orbit))/(pow(sin(theta_orbit),2)+1);

        t.transform.translation.z = 0;

        tf2::Quaternion q;
        // поворот base_link
        if ((t.transform.translation.x <= -1.48) and (rotation >= -3.927)) {
            rotation-=0.0115;
        }
        if ((t.transform.translation.x >= 1.48) and (rotation <= -1.2)) {
            rotation+=0.0115;
        }
        //double yaw = atan2(r_orbit*2*cos(2*theta_orbit), r_orbit*cos(theta_orbit));
        q.setRPY(0, 0, rotation*2); //

        t.transform.rotation.x = q.x();
        t.transform.rotation.y = q.y();
        t.transform.rotation.z = q.z();
        t.transform.rotation.w = q.w();

        tf_broadcaster->sendTransform(t);



        theta_orbit+=0.01;
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TestTfBroadcaster>());
    rclcpp::shutdown();
}





// // #include <rclcpp/rclcpp.hpp>
// // #include <geometry_msgs/msg/transform_stamped.hpp>
// // #include <tf2_ros/transform_broadcaster.h>
// // #include <tf2/LinearMath/Quaternion.h>
// // // реализация динамической и статической трансформации
// // using namespace std::chrono_literals;

// // class TestTfBroadcaster : public rclcpp::Node {
// // public:
// //     TestTfBroadcaster():
// //         Node("test_tf_broadcaster_node"),r_orbit(3.0), theta_orbit(0.0) {

// //         tf_broadcaster = std::make_unique<tf2_ros::TransformBroadcaster>(*this); //инициализация tf_broadcaster



// //         //Таймер определяет с какой частотой будут публиковаться сообщения
// //         timer = this->create_wall_timer(500ms, std::bind(&TestTfBroadcaster::timer_callback, this));
// //     }
// // private:
// //     rclcpp::TimerBase::SharedPtr timer;
// //     std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster; //указатель на объект tf_broadcaster
// //     double r_orbit, theta_orbit;

// //     void timer_callback() {
// //         geometry_msgs::msg::TransformStamped t;  //
// //         t.header.stamp = this->get_clock()->now();
// //         t.header.frame_id = "world";    //"world" неподвижная система координат
// //         t.child_frame_id = "base_link"; //"base_link" виртуальный робот
// //         //  задание параметров трансформации
// //         // перемещение
// //         t.transform.translation.x = r_orbit * cos(theta_orbit);
// //         t.transform.translation.y = r_orbit * sin(theta_orbit);
// //         t.transform.translation.z = 0;
// //         //
// //         tf2::Quaternion q;
// //         // задается кватернион через функцию setRPY
// //         q.setRPY(0,0,theta_orbit + M_PI_2);
// //         // 0 - тангаж; 0 - крен; theta_orbit + M_PI_2 - угол рыскания; M_PI_2 = Пи/2 - поворот налево
// //         // дальше идут поля кватерниона
// //         t.transform.rotation.x = q.x();
// //         t.transform.rotation.y = q.y();
// //         t.transform.rotation.z = q.z();
// //         t.transform.rotation.w = q.w();
// //         //отправка через публикацию
// //         tf_broadcaster->sendTransform(t);


// //         theta_orbit+=0.01;//увеличение угла

// //     }
// // };

// // int main(int argc, char **argv)
// // {
// //     rclcpp::init(argc,argv);
// //     rclcpp::spin(std::make_shared<TestTfBroadcaster>());
// //     rclcpp::shutdown();
// // }
// // // //source install/setup.bash
// // // //ros2 run test_tf_broadcaster test_tf_broadcaster_node
// // // //ros2 run tf2_tools view_frames вводить в основном терминале
