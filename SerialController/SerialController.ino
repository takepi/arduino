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
  fdev_setup_stream (&uartout, uart_putchar, NULL, _FDEV_SETUP_WRITE);
  stdout = &uartout;
  
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}

void loop() {
  uint8_t i;
  uint8_t allsw = 0;
  uint16_t analog0;
  uint16_t analog1;
  uint16_t analog2;
  uint16_t analog3;

  analog0 = analogRead(A0);
  analog1 = analogRead(A1);
  analog2 = analogRead(A2);
  analog3 = analogRead(A3);

  for (i = 0; i <= 7; i++)
  {
    allsw |= digitalRead(i+2) << i;
  }

  Serial.write(':');
  Serial.write(allsw);
  Serial.write(analog0 >> 8);
  Serial.write(analog0 & 0xff);
  Serial.write(analog1>> 8);
  Serial.write(analog1 & 0xff);
  Serial.write(analog2 >> 8);
  Serial.write(analog2 & 0xff);
  Serial.write(analog3 >> 8);
  Serial.write(analog3 & 0xff);

  delay(10);
}
