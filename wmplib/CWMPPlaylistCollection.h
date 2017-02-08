#pragma once

class CWMPPlaylist;
class CWMPPlaylistArray;
class CWMPPlaylistCollection : public COleDispatchDriver
{
public:
	CWMPPlaylistCollection(){} 
	CWMPPlaylistCollection(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPPlaylistCollection(const CWMPPlaylistCollection& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

public:
	CWMPPlaylist NewPlaylist(LPCTSTR bstrName);
	CWMPPlaylistArray GetAll();
	CWMPPlaylistArray GetByName(LPCTSTR bstrName);
	void Remove(LPDISPATCH pItem);
	void SetDeleted(LPDISPATCH pItem, BOOL varfIsDeleted);
	BOOL IsDeleted(LPDISPATCH pItem);
	CWMPPlaylist ImportPlaylist(LPDISPATCH pItem);
};
