// MFC.h : main header file for the MFC application
//

#if !defined(AFX_MFC_H__2BD7EA90_4C52_4CED_AD60_563F0C6429CE__INCLUDED_)
#define AFX_MFC_H__2BD7EA90_4C52_4CED_AD60_563F0C6429CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCApp:
// See MFC.cpp for the implementation of this class
//

class CMFCApp : public CWinApp
{
public:
	CMFCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFCApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_H__2BD7EA90_4C52_4CED_AD60_563F0C6429CE__INCLUDED_)
