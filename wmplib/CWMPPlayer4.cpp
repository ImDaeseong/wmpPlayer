#include "stdafx.h"
#include "CWMPPlayer4.h"
#include "CWMPControls.h"
#include "CWMPSettings.h"
#include "CWMPMedia.h"
#include "CWMPMediaCollection.h"
#include "CWMPPlaylistCollection.h"
#include "CWMPNetwork.h"
#include "CWMPPlaylist.h"
#include "CWMPCdromCollection.h"
#include "CWMPClosedCaption.h"
#include "CWMPError.h"
#include "CWMPDVD.h"
#include "CWMPPlayerApplication.h"

IMPLEMENT_DYNCREATE(CWMPPlayer4, CWnd)


BOOL CWMPPlayer4::IsPlay()
{	
	return GetPlayState() == PLAYSTATE_PLAY;
}

BOOL CWMPPlayer4::IsPause()
{
	return GetPlayState() == PLAYSTATE_PAUSE;
}

BOOL CWMPPlayer4::IsReady()
{
	return GetPlayState() == PLAYSTATE_READY;
}
BOOL CWMPPlayer4::IsStop()
{
	return GetPlayState() == PLAYSTATE_STOP;
}

void CWMPPlayer4::Close()
{
	InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString CWMPPlayer4::GetURL()
{
	CString result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CWMPPlayer4::SetURL(LPCTSTR newValue)
{
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

long CWMPPlayer4::GetOpenState()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long CWMPPlayer4::GetPlayState()
{
	long result;
	InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CWMPControls CWMPPlayer4::GetControls()
{
	LPDISPATCH result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CWMPSettings CWMPPlayer4::GetSettings()
{
	LPDISPATCH result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CWMPMedia CWMPPlayer4::GetCurrentMedia()
{
	LPDISPATCH result;
	InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void CWMPPlayer4::SetCurrentMedia(LPDISPATCH newValue)
{
	static BYTE parms[] = VTS_DISPATCH ;
	InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

CWMPMediaCollection CWMPPlayer4::GetMediaCollection()
{
	LPDISPATCH result;
	InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CWMPPlaylistCollection CWMPPlayer4::GetPlaylistCollection()
{
	LPDISPATCH result;
	InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString CWMPPlayer4::GetVersionInfo()
{
	CString result;
	InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CWMPPlayer4::LaunchURL(LPCTSTR bstrURL)
{
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bstrURL);
}

CWMPNetwork CWMPPlayer4::GetNetwork()
{
	LPDISPATCH result;
	InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CWMPPlaylist CWMPPlayer4::GetCurrentPlaylist()
{
	LPDISPATCH result;
	InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void CWMPPlayer4::SetCurrentPlaylist(LPDISPATCH newValue)
{
	static BYTE parms[] = VTS_DISPATCH ;
	InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

CWMPCdromCollection CWMPPlayer4::GetCdromCollection()
{
	LPDISPATCH result;
	InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CWMPClosedCaption CWMPPlayer4::GetClosedCaption()
{
	LPDISPATCH result;
	InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL CWMPPlayer4::GetIsOnline()
{
	BOOL result;
	InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

CWMPError CWMPPlayer4::GetError()
{
	LPDISPATCH result;
	InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString CWMPPlayer4::GetStatus()
{
	CString result;
	InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CWMPDVD CWMPPlayer4::GetDvd()
{
	LPDISPATCH result;
	InvokeHelper(0x28, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CWMPPlaylist CWMPPlayer4::NewPlaylist(LPCTSTR bstrName, LPCTSTR bstrURL)
{
	LPDISPATCH result;
	static BYTE parms[] = VTS_BSTR VTS_BSTR ;
	InvokeHelper(0x29, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrName, bstrURL);
	return result;
}

CWMPMedia CWMPPlayer4::NewMedia(LPCTSTR bstrURL)
{
	LPDISPATCH result;
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0x2a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrURL);
	return result;
}

BOOL CWMPPlayer4::GetEnabled()
{
	BOOL result;
	InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWMPPlayer4::SetEnabled(BOOL newValue)
{
	static BYTE parms[] = VTS_BOOL ;
	InvokeHelper(0x13, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

BOOL CWMPPlayer4::GetFullScreen()
{
	BOOL result;
	InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWMPPlayer4::SetFullScreen(BOOL newValue)
{
	static BYTE parms[] = VTS_BOOL ;
	InvokeHelper(0x15, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

BOOL CWMPPlayer4::GetEnableContextMenu()
{
	BOOL result;
	InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWMPPlayer4::SetEnableContextMenu(BOOL newValue)
{
	static BYTE parms[] = VTS_BOOL ;
	InvokeHelper(0x16, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

void CWMPPlayer4::SetUiMode(LPCTSTR newValue)
{
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0x17, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

CString CWMPPlayer4::GetUiMode()
{
	CString result;
	InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

BOOL CWMPPlayer4::GetStretchToFit()
{
	BOOL result;
	InvokeHelper(0x18, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWMPPlayer4::SetStretchToFit(BOOL newValue)
{
	static BYTE parms[] = VTS_BOOL ;
	InvokeHelper(0x18, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

BOOL CWMPPlayer4::GetWindowlessVideo()
{
	BOOL result;
	InvokeHelper(0x19, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWMPPlayer4::SetWindowlessVideo(BOOL newValue)
{
	static BYTE parms[] = VTS_BOOL ;
	InvokeHelper(0x19, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

BOOL CWMPPlayer4::GetIsRemote()
{
	BOOL result;
	InvokeHelper(0x1a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

CWMPPlayerApplication CWMPPlayer4::GetPlayerApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void CWMPPlayer4::OpenPlayer(LPCTSTR bstrURL)
{
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0x1c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bstrURL);
}
