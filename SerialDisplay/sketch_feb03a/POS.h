/* 
* POS.h
*
* Created: 2018/8/10 11:45:18
* Author: Vulcan
*/


#ifndef __POS_H__
#define __POS_H__


class POS
{
public:
	POS();
	void realXY(double x1,double y1,double p);
	double X;
	double Y;
private:
	double _x1;//������һ�� X �������߹��ľ���
	double _y1;//������һ�� y �������߹��ľ���
	double _p1;//
}; //POS

#endif //__POS_H__
