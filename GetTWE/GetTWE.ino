#include "GetTWE.h"

void loop() {
  Get_TWEData data;
  while (1)
  {
    Serial.println(data.getad(), HEX);
  }
}
