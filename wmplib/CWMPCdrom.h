#pragma once

class CWMPPlaylist;
class CWMPCdrom : public COleDispatchDriver
{
public:
	CWMPCdrom(){} 
	CWMPCdrom(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPCdrom(const CWMPCdrom& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

public:
	CString GetDriveSpecifier();	
	CWMPPlaylist GetPlaylist();
	void Eject();
};
