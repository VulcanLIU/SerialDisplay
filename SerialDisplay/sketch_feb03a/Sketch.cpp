/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
#include "Adafruit_SSD1306.h"
#include "Buff.h"
#include "XK.h"
#include "Timer1.h"
/*End of auto generated code by Atmel studio */

Adafruit_SSD1306 display(-1);
Buff buff;
XK x;
Timer1 tc("CTC",500);
//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio
void UI();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  tc.attachInterrupt(UI);
  display.begin(SSD1306_SWITCHCAPVCC,0X3C);
  display.display();
  
  delay(100);
  display.setCursor(0,0);
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {
	//Serial.println(buff.getBuff());
	//Serial.println();
}

void UI()
{
	display.setCursor(0,5);
	display.clearDisplay();
	display.println(buff.getBuff());
	display.display();
}
void serialEvent()
{
	buff.onRecived();
}
