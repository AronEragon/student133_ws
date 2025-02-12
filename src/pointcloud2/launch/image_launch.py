from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="pointcloud2",
            executable="pointcloud2_node",
            name="pointcloud_node",
            output="screen"
        ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            arguments = [
            '--x', '0.0',
            '--y', '0.0',
            '--z', '0.0',
            '--yaw', '0.0',
            '--pitch', '0',
            '--roll', '0',
            '--frame-id', 'depth_cloud_optical',
            '--child-frame-id', '/depth_link_optical' ]
        ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            arguments = [
            '--x', '0.0',
            '--y', '0.0',
            '--z', '0.0',
            '--yaw', '0.0',
            '--pitch', '0',
            '--roll', '70.6858347',
            '--frame-id', '/depth_link_optical',
            '--child-frame-id', '/depth_link' ]
        )
    ])
