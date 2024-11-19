from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="test_parameters", # пакет
            executable="test_parameters_note",
            name="test_param_node", # название узла
            output="screen", # выводит информацию в консоль
            emulate_tty=True,# выводит информацию в консоль
            parameters=[
                {"string_param":"launch_test",
                "num1_param": 3.0, #Первая сторона треугольника
                "num2_param": 2.0, #Вторая сторона треугольника
                "num3_param": 2.0} #Третья сторона треугольника
            ]

        )
    ])

