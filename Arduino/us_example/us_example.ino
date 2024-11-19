#define ECHO_PIN 11
#define TRIG_PIN 10


void setup() {
  //Послеловательный порт
  Serial.begin(115200);
  //Режим работы линий дальномера
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  
  //Запуск излучателя
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  
  
  //Имеряем длительность импульса
  long duration = (pulseIn(ECHO_PIN, HIGH)/58.2);

  float distance = duration*0.01;
  
  Serial.print("$US,");
  Serial.print(distance);
  Serial.println("*");


  //Duration - интервал времени в микросекундах 
  //TODO на основе полученного значения вычислить расстояние в МЕТРАХ
  //Сформировать посылку с полученным расстоянием и отправить по последовательному порту

  delay(100);
}
