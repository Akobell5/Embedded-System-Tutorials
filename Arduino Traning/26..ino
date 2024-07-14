const int voltPin = A0;
const int currPin = A1;

void setup() 
{
  Serial.begin(9600);
  pinMode(voltPin,INPUT);
  pinMode(currPin,INPUT);
}

void loop() 
{
  float voltRaw = analogRead(voltPin);
  float currRaw = analogRead(currPin);
  Serial.print("VoltageRaw: ");
  Serial.println(voltRaw);
  Serial.print("CurrentRaw: ");
  Serial.println(currRaw);

  float voltage = voltRaw/2;
  float current = currRaw/200;
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print("  Current: ");
  Serial.println(current);  

  float power = voltage*current;
  Serial.print("Power: ");
  Serial.println(power);
  delay(1000);
}
