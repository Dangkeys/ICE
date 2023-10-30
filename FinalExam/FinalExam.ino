//ใช้bitเถอะครับน้องๆ มันง่ายกว่าเยอะ อย่าหาใช้array

const int ledSize = 8;
const int ledPin[ledSize] = { 4, 5, 6, 7, 8, 9, 10, 11 };
const int leftButton = 2;
const int rightButton = 3;
int number = B00000000;
int currentbit = B00000001;
int pressCounter = 0;
const int pressAmount = 4;
int state = B00000000;
int debounceDelay = 50;
int debounceLastTime = 0;
int buttonLastState = LOW;
int buttonState = LOW;
int loopAmount = 0;
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < ledSize; i++) {
    pinMode(ledPin[i], OUTPUT);
  }
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
}
void loop() {
  //handle leftButton
  if (digitalRead(leftButton)) {
    state = 1;
  } else {
    state = 0;
  }
  //handle rightButton
  int readIncomingBit = digitalRead(rightButton);
  if (readIncomingBit != buttonLastState) {
    debounceLastTime = millis();
  }
  if (millis() - debounceLastTime > debounceDelay) {
    if (readIncomingBit != buttonState) {
      buttonState = readIncomingBit;
      if (buttonState == HIGH) {
        if (pressCounter < pressAmount) {
          Serial.print(pressCounter + 1);
          Serial.print(": ");
          Serial.println(state);
          number |= (state << pressCounter);
          pressCounter++;
        }
        if (pressCounter >= pressAmount) {
          Serial.print("Your number is ");
          Serial.println(number, DEC);
          for (int i = 0; i < ledSize; i++) {
            int setBit = bitRead(number, i);
            digitalWrite(ledPin[i], setBit);
          }
          delay(1000);
          int originalNumber = number;
          while (loopAmount != 3) {
            while (number < 255) {
              if (number<<1 >= 255) {
                break;
              }
              number <<= 1;
              Serial.println(number);
              for (int i = 0; i < ledSize; i++) {
                int setBit = bitRead(number, i);
                digitalWrite(ledPin[i], setBit);
              }
              delay(500);
            }
            while(number != originalNumber)
            {
              number >>= 1;
              Serial.println(number);
              for (int i = 0; i < ledSize; i++) {
                int setBit = bitRead(number, i);
                digitalWrite(ledPin[i], setBit);
              }
              delay(500);
            }
            loopAmount++;
          }
          ResetEverything();
        }
      }
    }
  }
  buttonLastState = readIncomingBit;
}
void ResetEverything() {
  number = 0;
  currentbit = 0;
  pressCounter = 0;
  loopAmount = 0;
  for(int i = 0; i < ledSize; i++)
  {
    digitalWrite(ledPin[i], LOW);
  }
}