#include <rclcpp/rclcpp.hpp>
#include <visualization_msgs/msg/marker.hpp>

using namespace std::chrono_literals;

class MarkerPublisher : public rclcpp::Node{
public:
  MarkerPublisher():
    Node("test_visualization_node"),
  angle(0)
{
    publisher =
        this->create_publisher<visualization_msgs::msg::Marker>
        ("custom_marker", 4);
    timer = this->create_wall_timer(100ms,
                                    std::bind(&MarkerPublisher::timer_callback,
                                              this));
  }


private:
  rclcpp::TimerBase::SharedPtr timer;
  rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr
          publisher;

  float angle; //Переменная для движения маркера
  float fgle;

  //  void timer_callback(){
  //   auto marker_msg = visualization_msgs::msg::Marker();

  //   /*Фрейм - название группы которой принадлежат данные
  //    * Позволяет пространственно расположить
  //    * и связвть отдельные группы данных
  //    */
  //   marker_msg.header.frame_id = "base_link";
  //   /*Временной штамп - момент времени, в который
  //    * было сформировано сообщение
  //    */
  //   marker_msg.header.stamp = this->get_clock()->now();
  //   /*Пространство имен маркера - позволяет
  //    * сгруппировать маркеры
  //    */
  //   marker_msg.ns="my_namespace";
  //   /*Идентификационный номер маркера - по нему можно
  //    * изменять или удалять маркер в последующих публикациях
  //    */
  //   marker_msg.id = 0;
  //   //Тип маркера - определяет форму маркера
  //   marker_msg.type=
  //       visualization_msgs::msg::Marker::SPHERE;

  //   /*Действие с маркером - позволяет определить
  //    * операцию добавления или удаления маркера
  //    */
  //   marker_msg.action =
  //       visualization_msgs::msg::Marker::ADD;

  //   //Местоположение центра маркера
  //   marker_msg.pose.position.x = 5.0 * cos(angle);
  //   marker_msg.pose.position.y = 5.0 * sin(angle);
  //   marker_msg.pose.position.z = 0;

  //   /*Ориентация (угловое положение маркера) - задается
  //    * квартернионом
  //    */
  //   marker_msg.pose.orientation.x = 0;
  //   marker_msg.pose.orientation.y = 0;
  //   marker_msg.pose.orientation.z = 0;
  //   marker_msg.pose.orientation.w = 1;

  //   //Размер маркера в доль осей
  //   marker_msg.scale.x = 1;
  //   marker_msg.scale.y = 1;
  //   marker_msg.scale.z = 1;

  //   //Цвет маркера
  //   marker_msg.color.a = 1.0; //Прозрачность
  //   marker_msg.color.r = 0.0;
  //   marker_msg.color.g = 1.0;
  //   marker_msg.color.b = 0.0;

  //   publisher->publish(marker_msg);
  //   angle +=0.1;



  // }

  //Сфера, в качестве солнца в модели rviz2

