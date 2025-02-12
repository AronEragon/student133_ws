from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
        package="l3_pointcloud",
        executable="l3_pointcloud_node",
        name="l3_pointcloud_node",
        output="screen"
    ),

    Node(
    package="l3_pointcloud2",
    executable="l3_pointcloud2_node",
    name="l3_pointcloud2_node",
    output="screen"
    ),
    Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        arguments = ['--x', '0.25',
        '--y', '0',
        '--z', '0.0',
        '--yaw', '0',
        '--pitch', '0',
        '--roll', '0',
        '--frame-id', 'depth_cloud_optical',
        '--child-frame-id', '/depth_link_optical'],
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
        '--frame-id', '/depth_link_optical',
        '--child-frame-id', '/depth_link'],
        output="screen"
    )

])
