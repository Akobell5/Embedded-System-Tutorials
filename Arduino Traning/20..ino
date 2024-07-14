volatile int flowCountFreq; 
unsigned int l_hour; 
unsigned char sensorPin = 2;
unsigned long currentTime;
unsigned long loopTime;

void flow () // Interrupt function
{
   flowCountFreq++; //flowCountFreq=flowCountFreq+1;
}

void setup()
{
   pinMode(sensorPin, INPUT);
   digitalWrite(sensorPin, HIGH); // Optional Internal Pull-Up
   Serial.begin(9600);
   attachInterrupt(0, flow, RISING); 
   sei(); // Enable interrupts There are two instructions that allow software to turn off (cli) and on (sei) interrupts 
   currentTime = millis();
   loopTime = currentTime;
}
void loop ()
{
   currentTime = millis();
   // Every second, calculate and print litres/hour
   if(currentTime >= (loopTime + 1000))
   {
      loopTime = currentTime; // Updates loopTime
      // flow frequency (Hz) = 7.5Q, Q is flow rate in L/min.
      l_hour = (flowCountFreq * 60 / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour
      flowCountFreq = 0; // Reset Counter
      Serial.print(l_hour, DEC); // Print litres/hour
      Serial.println(" L/hour");
   }
}
