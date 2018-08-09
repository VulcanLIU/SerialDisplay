/* 
* XK.cpp
*
* Created: 2018/8/7 23:51:53
* Author: Vulcan
*/


#include "XK.h"

void XK::setName(String val)
{
 if (name == "naozi")
	{
		name == "xukai";
	}
	else{name = val;}

}

// default constructor
XK::XK()
{
	name == "KX";
} //XK

 XK::XK(String str)
{
	this->setName(str);
}

// default destructor
XK::~XK()
{
} //~XK
