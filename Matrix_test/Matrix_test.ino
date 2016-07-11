#include <GetTWE.h>

void setup() {
  Serial.begin(115200);
  pinMode(50, OUTPUT);
  pinMode(52, OUTPUT);
  digitalWrite(50, HIGH);
  digitalWrite(52, HIGH);
  Serial.println("start");
}

void loop() {
  Get_TWEData data;
  char allbtn;
  int btn1, btn2, btn3, btn4;
  int cnt = 0;
  while (1)
  {
    Serial.println(cnt);
    cnt++;
    digitalWrite(50, LOW);
    allbtn = data.getdi();
    btn1 = allbtn & 0x01;
    btn2 = allbtn & 0x02;
    digitalWrite(50, HIGH);
    digitalWrite(52, LOW);
    allbtn = data.getdi();
    btn3 = allbtn & 0x01;
    btn4 = allbtn & 0x02;
    digitalWrite(52, HIGH);

    Serial.print("btn1 : ");Serial.println(btn1, BIN);
    Serial.print("btn2 : ");Serial.println(btn2, BIN);
    Serial.print("btn3 : ");Serial.println(btn3, BIN);
    Serial.print("btn4 : ");Serial.println(btn4, BIN);
    Serial.println();
  }
}
