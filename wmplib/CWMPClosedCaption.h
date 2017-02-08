#pragma once

class CWMPClosedCaption : public COleDispatchDriver
{
public:
	CWMPClosedCaption(){} 
	CWMPClosedCaption(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPClosedCaption(const CWMPClosedCaption& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

public:
	CString GetSAMIStyle();
	void SetSAMIStyle(LPCTSTR newValue);
	CString GetSAMILang();
	void SetSAMILang(LPCTSTR newValue);
	CString GetSAMIFileName();
	void SetSAMIFileName(LPCTSTR newValue);
	CString GetCaptioningId();
	void SetCaptioningId(LPCTSTR newValue);

};
