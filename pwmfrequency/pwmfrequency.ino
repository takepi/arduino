void setup() {
  Serial.begin(9600);
  
  pinMode(3, OUTPUT);
}

void loop() {
  Serial.print("PIN#3 TIMER : ");Serial.println(digitalPinToTimer(3));
  Serial.println("");
  Serial.println("PIN#3");
  Serial.print("TCCR2A : ");
}
