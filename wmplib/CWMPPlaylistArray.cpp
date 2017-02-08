#include "stdafx.h"
#include "CWMPPlaylistArray.h"
#include "CWMPPlaylist.h"

long CWMPPlaylistArray::GetCount()
{
	long result;
	InvokeHelper(0x1f5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CWMPPlaylist CWMPPlaylistArray::Item(long lIndex)
{
	LPDISPATCH result;
	static BYTE parms[] = VTS_I4 ;
	InvokeHelper(0x1f6, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, lIndex);
	return result;
}

	