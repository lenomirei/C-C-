// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFC.h"
#include "Line.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLine::CLine()
{

}

CLine::~CLine()
{

}

void CLine::Moveto(CDC *pDC,CP2 p0)
{
	_p0=p0;
}

void CLine::Moveto(CDC *pDC,double x0,double y0)
{
	_p0=CP2(x0,y0);
}

void CLine::Lineto(CDC *pDC,CP2 p1)
{
	_p1=p1;
	CP2 p,t;
	COLORREF clr=RGB(0,0,0);
	if(fabs(_p0.x-_p1.x)<1e-6)
	{
		if(_p0.y>_p1.y)
		{
			t=_p0;
			_p0=_p1;
			_p1=t;
		}
		for(p=_p0;p.y<_p1.y;p.y++)
		{
			pDC->SetPixel(Round(p.x),Round(p.y),clr);
		}
	}
	else
	{
		double k,d;
		k=(_p1.y-_p0.y)/(_p1.x-_p0.x);
		if(k>1.0)
		{
			if(_p0.y>_p1.y)
			{
				t=_p0;
				_p0=_p1;
				_p1=t;
			}
			d=1-0.5*k;
			for(p=_p0;p.y<_p1.y;p.y++)
			{
				pDC->SetPixelV(Round(p.x),Round(p.y),clr);
				if(d>=0)
				{
					p.x++;
					d+=1-k;
				}
				else
					d+=1;
			}
		}
		if(0.0<=k && k<=1.0)
		{
			if(_p0.x>_p1.x)
			{
				t=_p0;
				_p0=_p1;
				_p1=t;
			}
			d=0.5-k;
			for(p=_p0;p.x<_p1.x;p.x++)
			{
				pDC->SetPixelV(Round(p.x),Round(p.y),clr);
				if(d<0)
				{
					p.y++;
					d+=1-k;
				}
				else
					d-=k;
			}
		}
		if(k>=-1.0 && k<0.0)
		{
			if(_p0.x>_p1.x)
			{
				t=_p0;
				_p0=_p1;
				_p1=t;
			}
			d=-0.5-k;
			for(p=_p0;p.x<_p1.x;p.x++)
			{
				pDC->SetPixelV(Round(p.x),Round(p.y),clr);
				if(d<0)
				{
					p.y--;
					d-=1+k;
				}
				else
					d-=k;
			}
		}
		if(k<-1.0)
		{
			if(_p0.y<-p1.y)
			{
				t=_p0;
				_p0=_p1;
				_p1=t;
			}
			d=-1-0.5*k;
			for(p=_p0;p.y>_p1.y;p.y--)
			{
				pDC->SetPixelV(Round(p.x),Round(p.y),clr);
				if(d<0)
				{
					p.x++;
					d-=1+k;
				}
				else 
					d-=1;
			}
		}
	}
	_p0=_p1;
}


void CLine::Lineto(CDC *pDC,double x1,double y1)
{
	Lineto(pDC,CP2(x1,y1));
}
