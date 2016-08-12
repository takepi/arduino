#include <GetController.h>
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
}

void loop() {
  GetCon con;

  if (con.GetError())
  {
    Serial.println("error");
  }
  else
  {
    Serial.println(con.GetAllSW());
  }
}
