#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

#define digitlength 5 
int pwd = 1111;

char Data[digitlength]; 
byte data_count = 0, master_count = 0;
bool Pass_is_good;
char customKey;

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};


byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2); 
  lcd.backlight();
}

void loop()
{
  
  lcd.setCursor(0,0);
  lcd.print("Enter Password:");

  customKey = customKeypad.getKey();
  if (customKey){
    Data[data_count] = customKey; 
    lcd.setCursor(data_count,1); 
    lcd.print(Data[data_count]); 
    data_count++; 
    }

  if(data_count == digitlength-1){
    lcd.clear();
    int data=String(Data).toInt();
    if(data == pwd)
    {
      lcd.print("! Success !");
      delay(1000);
      }
    else{
      lcd.print("Failed");
      
      delay(1000);
      }
    lcd.clear();
    clearData();  
  }
}

void clearData(){
  while(data_count !=0){
    Data[data_count--] = 0; 
  }
  return;
}
