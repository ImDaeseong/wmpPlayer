#include "stdafx.h"
#include "CWMPControls.h"
#include "CWMPMedia.h"


BOOL CWMPControls::GetIsAvailable(LPCTSTR bstrItem)
{
	BOOL result;
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0x3e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, bstrItem);
	return result;
}

void CWMPControls::Play()
{
	InvokeHelper(0x33, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CWMPControls::Stop()
{
	InvokeHelper(0x34, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CWMPControls::Pause()
{
	InvokeHelper(0x35, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CWMPControls::FastForward()
{
	InvokeHelper(0x36, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CWMPControls::FastReverse()
{
	InvokeHelper(0x37, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

double CWMPControls::GetCurrentPosition()
{
	double result;
	InvokeHelper(0x38, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
	return result;
}

void CWMPControls::SetCurrentPosition(double newValue)
{
	static BYTE parms[] = VTS_R8 ;
	InvokeHelper(0x38, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

CString CWMPControls::GetCurrentPositionString()
{
	CString result;
	InvokeHelper(0x39, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CWMPControls::Next()
{
	InvokeHelper(0x3a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CWMPControls::Previous()
{
	InvokeHelper(0x3b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CWMPMedia CWMPControls::GetCurrentItem()
{
	LPDISPATCH result;
	InvokeHelper(0x3c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void CWMPControls::SetCurrentItem(LPDISPATCH newValue)
{
	static BYTE parms[] = VTS_DISPATCH ;
	InvokeHelper(0x3c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

long CWMPControls::GetCurrentMarker()
{
	long result;
	InvokeHelper(0x3d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CWMPControls::SettCurrentMarker(long newValue)
{
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x3d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

void CWMPControls::PlayItem(LPDISPATCH pIWMPMedia)
{
	static BYTE parms[] = VTS_DISPATCH ;
	InvokeHelper(0x3f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pIWMPMedia);
}
