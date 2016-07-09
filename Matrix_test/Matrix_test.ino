#include <GetTWE.h>

void setup() {
  Serial.begin(115200);
  pinMode(50, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(48, INPUT);
  pinMode(46, INPUT);
  digitalWrite(50, LOW);
  digitalWrite(52, LOW);
  Serial.println("start");
}

void loop() {
  Get_TWEData data;
  unsigned char btn;
  bool btn1, btn2, btn3, btn4;
  while (1)
  {
    digitalWrite(50, LOW);
    delay(1000);
    btn = data.getdi();
    Serial.print("50pinH : "); Serial.println(btn, BIN);
    digitalWrite(50, LOW);
    delay(1000);
    btn = data.getdi();
    Serial.print("50pinL : "); Serial.println(btn, BIN);
    Serial.println();

    //    Serial.print("btn1 : ");Serial.println(btn1);
    //    Serial.print("btn2 : ");Serial.println(btn2);
    //    Serial.print("btn3 : ");Serial.println(btn3);
    //    Serial.print("btn4 : ");Serial.println(btn4);
    //    Serial.println();
  }
}
