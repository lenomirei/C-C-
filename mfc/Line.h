// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__C7B6CA28_7A59_4164_BB8D_B8988F069622__INCLUDED_)
#define AFX_LINE_H__C7B6CA28_7A59_4164_BB8D_B8988F069622__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define   Round(a) int(a+0.5)
#include"p2.h"
#include <math.h>
#pragma once 
class CLine  
{
public:
	CLine();
	virtual ~CLine();
	void Moveto(CDC *,CP2);
	void Moveto(CDC *,double ,double);
	void Lineto(CDC *, CP2);
	void Lineto(CDC *,double,double);
public:
	CP2 _p0;
	CP2 _p1;
};






#endif // !defined(AFX_LINE_H__C7B6CA28_7A59_4164_BB8D_B8988F069622__INCLUDED_)
