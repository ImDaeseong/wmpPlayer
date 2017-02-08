#include "stdafx.h"
#include "CWMPSettings.h"

BOOL CWMPSettings::GetIsAvailable(LPCTSTR bstrItem)
{
	BOOL result;
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0x71, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, bstrItem);
	return result;
}

BOOL CWMPSettings::GetAutoStart()
{
	BOOL result;
	InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWMPSettings::SetAutoStart(BOOL newValue)
{
	static BYTE parms[] = VTS_BOOL ;
	InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

CString CWMPSettings::GetBaseURL()
{
	CString result;
	InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CWMPSettings::SetBaseURL(LPCTSTR newValue)
{
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0x6c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

CString CWMPSettings::GetDefaultFrame()
{
	CString result;
	InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CWMPSettings::SetDefaultFrame(LPCTSTR newValue)
{
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0x6d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

BOOL CWMPSettings::GetInvokeURLs()
{
	BOOL result;
	InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWMPSettings::SetInvokeURLs(BOOL newValue)
{
	static BYTE parms[] = VTS_BOOL ;
	InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

BOOL CWMPSettings::GetMute()
{
	BOOL result;
	InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWMPSettings::SetMute(BOOL newValue)
{
	static BYTE parms[] = VTS_BOOL ;
	InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

long CWMPSettings::GetPlayCount()
{
	long result;
	InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CWMPSettings::SetPlayCount(long newValue)
{
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x69, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

double CWMPSettings::GetRate()
{
	double result;
	InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
	return result;
}

void CWMPSettings::SetRate(double newValue)
{
	static BYTE parms[] = VTS_R8 ;
	InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

long CWMPSettings::GetBalance()
{
	long result;
	InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CWMPSettings::SetBalance(long newValue)
{
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

long CWMPSettings::GetVolume()
{
	long result;
	InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CWMPSettings::SetVolume(long newValue)
{
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x6b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

BOOL CWMPSettings::GetMode(LPCTSTR bstrMode)
{
	BOOL result;
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0x6e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, bstrMode);
	return result;
}

void CWMPSettings::SetMode(LPCTSTR bstrMode, BOOL varfMode)
{
	static BYTE parms[] = VTS_BSTR VTS_BOOL ;
	InvokeHelper(0x6f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bstrMode, varfMode);
}

BOOL CWMPSettings::GetEnableErrorDialogs()
{
	BOOL result;
	InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CWMPSettings::SetEnableErrorDialogs(BOOL newValue)
{
	static BYTE parms[] = VTS_BOOL ;
	InvokeHelper(0x70, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

	