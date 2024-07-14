char input[11];        
int count = 0;        

void setup()
{
  Serial.begin(9600);    
}

void loop()
{        
  if(Serial.available())   
  {
    count = 0;      
    while(Serial.available() && count < 11) 
    {
      input[count] = Serial.read(); 
      count++;          
      delay(5);
    }
    for(int i=0;i<11;i++)
    {
      Serial.print(input[i]);
    }
      
    Serial.println();

    if((input[0]=='$') && (input[1]=='0') && (input[2]=='0') && (input[3]=='0') && (input[4]=='5') && (input[5]=='6') && (input[6]=='5') && (input[7]=='5') && (input[8]=='0') && (input[9]=='9') && (input[10]=='2') )
    {
      Serial.println("Hello Champ");
     }
    else if((input[0]=='$') && (input[1]=='0') && (input[2]=='0') && (input[3]=='1') && (input[4]=='3') && (input[5]=='8') && (input[6]=='1') && (input[7]=='5') && (input[8]=='6') && (input[9]=='0') && (input[10]=='2') )
    {
      Serial.println("Hello Sanjay");
    }
    else if((input[0]=='$') && (input[1]=='0') && (input[2]=='0') && (input[3]=='0') && (input[4]=='8') && (input[5]=='8') && (input[6]=='6') && (input[7]=='7') && (input[8]=='7') && (input[9]=='1') && (input[10]=='9') )
    {
      Serial.println("Hello Pravin");
    }
   }    
 }
