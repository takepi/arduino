#include <GetTWE.h>

void setup() {
  Serial.begin(115200);
  pinMode(50, OUTPUT);
  pinMode(52, OUTPUT);
  digitalWrite(50, HIGH);
  digitalWrite(50, HIGH);
}

void loop() {
  Get_TWEData data;
  while (1)
  {
    Serial.println(data.getdi(), BIN);
  }

}
