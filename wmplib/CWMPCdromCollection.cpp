#include "stdafx.h"
#include "CWMPCdromCollection.h"
#include "CWMPCdrom.h"

long CWMPCdromCollection::GetCount()
{
	long result;
	InvokeHelper(0x12d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CWMPCdrom CWMPCdromCollection::Item(long lIndex)
{
	LPDISPATCH result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x12e, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, lIndex);
	return result;
}

CWMPCdrom CWMPCdromCollection::GetByDriveSpecifier(LPCTSTR bstrDriveSpecifier)
{
	LPDISPATCH result;
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0x12f, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrDriveSpecifier);
	return result;
}
