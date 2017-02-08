#include "stdafx.h"
#include "CWMPClosedCaption.h"


CString CWMPClosedCaption::GetSAMIStyle()
{
	CString result;
	InvokeHelper(0x3b7, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CWMPClosedCaption::SetSAMIStyle(LPCTSTR newValue)
{
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0x3b7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

CString CWMPClosedCaption::GetSAMILang()
{
	CString result;
	InvokeHelper(0x3b8, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CWMPClosedCaption::SetSAMILang(LPCTSTR newValue)
{
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0x3b8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

CString CWMPClosedCaption::GetSAMIFileName()
{
	CString result;
	InvokeHelper(0x3b9, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CWMPClosedCaption::SetSAMIFileName(LPCTSTR newValue)
{
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0x3b9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}

CString CWMPClosedCaption::GetCaptioningId()
{
	CString result;
	InvokeHelper(0x3ba, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CWMPClosedCaption::SetCaptioningId(LPCTSTR newValue)
{
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0x3ba, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
}
