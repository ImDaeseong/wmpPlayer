#pragma once
#include "afxcmn.h"

class CwmpPlayerDlg : public CDialog
{
public:
	CwmpPlayerDlg(CWnd* pParent = NULL);	

	enum { IDD = IDD_WMPPLAYER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	

protected:	
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	DECLARE_MESSAGE_MAP()

public:	
	afx_msg void OnBnClickedButtonOpen();
	afx_msg void OnBnClickedButtonPause();
	afx_msg void OnBnClickedButtonStop();
	afx_msg void OnBnClickedButtonFull();
	afx_msg void OnBnClickedButtonVolumn1();
	afx_msg void OnBnClickedButtonVolumn2();
	afx_msg void OnBnClickedButtonMute();
	afx_msg void OnBnClickedButtonLeft();
	afx_msg void OnBnClickedButtonRight();

private:
	CSliderCtrl m_slidVolumn;
	CSliderCtrl m_slidPlayer;

	CWMPPlayer4	m_WMPPlayer;
};
