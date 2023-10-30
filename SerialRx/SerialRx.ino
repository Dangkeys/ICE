#include <SoftwareSerial.h>
SoftwareSerial anotherSerial(10, 11);
String inputString = "";
void setup() {
  Serial.begin(9600);
  anotherSerial.begin(9600);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available()) {
    char readIncomingChar = (char)Serial.read();
    inputString += readIncomingChar;
    if (readIncomingChar == '\r') {
      anotherSerial.print("A:");
      anotherSerial.println(inputString);
      inputString = "";
    }
  }
  while (mySerial.available()) {
    char readIncomingChar = (char)Serial.read();
    inputString += readIncomingChar;
    if (readIncomingChar == '\r') {
      Serial.print("B:");
      Serial.println(inputString);
      inputString = "";
    }
  }
}