    void timer_callback() {
      auto marker_msg = visualization_msgs::msg::Marker();

       //Фрейм - название группы, которой принадлежат данные. Фрейм позволяет пространственно расположить и связать отдельные группы данных.
      marker_msg.header.frame_id = "range_link"; //Группировка одних типов данных от других типов.

       //Временно штамп - момент времени, в который было сформировано сообщение.
      marker_msg.header.stamp = this->get_clock()->now();

       //Пространство имён маркера - позволяет сгруппировать маркеры по какому-то признаку.
      marker_msg.ns = "my_namespace";

       //Идентификационный номер маркера - по нему можно изменять или удалять маркер в последующих публикациях.
      marker_msg.id = 0;

       //Типа маркера - определяет форму маркера. Тип примитива, по которому рисуется маркер.
      marker_msg.type =
          visualization_msgs::msg::Marker::SPHERE;

      //Действие с маркером - позволяет определить операцию добавления или удаления маркера.
      marker_msg.action =
          visualization_msgs::msg::Marker::ADD;

      //Местоположение центра маркера (по трём координатам).
      marker_msg.pose.position.x = 0;
      marker_msg.pose.position.y = 0;
      marker_msg.pose.position.z = 0;

      //Ориентация (угловое положение маркера) - задаётся кватернионом.
      marker_msg.pose.orientation.x = 0;
      marker_msg.pose.orientation.y = 0;
      marker_msg.pose.orientation.z = 0;
      marker_msg.pose.orientation.w = 0;

      //Размер маркера вдоль осей.
      marker_msg.scale.x = 15;
      marker_msg.scale.y = 15;
      marker_msg.scale.z = 15;

      //Цвет маркера.
      marker_msg.color.a = 1.0; //Прозрачность (0.0 - прозрачен)
      marker_msg.color.r = 1.0;
      marker_msg.color.g = 1.0;
      marker_msg.color.b = 0.0;

      //Публикация маркера.
      publisher->publish(marker_msg);

      angle += 0;

      float X;
      float Y;


  //Сфера, в качестве Земли в модели rviz2

      //Временно штамп - момент времени, в который было сформировано сообщение.
     marker_msg.header.stamp = this->get_clock()->now();

      //Идентификационный номер маркера - по нему можно изменять или удалять маркер в последующих публикациях.
     marker_msg.id = 1;

      //Типа маркера - определяет форму маркера. Тип примитива, по которому рисуется маркер.
     marker_msg.type =
         visualization_msgs::msg::Marker::SPHERE;

     //Действие с маркером - позволяет определить операцию добавления или удаления маркера.
     marker_msg.action =
         visualization_msgs::msg::Marker::ADD;

     //Местоположение центра маркера (по трём координатам).
     marker_msg.pose.position.x = 20.0 * sin(angle);
     marker_msg.pose.position.y = 20.0 * cos(angle);
     marker_msg.pose.position.z = 0;

     //Ориентация (угловое положение маркера) - задаётся кватернионом.
     marker_msg.pose.orientation.x = 0;
     marker_msg.pose.orientation.y = 0;
     marker_msg.pose.orientation.z = 0;
     marker_msg.pose.orientation.w = 0;

     //Размер маркера вдоль осей.
     marker_msg.scale.x = 4;
     marker_msg.scale.y = 4;
     marker_msg.scale.z = 4;

     //Цвет маркера.
     marker_msg.color.a = 1.0; //Прозрачность (0.0 - прозрачен)
     marker_msg.color.r = 0.0;
     marker_msg.color.g = 1.0;
     marker_msg.color.b = 1.0;

     //Публикация маркера.
     publisher->publish(marker_msg);

     angle += 0.01;

     X = marker_msg.pose.position.x;
     Y = marker_msg.pose.position.y;


  //Сфера, в качестве Луны в модели rviz2

     //Временно штамп - момент времени, в который было сформировано сообщение.
    marker_msg.header.stamp = this->get_clock()->now();

     //Идентификационный номер маркера - по нему можно изменять или удалять маркер в последующих публикациях.
    marker_msg.id = 2;

     //Типа маркера - определяет форму маркера. Тип примитива, по которому рисуется маркер.
    marker_msg.type =
        visualization_msgs::msg::Marker::SPHERE;

    //Действие с маркером - позволяет определить операцию добавления или удаления маркера.
    marker_msg.action =
        visualization_msgs::msg::Marker::ADD;

    //Местоположение центра маркера (по трём координатам).
    marker_msg.pose.position.x = (X+3.5 * sin(fgle));
    marker_msg.pose.position.y = (Y+3.5 * cos(fgle));
    marker_msg.pose.position.z = 0;

    //Ориентация (угловое положение маркера) - задаётся кватернионом.
    marker_msg.pose.orientation.x = 0;
    marker_msg.pose.orientation.y = 0;
    marker_msg.pose.orientation.z = 0;
    marker_msg.pose.orientation.w = 0;

    //Размер маркера вдоль осей.
    marker_msg.scale.x = 1.7;
    marker_msg.scale.y = 1.7;
    marker_msg.scale.z = 1.7;

    //Цвет маркера.
    marker_msg.color.a = 1.0; //Прозрачность (0.0 - прозрачен)
    marker_msg.color.r = 1.0;
    marker_msg.color.g = 1.0;
    marker_msg.color.b = 1.0;

    //Публикация маркера.
    publisher->publish(marker_msg);

    fgle += 0.05;
    }


};

int main(int argc, char **argv)
{

  rclcpp::init(argc, argv); //Инициализация узла в системе (объявление нового узла)
  rclcpp::spin(std::make_shared<MarkerPublisher>()); //Работа класса в некотором потоке с обработкой и испусканием некоторых данных. Make_shared - общий указатель
  rclcpp::shutdown(); //Набор инструкций для завершение работы узла

}


/*Лабораторная работа 3 часть 2
 * С помощбю маркера сферы сделать мини модель
 * движения планет
 * Луна вращается во круг земли, земля во круг солнца, солнце в центре
 *
 * sudo apt install libserial-dev
 *
 * sudo apt remove brltty
 *
 *
 */









