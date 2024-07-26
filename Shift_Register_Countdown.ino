// byte seven_seg_digits[1] = {B00000011,};

byte seven_seg_digits[10] =
{
  B10000001,      // 0
  B11001111,      // 1
  B10010010,      // 2
  B10000110,      // 3
  B11001100,      // 4
  B10100100,      // 5
  B10100000,      // 6
  B10001111,      // 7
  B10000000,      // 8
  B10001100,      // 9

};

byte latchPin = 11;
byte clockPin =  9;
byte dataPin = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
void sevenSegWrite(byte digit)
{
  digitalWrite(latchPin,  LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, seven_seg_digits[digit]);
  digitalWrite(latchPin, HIGH);
}

void loop() {
  //   put your main code here, to run repeatedly:

  for (byte digit = 0; digit < 10 || digit >= 0; ++digit)
  {
    if (digit < 10) {
      sevenSegWrite(digit);
      delay(1000);
    }
  }
}
