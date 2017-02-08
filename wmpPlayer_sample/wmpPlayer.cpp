#include "stdafx.h"
#include "wmpPlayer.h"
#include "wmpPlayerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CwmpPlayerApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

CwmpPlayerApp::CwmpPlayerApp()
{	
}

CwmpPlayerApp theApp;

BOOL CwmpPlayerApp::InitInstance()
{
	HANDLE hMutex = ::CreateMutex(NULL, FALSE, "wmpplayerModuleMiniInstance_");
	if (ERROR_ALREADY_EXISTS == ::GetLastError())
		return FALSE;	

	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	AfxEnableControlContainer();

	SetClassName();

	CwmpPlayerDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}
	return FALSE;
}

int CwmpPlayerApp::ExitInstance()
{
	return CWinAppEx::ExitInstance();
}

void CwmpPlayerApp::SetClassName()
{
	WNDCLASS wc;
	GetClassInfo(AfxGetInstanceHandle(), _T("#32770"), &wc);;

	wc.lpszClassName = _T("wmpplayerModuleMini");
	AfxRegisterClass(&wc);
}