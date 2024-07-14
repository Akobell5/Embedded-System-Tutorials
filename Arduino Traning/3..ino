//explanation of serial monitor 


int led = 4;
int switchh = 2;

void setup() 
{
  pinMode(led,OUTPUT);
  pinMode(switchh,INPUT);
}

void loop() 
{
  if (digitalRead(switchh) == 0)
    digitalWrite(led,HIGH);
  else
    digitalWrite(led,LOW);
}
