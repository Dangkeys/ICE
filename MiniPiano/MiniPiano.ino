typedef void (*FunctionType)(int);
const int toneSize = 4;
const int melodySize = 4;
const int tones[toneSize] = {261, 294, 330, 349};
const int speakerPin = 3;
class Button {
private:
  int debounceLastTime;
  int debounceDelay;
  int buttonLastState;
  int buttonState;
  int doStuffWhen;
  int pin;
public:
  Button(int pin)
    : pin(pin), doStuffWhen(LOW), debounceLastTime(0), debounceDelay(50), buttonState(HIGH), buttonLastState(HIGH) {
    pinMode(pin, INPUT);
  }
  void HandleTogglePress(FunctionType CallThisWhenPressed, int value) {
    int readValue = digitalRead(pin);
    if (readValue != buttonLastState) {
      debounceLastTime = millis();
    }
    if (millis() - debounceLastTime > debounceDelay) {
      if (readValue != buttonState) {
        buttonState = readValue;
        if (buttonState == doStuffWhen) {
          CallThisWhenPressed(value);
        }
      }
    }
    buttonLastState = readValue;
  }
};
Button melodyButton[melodySize] = {12,11,10,9};
Button resetButton = 8;
Button playButton = 7;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  for(int i = 0; i < melodySize; i++)
  {
    melodyButton[i].HandleTogglePress(SaveSong, i);
  }
}
void SaveSong(int number)
{
  tone(speakerPin, tones[number]);
  delay(500);
  noTone(speakerPin);
}
