#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX
String a;

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() // run over and over
{
  if (mySerial.available() > 0) 
  {
     a = mySerial.readString();
     Serial.println(a);
     delay(500);
  }
}
