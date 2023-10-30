const int x[3] = { 12, 11, 10 };
const int y[3] = { 7, 6, 5 };
const int blinkTime = 2;
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 3; i++) {
    pinMode(x[i], OUTPUT);
    digitalWrite(x[i], LOW);
    pinMode(y[i], OUTPUT);
    digitalWrite(y[i], LOW);
  }
}

void loop() {

  int lastDrawO = millis();
  while (millis() - lastDrawO <= 1000) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(y[i], LOW);
    }
    digitalWrite(x[0], HIGH);
    delay(blinkTime);
    digitalWrite(x[0], LOW);
    digitalWrite(y[1], HIGH);
    digitalWrite(x[1], HIGH);
    delay(blinkTime);
    digitalWrite(x[1], LOW);
    for (int i = 0; i < 3; i++) {
      digitalWrite(y[i], LOW);
    }
    digitalWrite(x[2], HIGH);
    delay(blinkTime);
    digitalWrite(x[2], LOW);
  }
  for (int i = 0; i < 3; i++) {
    digitalWrite(x[i], LOW);
    digitalWrite(y[i], LOW);
  }
  int lastDrawX = millis();
  while (millis() - lastDrawX <= 20000) {
    for (int i = 0; i < 3; i++) {
      if (i != 1) {
        digitalWrite(y[i], LOW);
      } else {
        digitalWrite(y[i], HIGH);
      }
    }
    digitalWrite(x[0], HIGH);
    delay(blinkTime);
    digitalWrite(x[0], LOW);
    digitalWrite(x[2], HIGH);
    delay(blinkTime);
    digitalWrite(x[2], LOW);
    for (int i = 0; i < 3; i++) {
      if (i == 1) {
        digitalWrite(y[i], LOW);
      } else {
        digitalWrite(y[i], HIGH);
      }
    }
    digitalWrite(x[1], HIGH);
    delay(blinkTime);
    digitalWrite(x[1], LOW);
    for (int i = 0; i < 3; i++) {
      if (i != 1) {
        digitalWrite(y[i], LOW);
      } else {
        digitalWrite(y[i], HIGH);
      }
    }
    digitalWrite(x[2], HIGH);
    delay(blinkTime);
    digitalWrite(x[2], LOW);
  }
  for (int i = 0; i < 3; i++) {
    digitalWrite(x[i], LOW);
    digitalWrite(y[i], LOW);
  }
}
