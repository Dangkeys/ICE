const int toneSize = 4;
const int melodySize = 4;
const int tones[toneSize] = { 261, 294, 330, 349 };
const int speakerPin = 3;
int music[100] = { 0 };
int counter = 0;
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
  void HandleTogglePress() {
    int readValue = digitalRead(pin);
    if (readValue != buttonLastState) {
      debounceLastTime = millis();
    }
    if (millis() - debounceLastTime > debounceDelay) {
      if (readValue != buttonState) {
        buttonState = readValue;
        if (buttonState == doStuffWhen) {
          CallThisWhenPressed();
        }
      }
    }
    buttonLastState = readValue;
  }
  void CallThisWhenPressed() {
    if (pin >= 9 && pin <= 12) {
      music[counter] = tones[pin - 9];
      counter++; 
      tone(speakerPin, tones[pin - 9]);
      delay(500);
      noTone(speakerPin);

    } else if (pin == 8) {
      for(int i = 0; i < counter; i++)
      {
        music[i] = 0;
      }
      counter = 0;
    } else if (pin == 7) {
      for(int i = 0; i < counter; i++)
      {
        tone(speakerPin, music[i]);
        delay(500);
        noTone(speakerPin);
      }
    }
  }
};
Button melodyButton[melodySize] = { 12, 11, 10, 9 };
Button resetButton = 8;
Button playButton = 7;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  for (int i = 0; i < melodySize; i++) {
    melodyButton[i].HandleTogglePress();
  }
  resetButton.HandleTogglePress();
  playButton.HandleTogglePress();
}

