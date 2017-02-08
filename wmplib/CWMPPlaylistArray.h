#pragma once

class CWMPPlaylist;
class CWMPPlaylistArray : public COleDispatchDriver
{
public:
	CWMPPlaylistArray(){} 
	CWMPPlaylistArray(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPPlaylistArray(const CWMPPlaylistArray& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

public:
	long GetCount();
	CWMPPlaylist Item(long lIndex);
};
