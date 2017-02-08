#include "stdafx.h"
#include "CWMPPlayerApplication.h"

void CWMPPlayerApplication::SwitchToPlayerApplication()
{
	InvokeHelper(0x44d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CWMPPlayerApplication::SwitchToControl()
{
	InvokeHelper(0x44e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

BOOL CWMPPlayerApplication::GetPlayerDocked()
{
	BOOL result;
	InvokeHelper(0x44f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL CWMPPlayerApplication::GetHasDisplay()
{
	BOOL result;
	InvokeHelper(0x450, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}
