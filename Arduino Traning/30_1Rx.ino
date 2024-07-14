char input;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
    while (Serial.available())
    {
      input = Serial.read();
      Serial.print(input);
    }  
}
