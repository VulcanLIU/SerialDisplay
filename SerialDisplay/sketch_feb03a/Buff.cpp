/* 
* Buff.cpp
*
* Created: 2018/8/7 19:47:50
* Author: Vulcan
*/


#include "Buff.h"
#include "HardwareSerial.h"
#include "HardwareSerial_private.h"

// default constructor
Buff::Buff()
{
} //Buff


void Buff::onRecived()
{
	while(Serial.available()>0)
	{
		char c = Serial.read();
		if (c =='\n')
		{
			_buff.toUpperCase();
			Serial.println(_buff);
			//上电自检数据
			if (_buff.startsWith("INITING"))
			{
				buff = "";
			}
			if (_buff.startsWith("STR:"))
			{
				STR = _buff.substring(4);
				buff += STR;
				_buff = "";
			}
			//工作状态数据
			if(_buff.startsWith("INFORMATION"))
			{
				buff = "";
			}
			if (_buff.startsWith("WKST:")>0)
			{
				WKST = _buff.substring(5);
				_buff = "";
			}
			//位置姿势数据
			if (_buff.startsWith("XYP:"))
			{
				XYP = _buff.substring(4);
				_buff = "";
			}
			//状态数据
			if (_buff.startsWith("MSG:"))
			{
				Msg = _buff.substring(4);
				_buff = "";
			}
			if(_buff.startsWith("OK"))
			{
				buff += WKST;
				buff += XYP;
				buff += Msg;
				_buff = "";
			}
			_buff = "";
		}
		else
		{
			_buff+=c;
		}	
	}


}

String Buff::getBuff()
{
	return buff;
}
