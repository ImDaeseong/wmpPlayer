#pragma once

class CWMPErrorItem : public COleDispatchDriver
{
public:
	CWMPErrorItem(){} 
	CWMPErrorItem(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPErrorItem(const CWMPErrorItem& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

public:
	long GetErrorCode();
	CString GetErrorDescription();
	VARIANT GetErrorContext();
	long GetRemedy();
	CString GetCustomUrl();
};
