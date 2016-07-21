#include <GetController.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  GetCon con;
  int cnt = 0;
  if (con.GetError())
  {
    Serial.print(cnt);
    Serial.print(" : ");
    Serial.println("error");
    cnt++;
  }
  else
  {
  Serial.println(con.Get0X());
  }
}
