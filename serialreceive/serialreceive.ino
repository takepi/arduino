#include <stdio.h>
 
static FILE uartout;

static int uart_putchar (char c, FILE *stream) {
    if (Serial.write(c) > 0) {
      return 0;
    } else {
      return -1;
    }
}

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  pinMode(52, OUTPUT);

  fdev_setup_stream (&uartout, uart_putchar, NULL, _FDEV_SETUP_WRITE);
  stdout = &uartout;
}

void loop() {
  char buff;
  if (Serial1.available())
  {
    digitalWrite(52, HIGH);
    buff = Serial1.read();
    Serial.println(buff);
  }
  digitalWrite(52, LOW);
 }
