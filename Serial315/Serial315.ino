#define PAD_X A0
#define PAD_Y A1
#define TRIGGER_X A2
#define TRIGGER_Y A3

void setup() {
  Serial.begin(38400);

  pinMode(PAD_X, INPUT);
  pinMode(PAD_Y, INPUT);
  pinMode(TRIGGER_X, INPUT);
  pinMode(TRIGGER_Y, INPUT);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
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
  uint8_t allsw = 0;
  
  allsw |= digitalRead(A4) << 7;
  allsw |= digitalRead(A5) << 6;
  allsw |= digitalRead(2) << 5;
  allsw |= digitalRead(3) << 4;
  allsw |= digitalRead(4) << 3;
  allsw |= digitalRead(5) << 2;
  allsw |= digitalRead(11) << 1;
  allsw |= digitalRead(12) << 0;

  Serial.print("TXDT ");

  allsw = (~allsw) & 0xff;
  if (allsw <= 0xf) {
    Serial.print("0");
  }
  Serial.print(allsw, HEX);

  send_920data(analogRead(PAD_X));
  send_920data(analogRead(PAD_Y));
  send_920data(analogRead(TRIGGER_X));
//  send_920data(analogRead(TRIGGER_Y));

  Serial.print("\r\n");
 delay(5);
}
