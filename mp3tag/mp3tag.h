#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		

class Cmp3tagApp : public CWinAppEx
{
public:
	Cmp3tagApp();

	public:
	virtual BOOL InitInstance();
	DECLARE_MESSAGE_MAP()
};

extern Cmp3tagApp theApp;