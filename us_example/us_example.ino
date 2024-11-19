#define ECHO_PIN 11 //По длительности импульса будем определять время прохождения волны
#define TRIG_PIN 10 // Запускает излучатель




void setup() {
 //Последователный порт
 Serial.begin(115200);
 //Режим работы линии дальномера
 pinMode(TRIG_PIN, OUTPUT);
 pinMode(ECHO_PIN, INPUT);

}

void loop() {

 //Запуск излучателя - это делается импульсом длительностью 10мкс
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
 

 //измеряем длительность импульса с ECHO - это 
 // будет время прохождения УЗ волны до препядствия и обратно
 //long duration = pulseIn(ECHO_PIN,HIGH);

 //duration - интервал времени в микро секундах 
 // TODO на основе получнного значения интервала времени 
 //вычислить расстояние в метрах
 //сформировать посылку с полученным расстоянием и отправить 
 //по последовательному порту

  delay(100);
 

}
