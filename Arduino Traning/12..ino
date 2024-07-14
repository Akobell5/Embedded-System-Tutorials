int motL_A = 2;
int motL_B = 3;
int motR_A = 4;
int motR_B = 5;

void setup() 
{
  Serial.begin(9600);
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
  while(!Serial.available());
  byte value = Serial.read();
  switch(value)
  {
    case 'F':
      forward();
      break;
    case 'B':
      backward();
      break;
    case 'L':
      left();
      delay(5000);
      stopp();
      break;
    case 'R':
      right();
      delay(5000);
      stopp();      
      break;  
    case 'S':
      stopp();      
      break;            
  }
}

void forward()
{
  digitalWrite(motL_A,HIGH);
  digitalWrite(motL_B,LOW);
  digitalWrite(motR_A,HIGH);
  digitalWrite(motR_B,LOW);  
}

void backward()
{
  digitalWrite(motL_A,LOW);
  digitalWrite(motL_B,HIGH);
  digitalWrite(motR_A,LOW);
  digitalWrite(motR_B,HIGH);  
}

void left()
{
  digitalWrite(motL_A,LOW);
  digitalWrite(motL_B,HIGH);
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
