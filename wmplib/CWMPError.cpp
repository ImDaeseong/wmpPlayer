#include "stdafx.h"
#include "CWMPError.h"
#include "CWMPErrorItem.h"

void CWMPError::ClearErrorQueue()
{
	InvokeHelper(0x353, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

long CWMPError::GetErrorCount()
{
	long result;
	InvokeHelper(0x354, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CWMPErrorItem CWMPError::GetItem(long dwIndex)
{
	LPDISPATCH result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x355, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, dwIndex);
	return result;
}

void CWMPError::WebHelp()
{
	InvokeHelper(0x356, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}
