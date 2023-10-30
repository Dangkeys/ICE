const int ledSize = 3;
const int switchSize = 3;
const int leds[3] = { 12, 11, 10 };
const int switches[3] = { 3, 4, 2 };

struct Button {
  int buttonState;
  int lastButtonState;
  int lastDebounceTime;
  unsigned long debouceDelay;
  int lightsOnWhen;
  int ledState;
};
struct Button buttons[3] = {{LOW, LOW, 0, 50, HIGH, LOW}, {HIGH, HIGH, 0, 50, LOW, LOW}, {HIGH, HIGH, 0, 50, LOW, LOW}};
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < ledSize; i++) {
    pinMode(leds[i], OUTPUT);
  }
  for (int i = 0; i < switchSize - 1; i++) {
    pinMode(switches[i], INPUT);
  }
  pinMode(switches[2], INPUT_PULLUP);
}

void loop() {
  for(int i = 0; i < ledSize; i++)
  {
    int readValue = digitalRead(switches[i]);
    if(readValue != buttons[i].lastButtonState)
      buttons[i].lastDebounceTime = millis();
    if(millis() - buttons[i].lastDebounceTime > buttons[i].debouceDelay)
    {
      if(readValue != buttons[i].buttonState)
      {
        buttons[i].buttonState = readValue;
        if(buttons[i].buttonState == buttons[i].lightsOnWhen)
        {
          buttons[i].ledState = !buttons[i].ledState;
        }
      }
      
    }
    digitalWrite(leds[i], buttons[i].ledState);
    buttons[i].lastButtonState = readValue;
  }
}
