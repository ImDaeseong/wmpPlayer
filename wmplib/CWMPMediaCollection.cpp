#include "stdafx.h"
#include "CWMPMediaCollection.h"
#include "CWMPMedia.h"
#include "CWMPPlaylist.h"
#include "CWMPStringCollection.h"

CWMPMedia CWMPMediaCollection::Add(LPCTSTR bstrURL)
{
	LPDISPATCH result;
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0x1c4, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrURL);
	return result;
}

CWMPPlaylist CWMPMediaCollection::GetAll()
{
	LPDISPATCH result;
	InvokeHelper(0x1c5, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CWMPPlaylist CWMPMediaCollection::GetByName(LPCTSTR bstrName)
{
	LPDISPATCH result;
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0x1c6, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrName);
	return result;
}

CWMPPlaylist CWMPMediaCollection::GetByGenre(LPCTSTR bstrGenre)
{
	LPDISPATCH result;
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0x1c7, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrGenre);
	return result;
}

CWMPPlaylist CWMPMediaCollection::GetByAuthor(LPCTSTR bstrAuthor)
{
	LPDISPATCH result;
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0x1c8, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrAuthor);
	return result;
}

CWMPPlaylist CWMPMediaCollection::GetByAlbum(LPCTSTR bstrAlbum)
{
	LPDISPATCH result;
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0x1c9, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrAlbum);
	return result;
}

CWMPPlaylist CWMPMediaCollection::GetByAttribute(LPCTSTR bstrAttribute, LPCTSTR bstrValue)
{
	LPDISPATCH result;
	static BYTE parms[] = VTS_BSTR VTS_BSTR ;
	InvokeHelper(0x1ca, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrAttribute, bstrValue);
	return result;
}

void CWMPMediaCollection::Remove(LPDISPATCH pItem, BOOL varfDeleteFile)
{
	static BYTE parms[] = VTS_DISPATCH VTS_BOOL ;
	InvokeHelper(0x1cb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pItem, varfDeleteFile);
}

CWMPStringCollection CWMPMediaCollection::GetAttributeStringCollection(LPCTSTR bstrAttribute, LPCTSTR bstrMediaType)
{
	LPDISPATCH result;
	static BYTE parms[] = VTS_BSTR VTS_BSTR ;
	InvokeHelper(0x1cd, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrAttribute, bstrMediaType);
	return result;
}

long CWMPMediaCollection::GetMediaAtom(LPCTSTR bstrItemName)
{
	long result;
	static BYTE parms[] = VTS_BSTR ;
	InvokeHelper(0x1d6, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bstrItemName);
	return result;
}

void CWMPMediaCollection::SetDeleted(LPDISPATCH pItem, BOOL varfIsDeleted)
{
	static BYTE parms[] = VTS_DISPATCH VTS_BOOL ;
	InvokeHelper(0x1d7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pItem, varfIsDeleted);
}

BOOL CWMPMediaCollection::IsDeleted(LPDISPATCH pItem)
{
	BOOL result;
	static BYTE parms[] = VTS_DISPATCH ;
	InvokeHelper(0x1d8, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, pItem);
	return result;
}
