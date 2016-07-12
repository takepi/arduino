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
 
  int i = 10;
  char s[] = "abcd";
  printf("i = %d, s = %s\n", i, s);
  
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
  uint8_t allbtn = 0;
  uint16_t analog0;
  uint16_t analog1;
  uint16_t analog2;
  uint16_t analog3;
  
  while (1)
  {
    analog0 = analogRead(A0);
    analog1 = analogRead(A1);
    analog2 = analogRead(A2);
    analog3 = analogRead(A3);

    for (int i = 0; i <= 7; i++)
    {
      allbtn |= (digitalRead(i+2) << i);
    }

    printf("%d%d%d%d%d\n", allbtn, analog0, analog1, analog2, analog3);
  }
}
