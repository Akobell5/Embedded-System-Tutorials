int led = 13;
int switchh = 2;

void setup() 
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(switchh,INPUT);
}

void loop() 
{
  if (digitalRead(switchh) == 0)
  {
    Serial.println("Motion Detected");
    digitalWrite(led,HIGH);
  }
  else
    digitalWrite(led,LOW);
}
