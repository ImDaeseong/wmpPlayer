#pragma once

class CWMPMedia;
class CWMPPlaylist;
class CWMPStringCollection;
class CWMPMediaCollection : public COleDispatchDriver
{
public:
	CWMPMediaCollection(){} 
	CWMPMediaCollection(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPMediaCollection(const CWMPMediaCollection& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

public:
	CWMPMedia Add(LPCTSTR bstrURL);
	CWMPPlaylist GetAll();
	CWMPPlaylist GetByName(LPCTSTR bstrName);
	CWMPPlaylist GetByGenre(LPCTSTR bstrGenre);
	CWMPPlaylist GetByAuthor(LPCTSTR bstrAuthor);
	CWMPPlaylist GetByAlbum(LPCTSTR bstrAlbum);
	CWMPPlaylist GetByAttribute(LPCTSTR bstrAttribute, LPCTSTR bstrValue);
	void Remove(LPDISPATCH pItem, BOOL varfDeleteFile);
	CWMPStringCollection GetAttributeStringCollection(LPCTSTR bstrAttribute, LPCTSTR bstrMediaType);
	long GetMediaAtom(LPCTSTR bstrItemName);
	void SetDeleted(LPDISPATCH pItem, BOOL varfIsDeleted);
	BOOL IsDeleted(LPDISPATCH pItem);
};
