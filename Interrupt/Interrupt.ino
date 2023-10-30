const int ledSize = 3;
const int switchSize = 3;
const int leds[3] = { 12, 11, 10 };
const int switches[3] = { 3, 4, 2 };
int lastState[3];


void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < ledSize; i++) {
    pinMode(leds[i], OUTPUT);
  }
  for (int i = 0; i < switchSize - 1; i++) {
    pinMode(switches[i], INPUT);
  }
  pinMode(switches[2], INPUT_PULLUP);
  attachInterrupt(0, LightsOff, FALLING);
  attachInterrupt(1, TurnOnRed, RISING);
}

void loop() {
  digitalWrite(leds[2], HIGH);
  delay(7000);
  digitalWrite(leds[2], LOW);
  digitalWrite(leds[1], HIGH);
  delay(3000);
  digitalWrite(leds[1], LOW);
  digitalWrite(leds[0], HIGH);
  delay(5000);
  digitalWrite(leds[0], LOW);
}
void LightsOff() {
  CollectLastState();
  for (int i = 0; i < ledSize; i++) {
    digitalWrite(leds[i], LOW);
  }
  for (int i = 0; i < 1000; i++)
    delayMicroseconds(5000);
  BackToPreviousState();
}
void TurnOnRed() {
  CollectLastState();
  for (int i = 0; i < ledSize; i++) {
    digitalWrite(leds[i], LOW);
  }
  digitalWrite(leds[0], HIGH);
  for (int i = 0; i < 1000; i++)
    delayMicroseconds(5000);
  BackToPreviousState();
}
void CollectLastState()
{
  for(int i = 0; i < ledSize; i++)
  {
    lastState[i] = digitalRead(leds[i]);
  }
}
void BackToPreviousState()
{
  for(int i = 0; i < ledSize; i++){
    digitalWrite(leds[i], lastState[i]);
  }
}
