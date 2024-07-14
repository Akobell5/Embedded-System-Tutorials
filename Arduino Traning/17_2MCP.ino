#include <MCP3008.h>

#define CLOCK_PIN 5
#define MISO_PIN 6
#define MOSI_PIN 7
#define CS_PIN 8

int val=0;
int val2=0;

MCP3008 adc(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN);

void setup() 
{
 Serial.begin(9600);
}


void loop() 
{
  int val = adc.readADC(0); // read Chanel 0 from MCP3008 ADC  
  int val2 = adc.readADC(1);
  Serial.print("LEVEL = ");
  Serial.print(val);
  Serial.println();
  Serial.print("Moisture = ");
  Serial.print(val2);  
}
