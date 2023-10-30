const int A = 4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float angle = 0; 
  for(angle = 0 ; angle < 2*22/7; angle += 0.1)
  {
    float sinA = A*sin(angle);
    Serial.print(sinA);
    delay(1);
  }
}
