from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
        package="l2_image_sender",
        executable="l2_image_sender_node",
        name="l2_image_sender_node",
        output="screen"
    ),

    Node(
    package="l2_image_detector",
    executable="l2_image_detector_node",
    name="l2_image_detector_node",
    output="screen"
    ),
    Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        arguments = ['--x', '0.25',
        '--y', '0',
        '--z', '0.2',
        '--yaw', '0',
        '--pitch', '0',
        '--roll', '0',
        '--frame-id', 'base_link',
        '--child-frame-id', 'camera_link'],
        output="screen"
    ),
    Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        arguments = ['--x', '0',
        '--y', '0',
        '--z', '0',
        '--yaw', '0',
        '--pitch', '0',
        '--roll', '0',
        '--frame-id', 'camera_link',
        '--child-frame-id', 'camera_optical'],
        output="screen"
    )

])

