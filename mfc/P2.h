// P2.h: interface for the CP2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_P2_H__CF963B1B_11DD_4755_B36B_CC3A724E0C1C__INCLUDED_)
#define AFX_P2_H__CF963B1B_11DD_4755_B36B_CC3A724E0C1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#pragma once 
class CP2  
{
public:
	CP2();
	virtual ~CP2();
	CP2(double x,double y)
	{
		this->x=x;
		this->y=y;
	};
public:
	double x;
	double y;
};

#endif // !defined(AFX_P2_H__CF963B1B_11DD_4755_B36B_CC3A724E0C1C__INCLUDED_)
