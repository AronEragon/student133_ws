void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);

}

void loop() {
  int x = analogRead(A0);
  Serial.print("$POT,");
  Serial.print(x);
  Serial.println("*");
  delay(100); 
  
}
