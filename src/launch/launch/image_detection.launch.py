from launch import LaunchDescription # Импорт класса для описания запуска
from launch_ros.actions import Node # Импорт класса Node для создания узлов ROS2

def generate_launch_description():
    return LaunchDescription([
        # Узел для публикации изображений
        Node(
            package='image_pub', # Пакет, в котором находится исполняемый файл
            executable='image_pub_node', # Исполняемый файл для запуска
            name='image_publisher', # Название узла
            output='screen' # Вывод информации узла на экран
        ),

        # Узел для получения изображений и распознавания окружностей
        Node(
            package='circle_detector', # Пакет с программой для распознавания окружностей
            executable='circle_detector_node', # Исполняемый файл для распознавания окружностей
            name='circle_detector', # Название узла
            output='screen' # Вывод информации узла на экран
        ),

        # Статическая трансформация между /base_link и /camera_link
        Node(
            package='tf2_ros', # Пакет для работы с трансформациями
            executable='static_transform_publisher', # Исполняемый файл для публикации статической трансформации
            name='base_to_camera_link_tf', # Название узла трансформации
            arguments=['0.25', '0.0', '0.2', '0', '0', '0', '/base_link', '/camera_link'], # Аргументы: координаты и ориентация
            output='screen' # Вывод информации узла на экран
        ),

        # Статическая трансформация между /camera_link и /camera_optical
        Node(
            package='tf2_ros', # Пакет для работы с трансформациями
            executable='static_transform_publisher', # Исполняемый файл для публикации статической трансформации
            name='camera_link_to_optical_tf', # Название узла трансформации
            arguments=['0', '0', '0', '-1.5708', '0', '-1.5708', '/camera_link', '/camera_optical'], # Аргументы: координаты и ориентация
            output='screen' # Вывод информации узла на экран
        )
    ])
