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
	while(Serial.available())
	{
		char c = Serial.read();
		if (c =='\n')
		{
			_buff.toUpperCase();
			
			//上电自检数据
			if (_buff.startsWith("INITING"))
			{
				buff = "";
			}
			if (_buff.startsWith("STR:"))
			{
				STR = _buff.substring(4);
				buff += STR;
				buff += '\n';
			}
			//工作状态数据
			if(_buff.startsWith("INFORMATION"))
			{
				buff = "";
			}
			if (_buff.startsWith("WKST:")>0)
			{
				WKST = _buff.substring(5);
			}
			//位置姿势数据
			if (_buff.startsWith("XYP:"))
			{
				XYP = _buff.substring(4);
			}
			//状态数据
			if (_buff.startsWith("MSG:"))
			{
				Msg = _buff.substring(4);
			}
			if(_buff.startsWith("OK"))
			{
				buff = WKST+'\n'+XYP+'\n'+Msg+'\n';
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
