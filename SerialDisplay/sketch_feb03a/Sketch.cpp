/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
#include "Adafruit_SSD1306.h"
#include "Buff.h"
#include "XK.h"
/*End of auto generated code by Atmel studio */

Adafruit_SSD1306 display(-1);
Buff buff;
XK x;
//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC,0X3C);
  display.display();
  
  delay(100);
  display.setCursor(0,0);
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {
	display.setCursor(0,5);
	
	Serial.println(buff.getBuff());
	Serial.println();
	
	display.clearDisplay();
	display.println(buff.getBuff());
	display.display();
	
	delay(100);
}

void serialEvent()
{
	buff.onRecived();
}
