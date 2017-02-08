#pragma once

#define PLAYSTATE_READY 10
#define PLAYSTATE_STOP 1
#define PLAYSTATE_PAUSE 2
#define PLAYSTATE_PLAY  3

class CWMPControls;
class CWMPSettings;
class CWMPMedia;
class CWMPMediaCollection;
class CWMPPlaylistCollection;
class CWMPNetwork;
class CWMPPlaylist;
class CWMPCdromCollection;
class CWMPClosedCaption;
class CWMPError;
class CWMPDVD;
class CWMPPlayerApplication;
class CWMPPlayer4 : public CWnd
{
protected:
	DECLARE_DYNCREATE(CWMPPlayer4)

public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x6bf52a52, 0x394a, 0x11d3, { 0xb1, 0x53, 0x0, 0xc0, 0x4f, 0x79, 0xfa, 0xa6 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}
    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE, BSTR bstrLicKey = NULL)
	{
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID, pPersist, bStorage, bstrLicKey); 
	}

public:
	BOOL IsReady();
	BOOL IsStop();
	BOOL IsPause();
	BOOL IsPlay();
	void Close();
	CString GetURL();
	void SetURL(LPCTSTR newValue);
	long GetOpenState();
	long GetPlayState();
	CWMPControls GetControls();
	CWMPSettings GetSettings();
	CWMPMedia GetCurrentMedia();
	void SetCurrentMedia(LPDISPATCH newValue);
	CWMPMediaCollection GetMediaCollection();
	CWMPPlaylistCollection GetPlaylistCollection();
	CString GetVersionInfo();
	void LaunchURL(LPCTSTR bstrURL);
	CWMPNetwork GetNetwork();
	CWMPPlaylist GetCurrentPlaylist();
	void SetCurrentPlaylist(LPDISPATCH newValue);
	CWMPCdromCollection GetCdromCollection();
	CWMPClosedCaption GetClosedCaption();
	BOOL GetIsOnline();
	CWMPError GetError();
	CString GetStatus();
	CWMPDVD GetDvd();
	CWMPPlaylist NewPlaylist(LPCTSTR bstrName, LPCTSTR bstrURL);
	CWMPMedia NewMedia(LPCTSTR bstrURL);
	BOOL GetEnabled();
	void SetEnabled(BOOL newValue);
	BOOL GetFullScreen();
	void SetFullScreen(BOOL newValue);
	BOOL GetEnableContextMenu();
	void SetEnableContextMenu(BOOL newValue);
	void SetUiMode(LPCTSTR newValue);
	CString GetUiMode();
	BOOL GetStretchToFit();
	void SetStretchToFit(BOOL newValue);
	BOOL GetWindowlessVideo();
	void SetWindowlessVideo(BOOL newValue);
	BOOL GetIsRemote();
	CWMPPlayerApplication GetPlayerApplication();
	void OpenPlayer(LPCTSTR bstrURL);
};
