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

//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio
void UI();
Timer1 tc("CTC",500);
bool buffok = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  tc.setMode("CTC",500);
  display.begin(SSD1306_SWITCHCAPVCC,0X3C);
  display.display();
  
  delay(1000);
  display.setCursor(0,0);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  tc.attachInterrupt(UI);
}

void loop() {

	//Serial.println("dddd");
			
	//Serial.println(buff.buff);
	//Serial.println();
	buff.onRecived();
	
	//Serial.println("--------------------------------");
	//delay(20);
	if (buffok == true)
	{
		display.display();
		buffok = false;
	}	
}

void UI()
{
	Serial.println(millis());
 	display.setCursor(0,5);
 	display.clearDisplay();
 	display.println(buff.buff);
 	buffok = true;
}