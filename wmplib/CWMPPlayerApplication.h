#pragma once

class CWMPPlayerApplication : public COleDispatchDriver
{
public:
	CWMPPlayerApplication(){} 
	CWMPPlayerApplication(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPPlayerApplication(const CWMPPlayerApplication& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

public:
	void SwitchToPlayerApplication();
	void SwitchToControl();
	BOOL GetPlayerDocked();
	BOOL GetHasDisplay();
};
