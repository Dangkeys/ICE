const int receiverPin = 2;
const int ledPin = 13;
void setup()
{
  Serial.begin(9600);
  pinMode(receiverPin, INPUT);
  pinMode(ledPin, OUTPUT);
}
void loop()

{
  digitalWrite(ledPin, digitalRead(receiverPin));
}