  const int LedSize = 4;
  const int ledPin[LedSize] = {8,9,10,11};


  void setup() {
    // put your setup code here, to run once:
    for(int i = 0; i < LedSize; i++)
    {
      pinMode(ledPin[i], OUTPUT);
      digitalWrite(ledPin[i], LOW);
    }
  }

  void loop() {
    for(int i = 0; i < LedSize; i++)
    {
      for(int j = 0; j < LedSize; j++)
      {
        if(j > LedSize - 1 - i)
        {
          digitalWrite(ledPin[j], HIGH);
        }else {
          digitalWrite(ledPin[j], LOW);
        }
      }
      delay(500);
    }

  }
