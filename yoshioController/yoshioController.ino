void setup() {
  Serial.begin(115200);
  
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
  pinMode(A4, OUTPUT);
  digitalWrite(A4, HIGH);
}

double GetAxis(int data)
{
    double axis = 0;
    
    axis = (double)(data - 511) / 511;
    
    if (axis > -0.012 && axis < 0.012)
    {
        axis = 0;
    }
    else if (axis < -1)
    {
        axis = -1;
    }
    else if (axis > 1)
    {
        axis = 1;
    }
    
    return axis;
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
  Serial.write(~allsw);
  Serial.write(analog1 >> 8);
  Serial.write(analog1 & 0xff);
  Serial.write(analog0>> 8);
  Serial.write(analog0 & 0xff);
  Serial.write(analog3 >> 8);
  Serial.write(analog3 & 0xff);
  Serial.write(analog2 >> 8);
  Serial.write(analog2 & 0xff);

  delay(10);
}
