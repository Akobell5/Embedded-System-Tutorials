#include <Servo.h> 
int servoPin = 9; 

Servo Servo1; 

void setup() 
{ 
   Servo1.attach(servoPin); 
}
void loop()
{ 
   Servo1.write(0); 
   delay(1000); 

   Servo1.write(90); 
   delay(1000); 

   Servo1.write(160); 
   delay(1000); 
}
