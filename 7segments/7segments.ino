const int segmentSize = 8;
const int numberSize = 10;
const int segmentPins[segmentSize] = {2,3,4,5,6,7,8,9};
const int table[numberSize][segmentSize] = {
{1, 1, 1, 1, 1, 1, 0}, // 0
{0, 1, 1, 0, 0, 0, 0}, // 1
{1, 1, 0, 1, 1, 0, 1}, // 2
{1, 1, 1, 1, 0, 0, 1}, // 3
{0, 1, 1, 0, 0, 1, 1}, // 4
{1, 0, 1, 1, 0, 1, 1}, // 5 
{1, 0, 1, 1, 1, 1, 1}, // 6
{1, 1, 1, 0, 0, 0, 0}, // 7
{1, 1, 1, 1, 1, 1, 1}, // 8
{1, 1, 1, 1, 0, 1, 1}  // 9

};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 0; i < segmentSize; i++)
  {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], HIGH);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    Serial.print("Enter your number: ");
    char readIncomingByte = Serial.read();
    int readIncomingByteAsInt = readIncomingByte - '0';
    Serial.println(readIncomingByte);
    if(readIncomingByteAsInt >= 0 && readIncomingByteAsInt <= 9)
    {
      for(int i = 0; i < segmentSize; i++)
      { 
        digitalWrite(segmentPins[i], !table[readIncomingByteAsInt][i]);
      }
      Serial.println("The input is int.");
    }else{
      Serial.println("The input is not int. Try again!");
    }
  }
}
