#pragma once

class CWMPDVD : public COleDispatchDriver
{
public:
	CWMPDVD(){} 
	CWMPDVD(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPDVD(const CWMPDVD& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

public:
	BOOL GetIsAvailable(LPCTSTR bstrItem);
	CString GetDomain();
	void TopMenu();
	void TitleMenu();
	void Back();
	void Resume();
};
