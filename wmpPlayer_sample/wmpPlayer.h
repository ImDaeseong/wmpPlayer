#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"	

class CwmpPlayerApp : public CWinAppEx
{
public:
	CwmpPlayerApp();

	public:
	virtual BOOL InitInstance();

protected:
	void SetClassName();

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CwmpPlayerApp theApp;