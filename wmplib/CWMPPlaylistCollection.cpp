#include "stdafx.h"
#include "CWMPPlaylistCollection.h"
#include "CWMPPlaylist.h"
#include "CWMPPlaylistArray.h"

CWMPPlaylist CWMPPlaylistCollection::NewPlaylist(LPCTSTR bstrName)
{
	LPDISPATCH result;
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0x228, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrName);
	return result;
}

CWMPPlaylistArray CWMPPlaylistCollection::GetAll()
{
	LPDISPATCH result;
	InvokeHelper(0x229, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CWMPPlaylistArray CWMPPlaylistCollection::GetByName(LPCTSTR bstrName)
{
	LPDISPATCH result;
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0x22a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrName);
	return result;
}

void CWMPPlaylistCollection::Remove(LPDISPATCH pItem)
{
	static BYTE parms[] = VTS_DISPATCH ;
	InvokeHelper(0x22c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pItem);
}

void CWMPPlaylistCollection::SetDeleted(LPDISPATCH pItem, BOOL varfIsDeleted)
{
	static BYTE parms[] = VTS_DISPATCH VTS_BOOL ;
	InvokeHelper(0x230, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pItem, varfIsDeleted);
}

BOOL CWMPPlaylistCollection::IsDeleted(LPDISPATCH pItem)
{
	BOOL result;
	static BYTE parms[] = VTS_DISPATCH ;
	InvokeHelper(0x231, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, pItem);
	return result;
}

CWMPPlaylist CWMPPlaylistCollection::ImportPlaylist(LPDISPATCH pItem)
{
	LPDISPATCH result;
	static BYTE parms[] = VTS_DISPATCH ;
	InvokeHelper(0x232, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, pItem);
	return result;
}
