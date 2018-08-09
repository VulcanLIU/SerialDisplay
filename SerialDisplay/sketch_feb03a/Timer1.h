/* 
* Timer1.h
*
* Created: 2018/6/18 18:14:58
* Author: Vulcan
*/


#ifndef __TIMER1_H__
#define __TIMER1_H__
#include "WString.h"
#include "wiring_private.h"
//#define F_CPU 16000000UL

class Timer1
{
//variables
public:
	String Mode = "";
	int prescaler = 1;
	int MAX_time = 0;
	int oc = 0;
protected:
	
private:
	
//functions
public:
	Timer1();
	Timer1(String _mode,int _time);
	void setMode(String _mode,int _time);
	void attachInterrupt(void (*userFunc)(void));
	~Timer1();
protected:
private:
	int calculate(int _prescaler,int _time);
    int select_prescaler(int _time);
}; //Timer1

#endif //__TIMER1_H__
