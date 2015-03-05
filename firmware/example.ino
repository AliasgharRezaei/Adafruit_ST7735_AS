
// // This #include statement was automatically added by the Spark IDE.
#include "Adafruit_ST7735_AS.h"

#define cs   A2
#define dc   D0
#define rst  0  
#define sd_cs  4

// #include "application.h"

// this variable represents the image to be drawn on screen
// PImage logo;

Adafruit_ST7735_AS tft = Adafruit_ST7735_AS(cs, dc, rst);
// this variable represents the image to be drawn on screen
// PImage logo;

unsigned long targetTime = 0;
int red = 31;
int green = 0;
int blue = 0;
int state = 0;
unsigned int colour = red << 11;

void setup(void) {
  tft.initG();
  tft.setRotation(1);
  tft.fillScreen(ST7735_BLACK);

  tft.setTextColor(ST7735_YELLOW, ST7735_BLACK); // Note: the new fonts do not draw the background colour

  targetTime = millis() + 1000; 
}

void loop() {
    tft.fillScreen(ST7735_BLACK);
    tft.setTextColor(ST7735_GREEN);

    tft.drawString(" !\"#$%&'()*+,-./0123456",0,0,2);
    tft.drawString("789:;<=>?@ABCDEFGHIJKL",0,16,2);
    tft.drawString("MNOPQRSTUVWXYZ[\\]^_`",0,32,2);
    tft.drawString("abcdefghijklmnopqrstuvw",0,48,2);
    int xpos=0;
    xpos+=tft.drawString("xyz{|}~",0,64,2);
    tft.drawChar(127,xpos,64,2);
    delay(4000);
    
    tft.fillScreen(ST7735_BLACK);
    tft.setTextColor(ST7735_GREEN);

    tft.drawString(" !\"#$%&'()*+,-.",0,0,4);
    tft.drawString("/0123456789:;",0,26,4);
    tft.drawString("<=>?@ABCDE",0,52,4);
    tft.drawString("FGHIJKLMNO",0,78,4);
    tft.drawString("PQRSTUVWX",0,104,4);
    delay(4000);
    tft.fillScreen(ST7735_BLACK);
    tft.drawString("YZ[\\]^_`abc",0,0,4);
    tft.drawString("defghijklmno",0,26,4);
    tft.drawString("pqrstuvwxyz",0,52,4);
    xpos=0;
    xpos+=tft.drawString("{|}~",0,78,4);
    tft.drawUnicode(127,xpos,78,4);
    delay(4000);
    
    tft.fillScreen(ST7735_BLACK);
    tft.setTextColor(ST7735_BLUE);

    tft.drawString("012346",0,0,6);
    tft.drawString("6789",0,40,6);
    tft.drawString("apm-:.",0,80,6);
    delay(4000);

    tft.fillScreen(ST7735_BLACK);
    tft.setTextColor(ST7735_RED);

    tft.drawString("0123",0,0,7);
    tft.drawString("4567",0,60,7);
    delay(4000);

    tft.fillScreen(ST7735_BLACK);
    tft.drawString("890:.",0,0,7);
    tft.drawString("",0,60,7);
    delay(4000);
    
    tft.setTextColor(ST7735_MAGENTA, ST7735_WHITE);
    tft.drawCentreString(">>That's all<< ",80,104,4);
    delay(4000);
}

void rainbow(int ystart, int ylen)
{
    red = 31;
    green = 0;
    blue = 0;
    state = 0;
    colour = red << 11;
    
    for (int i = 0; i<160; i++) {
      tft.drawFastVLine(i, ystart, ylen, colour);
      switch (state) {
      case 0: 
        green +=2;
        if (green == 64) {
          green=63; 
          state = 1;
        }
        break;
      case 1: 
        red--;
        if (red == 255) {
          red = 0;
          state = 2; 
        }
        break;
      case 2: 
        blue ++;
        if (blue == 32) {
          blue=31; 
          state = 3; 
        }
        break;
      case 3: 
        green -=2;
        if (green ==255) {
          green=0; 
          state = 4; 
        }
        break;
      case 4: 
        red ++;
        if (red == 32) {
          red = 31; 
          state = 5; 
        }
        break;
      case 5: 
        blue --;
        if (blue == 255) {
          blue = 0; 
          state = 0; 
        }
        break;
      }
      colour = red<<11 | green<<5 | blue;
    }
}


