from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
#узел для публикации динамической информации
        Node(
            package="test_tf_broadcaster", # пакет
            executable="test_tf_broadcaster_node",
            name="test_tf_broadcaster_node", # название узла
            output="screen" # выводит информацию в консоль
            ),
#узел для публикации статической информации
        Node(
            package = 'tf2_ros',
            executable = 'static_transform_publisher',
            arguments = ['--x', '0.2',
            '--y', '0.1',
            '--z', '0',
            '--yaw', '0.1',# угол рысканья
            '--pitch', '0',#
            '--roll', '0',#
            '--frame-id', 'base_link',
            '--child-frame-id', 'sensor_link']
            )

    ])
#ros2 launch test_tf_broadcaster test_static_tf_launch.py
#ros2 run tf2_tools view_frames

