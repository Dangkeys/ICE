void setup() {
  // put your setup code here, to run once:
  int bit = B00000101;
  Serial.begin(9600);
  Serial.println(bit);
  bit<<=1;
  Serial.println(bit);

}

void loop() {
  // put your main code here, to run repeatedly:

}
