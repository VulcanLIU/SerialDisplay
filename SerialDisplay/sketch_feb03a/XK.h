/* 
* XK.h
*
* Created: 2018/8/7 23:51:54
* Author: Vulcan
*/


#ifndef __XK_H__
#define __XK_H__

#include "WString.h"
class XK
{
//variables
public:

	String getName() const { return name; }
	void setName(String val);
protected:
private:
	String name = "";
//functions
public:
	XK();
	XK(String);
	~XK();
protected:
private:
	XK( const XK &c );
	XK& operator=( const XK &c );

}; //XK

#endif //__XK_H__
