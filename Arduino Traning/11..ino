int potentiometer = A0;
int motorPin = 3;

void setup()
{
  Serial.begin(9600);
  pinMode(potentiometer, INPUT);
}

void loop()
{
  int value = analogRead(potentiometer)/4;
  Serial.println(value);
  analogWrite(motorPin, value);
}
