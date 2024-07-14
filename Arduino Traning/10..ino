#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);

void u8g_prepare(void) 
{
  u8g.setFont(u8g_font_6x10);
  u8g.setFontRefHeightExtendedText();
  u8g.setDefaultForegroundColor();
  u8g.setFontPosTop();
}

void intro(uint8_t a)
{
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(2, 19, "Welcome");
  u8g.drawStr(2, 38, "to");
  u8g.drawStr(2, 57, "PantechSolution");
}


uint8_t draw_state = 2;

void draw(void) 
{
  u8g_prepare();
  switch(draw_state >> 3) {
    case 0: intro(draw_state&7); break;
  }
}

void setup(void) 
{
#if defined(ARDUINO)
  pinMode(13, OUTPUT);           
  digitalWrite(13, HIGH);  
#endif
}

void loop(void) 
{
  
  // picture loop  
  u8g.firstPage();  
  do 
  {
    draw();
  } while( u8g.nextPage() );
  
  // increase the state
  draw_state++;
  if ( draw_state >= 9*8 )
    draw_state = 0;
}
