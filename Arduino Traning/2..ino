int led = 2;

void setup() 
{
  pinMode(led,OUTPUT);
}

void loop() 
{
  digitalWrite(led,HIGH);
  delay(300); 
  digitalWrite(led,LOW);
  delay(300);
}
