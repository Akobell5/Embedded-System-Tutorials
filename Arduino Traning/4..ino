int ldrPin = A0;
int buzzer = 3;

void setup() 
{
  Serial.begin(9600);
  pinMode(ldrPin,INPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() 
{
  int ldrValue = analogRead(ldrPin);
  //Serial.print("LDR Value:");
  //Serial.println(ldrValue);
  if (ldrValue > 1000)
  {
    Serial.println("Rat Detected");
    digitalWrite(buzzer,HIGH);
  }
  else
  {
    digitalWrite(buzzer,LOW);
  }
}
