#include "stdafx.h"
#include "CWMPCdrom.h"
#include "CWMPPlaylist.h"

CString CWMPCdrom::GetDriveSpecifier()
{
	CString result;
	InvokeHelper(0xfb, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CWMPPlaylist CWMPCdrom::GetPlaylist()
{
	LPDISPATCH result;
	InvokeHelper(0xfc, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void CWMPCdrom::Eject()
{
	InvokeHelper(0xfd, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}