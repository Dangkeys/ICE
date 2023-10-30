const int segmentSize = 8;
const int numberSize = 12;
const int segmentPins[segmentSize] = { 5, 6, 7, 8, 9, 10, 11, 12 };
int randomNumber;
int currentNumber = 1;
int previousNumber = 0;
const int table[numberSize][segmentSize] = {
  { 0, 1, 1, 0, 0, 0, 0 },  // 1
  { 1, 1, 0, 1, 1, 0, 1 },  // 2
  { 1, 1, 1, 1, 0, 0, 1 },  // 3
  { 0, 1, 1, 0, 0, 1, 1 },  // 4
  { 1, 0, 1, 1, 0, 1, 1 },  // 5
  { 1, 0, 1, 1, 1, 1, 1 },  // 6
  { 1, 1, 1, 0, 0, 0, 0 },  // 7
  { 1, 1, 1, 1, 1, 1, 1 },  // 8
  { 1, 1, 1, 1, 0, 1, 1 },   // 9
  { 1, 1, 1, 1, 1, 1, 0 },  // equal
  { 0, 0, 0, 1, 1, 1, 0 },  // result lesser than currentNumber
  { 1, 0, 0, 0, 1, 1, 0 }   // result higher than currentNumber

};

class Button {
public:
  Button(int pin, int doStuffWhen)
    : pin(pin), doStuffWhen(doStuffWhen), lastButtonState(HIGH), lastDebounceTime(0), debounceDelay(50) {
    pinMode(pin, INPUT_PULLUP);
  }

  void HandleTogglePress() {
    int readValue = digitalRead(pin);
    if (readValue != lastButtonState) {
      lastDebounceTime = millis();
    }

    if (millis() - lastDebounceTime > debounceDelay) {
      if (readValue != buttonState) {
        buttonState = readValue;
        if (buttonState == doStuffWhen) {
          // Perform the action when the button is pressed
          DoStuff();
        }
      }
    }
    lastButtonState = readValue;
  }

  virtual void DoStuff() = 0;

private:
  int pin;
  int lastButtonState;
  int lastDebounceTime;
  int debounceDelay;
  int buttonState;
  int doStuffWhen;
};

class GuessButton : public Button {
public:
  GuessButton(int pin)
    : Button(pin, LOW) {}

  void DoStuff() override {
    // Action for the guess button
    previousNumber = currentNumber;
    Serial.println("Guess button pressed, performing guess action...");
    if (currentNumber == randomNumber) {
      Serial.println("Yes");
      currentNumber = 10;
    } else if (currentNumber > randomNumber) {
      Serial.println("result lesser than currentNumber");
      currentNumber = 11;
    } else {
      Serial.println("result higher than currentNumber");
      currentNumber = 12;
    }
  }
};

class AddButton : public Button {
public:
  AddButton(int pin)
    : Button(pin, LOW) {}

  void DoStuff() override {
    // Action for the answer button
    Serial.println("Answer button pressed, performing answer action...");
    if(currentNumber >= 10)
    {
      Serial.println("Ha guess again loser");
      currentNumber = previousNumber;
    }
    currentNumber++;
    if (currentNumber >= 10) {
      currentNumber = 1;
    }
  }
};

GuessButton guessButton(3);  // Initialize a guess button on pin 3
AddButton addButton(2);      // Initialize an answer button on pin 2


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(A0));
  randomNumber = random(1, 10);
  Serial.println(randomNumber);
  for (int i = 0; i < segmentSize; i++) {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], HIGH);
  }
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
}
void loop() {
  guessButton.HandleTogglePress();
  addButton.HandleTogglePress();
  for (int i = 0; i < segmentSize; i++) {
    digitalWrite(segmentPins[i], !table[currentNumber - 1][i]);
  }
  // You can add more buttons and call their HandleTogglePress() methods here if needed.
}
