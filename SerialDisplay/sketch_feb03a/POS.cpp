/* 
* POS.cpp
*
* Created: 2018/8/10 11:45:18
* Author: Vulcan
*/


#include "POS.h"
#include <math.h>
// default constructor
POS::POS()
{
} //POS

void POS::realXY(double x1,double y1,double p1)
{
	double dx = x1 - _x1;
	double dy = y1 - _y1;
	double dp = p1 - _p1;
	
	dp = dp*PI/180;
	
	double dx1 = dx*cos(dp)-dy*sin(dp);
	double dy1 = dx*sin(dy)+dy*cos(dp);
	
	X += dx1;
	Y += dy1;
	
	_x1 = x1;
	_y1 = y1;
	_p1 = p1;
}
