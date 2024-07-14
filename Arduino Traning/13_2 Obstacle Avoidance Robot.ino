int trigPin = 6; 
int echoPin = 7; 
int motL_A = 2;
int motL_B = 3;
int motR_A = 4;
int motR_B = 5;

long duration;

void setup() 
{
   Serial.begin(9600); 
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);

  pinMode(motL_A,OUTPUT);
  pinMode(motL_B,OUTPUT);
  pinMode(motR_A,OUTPUT);
  pinMode(motR_B,OUTPUT);

  digitalWrite(motL_A,LOW);
  digitalWrite(motL_B,LOW);
  digitalWrite(motR_A,LOW);
  digitalWrite(motR_B,LOW);   
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
   if (cm < 6)
   {
    Serial.println("Right");
    right();
    delay(2000);
    stopp();
   }
   else
   {
    Serial.println("Forward");
    forward();
   }
}

void forward()
{
  digitalWrite(motL_A,HIGH);
  digitalWrite(motL_B,LOW);
  digitalWrite(motR_A,HIGH);
  digitalWrite(motR_B,LOW);  
}
void right()
{
  digitalWrite(motL_A,HIGH);
  digitalWrite(motL_B,LOW);
  digitalWrite(motR_A,LOW);
  digitalWrite(motR_B,HIGH);  
}

void stopp()
{
  digitalWrite(motL_A,LOW);
  digitalWrite(motL_B,LOW);
  digitalWrite(motR_A,LOW);
  digitalWrite(motR_B,LOW);  
}
