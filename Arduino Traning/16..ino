int trigPin = 6; 
int echoPin = 7; 
long duration;


void setup() 
{
   Serial.begin(9600); 
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
}

void loop() 
{
   //Emitted USonic
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   
   //Detect USonic
   duration = pulseIn(echoPin, HIGH);
   int cm = duration/29/2;
   Serial.print(cm);
   Serial.println();
   delay(100);
}
