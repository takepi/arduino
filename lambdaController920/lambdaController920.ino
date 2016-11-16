#include <stdio.h>

static FILE uartout;

static int uart_putchar (char c, FILE *stream)
{
    if (Serial.write(c) > 0)
    {
      return 0;
    }
    else
    {
      return -1;
    }
}

void setup() {
  Serial.begin(19200);

  fdev_setup_stream (&uartout, uart_putchar, NULL, _FDEV_SETUP_WRITE);
  stdout = &uartout;

  
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);  // 真空発生装置
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);

  delay(10);
  
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, OUTPUT);
  
  digitalWrite(A4, HIGH);
}

void send_920data(uint16_t data)
{
  if (data <= 0xf)
  {
    Serial.print("000");
  }
  else if (data <= 0xff)
  {
    Serial.print("00");
  }
  else if (data <= 0xfff)
  {
    Serial.print("0");
  }

  Serial.print(data, HEX);
}

void loop() {
  uint8_t i;
  uint16_t allsw = 0;
  uint16_t analog0;
  uint16_t analog1;
  uint16_t analog2;
  uint16_t analog3;

  analog0 = analogRead(A0);
  analog1 = analogRead(A1);
  analog2 = analogRead(A2);
  analog3 = analogRead(A3);

  if (analog0 < 0) analog0 = 0;
  else if (analog0 == 0x3a) analog0 = 0x39;
  else if (analog0 > 0x3ff) analog0 = 0x3ff;
  if (analog1 < 0) analog1 = 0;
  else if (analog1 == 0x3a) analog1 = 0x39;
  else if (analog1 > 0x3ff) analog1 = 0x3ff;
  if (analog2 < 0) analog2 = 0;
  else if (analog2 == 0x3a) analog2 = 0x39;
  else if (analog2 > 0x3ff) analog2 = 0x3ff;
  if (analog3 < 0) analog3 = 0;
  else if (analog3 == 0x3a) analog3 = 0x39;
  else if (analog3 > 0x3ff) analog3 = 0x3ff;

  allsw |= digitalRead(8) << 10;
  allsw |= digitalRead(6) << 9;
  allsw |= (~digitalRead(10)) << 8;
  allsw |= digitalRead(9) << 7;
  allsw |= (digitalRead(7)) << 6;
  allsw |= digitalRead(5) << 4;
  allsw |= digitalRead(4) << 5;
  allsw |= digitalRead(13) << 3;
  allsw |= digitalRead(12) << 2;
  allsw |= digitalRead(3) << 1;
  allsw |= digitalRead(2) << 0;

/*
  allsw |= digitalRead(13) << 10;
  allsw |= digitalRead(12) << 9;
  allsw |= digitalRead(10) << 8;
  allsw |= digitalRead(9) << 7;
  allsw |= digitalRead(8) << 6;
  allsw |= digitalRead(7) << 4;
  allsw |= digitalRead(6) << 5;
  allsw |= digitalRead(5) << 3;
  allsw |= digitalRead(4) << 2;
  allsw |= digitalRead(3) << 1;
  allsw |= digitalRead(2) << 0;
*/
  if (digitalRead(11))
  {
    Serial.write(':');
    Serial.write((~allsw >> 8) & 0x07);
    Serial.write(~allsw & 0xff);
    Serial.write(analog0 >> 8);
    Serial.write(analog0 & 0xff);
    Serial.write(analog1>> 8);
    Serial.write(analog1 & 0xff);
    Serial.write(analog2 >> 8);
    Serial.write(analog2 & 0xff);
    Serial.write(analog3 >> 8);
    Serial.write(analog3 & 0xff);
  
    delay(30);
  }
  else
  {
    Serial.print("TXDA ");

    send_920data((~allsw) & 0x7ff);
    send_920data(analog0);
    send_920data(analog1);
    send_920data(analog2);
    send_920data(analog3); 
  
/*
    printf("%02x", (~allsw >> 8) & 0x07);
    printf("%02x", ~allsw & 0xff);
    printf("%04x", analog0);
    printf("%04x", analog1);
    printf("%04x", analog2);
    printf("%04x", analog3);
*/
  
    Serial.print("\r\n");
  }
}
