#include <Stepper.h>
const int stepsPerRevolution = 90;

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() 
{
   myStepper.setSpeed(50);
}

void loop() 
{
  myStepper.step(stepsPerRevolution);
  //delay(500);
  //myStepper.step(-stepsPerRevolution);
  //delay(500);
}
