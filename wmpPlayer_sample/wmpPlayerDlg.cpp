#include "stdafx.h"
#include "wmpPlayer.h"
#include "wmpPlayerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CwmpPlayerDlg::CwmpPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CwmpPlayerDlg::IDD, pParent)
{

}

void CwmpPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);	
	DDX_Control(pDX, IDC_SLIDER_VOLUMN, m_slidVolumn);
	DDX_Control(pDX, IDC_SLIDER_PLAYER, m_slidPlayer);
	DDX_Control(pDX, IDC_MEDIA_PLAY, m_WMPPlayer);
}

BEGIN_MESSAGE_MAP(CwmpPlayerDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CwmpPlayerDlg::OnBnClickedButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_PAUSE, &CwmpPlayerDlg::OnBnClickedButtonPause)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &CwmpPlayerDlg::OnBnClickedButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_FULL, &CwmpPlayerDlg::OnBnClickedButtonFull)
	ON_BN_CLICKED(IDC_BUTTON_VOLUMN1, &CwmpPlayerDlg::OnBnClickedButtonVolumn1)
	ON_BN_CLICKED(IDC_BUTTON_VOLUMN2, &CwmpPlayerDlg::OnBnClickedButtonVolumn2)
	ON_BN_CLICKED(IDC_BUTTON_MUTE, &CwmpPlayerDlg::OnBnClickedButtonMute)
	ON_BN_CLICKED(IDC_BUTTON_LEFT, &CwmpPlayerDlg::OnBnClickedButtonLeft)
	ON_BN_CLICKED(IDC_BUTTON_RIGHT, &CwmpPlayerDlg::OnBnClickedButtonRight)
END_MESSAGE_MAP()

void CwmpPlayerDlg::OnPaint()
{
	CPaintDC dc(this);
}

BOOL CwmpPlayerDlg::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN) return TRUE;
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE) return TRUE;
	
	return CDialog::PreTranslateMessage(pMsg);
}

BOOL CwmpPlayerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	//sound
	m_slidVolumn.SetRange(0, 100, false);
	m_slidVolumn.SetTicFreq(10);
	m_slidVolumn.SetLineSize(1);

	//play
	m_slidPlayer.SetRange(0, 100, false);
	m_slidPlayer.SetTicFreq(1);
	m_slidPlayer.SetLineSize(1);
	m_slidPlayer.SetPos(0);
	
	m_WMPPlayer.SetUiMode(_T("none"));
	m_WMPPlayer.GetSettings().SetAutoStart(false);
	
	return TRUE;  
}

void CwmpPlayerDlg::OnBnClickedButtonOpen()
{
	TCHAR szFilter[] =
		_T("Mp3 File(*.mp3)|*.mp3|Wma File(*.wma)|\
		*.wma|Video File(*.dat)|*.dat|Wave File(*.wav)|\
		*.wav|AVI File(*.avi)|*.avi|Movie File(*.mov)|\
		*.mov|Media File(*.mmm)|*.mmm|Mid File(*.mid;*,rmi)|\
		*.mid;*.rmi|MPEG File(*.mpeg)|*.mpeg|All File(*.*)|*.*||");
	CFileDialog fFileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
	if (IDOK == fFileDlg.DoModal())
	{	
		KillTimer(1);

		//현재 볼륨 설정
		m_slidVolumn.SetPos(m_WMPPlayer.GetSettings().GetVolume());

		m_WMPPlayer.SetURL(fFileDlg.GetPathName());
		m_WMPPlayer.GetControls().Play();
		
		SetTimer(1, 1000, NULL);
	}
}

void CwmpPlayerDlg::OnBnClickedButtonPause()
{
	if (m_WMPPlayer.IsPause())
		m_WMPPlayer.GetControls().Play();
	else
		m_WMPPlayer.GetControls().Pause();
}

void CwmpPlayerDlg::OnBnClickedButtonStop()
{
	m_WMPPlayer.GetControls().Stop();

	m_slidPlayer.SetPos(0);
}

//mp4 FullScreen
void CwmpPlayerDlg::OnBnClickedButtonFull()
{
	if (m_WMPPlayer.GetControls().GetCurrentPosition() != 0 && !m_WMPPlayer.GetFullScreen())
		m_WMPPlayer.SetFullScreen(true);
}

//Volumn up
void CwmpPlayerDlg::OnBnClickedButtonVolumn1()
{
	m_WMPPlayer.GetSettings().SetVolume(m_WMPPlayer.GetSettings().GetVolume() + 5);
	m_slidVolumn.SetPos(m_WMPPlayer.GetSettings().GetVolume());
}

//Volumn down
void CwmpPlayerDlg::OnBnClickedButtonVolumn2()
{
	m_WMPPlayer.GetSettings().SetVolume(m_WMPPlayer.GetSettings().GetVolume() - 5);
	m_slidVolumn.SetPos(m_WMPPlayer.GetSettings().GetVolume());
}

//Volumn Mute
void CwmpPlayerDlg::OnBnClickedButtonMute()
{
	if (!m_WMPPlayer.GetSettings().GetMute())
		m_WMPPlayer.GetSettings().SetMute(true);
	else
		m_WMPPlayer.GetSettings().SetMute(false);
}

//플레이 상태를 뒤로
void CwmpPlayerDlg::OnBnClickedButtonLeft()
{
	double dPos = m_WMPPlayer.GetControls().GetCurrentPosition();
	m_WMPPlayer.GetControls().SetCurrentPosition(dPos -= 5);
}

//플레이 상태를 앞으로
void CwmpPlayerDlg::OnBnClickedButtonRight()
{
	double dPos = m_WMPPlayer.GetControls().GetCurrentPosition();
	m_WMPPlayer.GetControls().SetCurrentPosition(dPos += 5);
}

void CwmpPlayerDlg::OnTimer(UINT nIDEvent)
{
	if (m_WMPPlayer.GetControls().GetCurrentPosition() == 0)
		m_slidPlayer.SetPos(0);
	else
	{
		double dDur = m_WMPPlayer.GetCurrentMedia().GetDuration();
		double dPos = m_WMPPlayer.GetControls().GetCurrentPosition();
		int nCurPosition = (100 * dPos) / dDur;
		m_slidPlayer.SetPos(nCurPosition);
	}
	
	if (m_WMPPlayer.IsStop())
	{
		KillTimer(1);
	}

	CDialog::OnTimer(nIDEvent);
}