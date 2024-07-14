String a;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  if (Serial.available() > 0) 
  {
     a = Serial.readString();
     Serial.println(a);
     delay(500);
  }
}
