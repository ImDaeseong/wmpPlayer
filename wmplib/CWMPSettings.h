#pragma once

class CWMPSettings : public COleDispatchDriver
{
public:
	CWMPSettings(){} 
	CWMPSettings(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPSettings(const CWMPSettings& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

public:
	BOOL GetIsAvailable(LPCTSTR bstrItem);
	BOOL GetAutoStart();
	void SetAutoStart(BOOL newValue);
	CString GetBaseURL();
	void SetBaseURL(LPCTSTR newValue);
	CString GetDefaultFrame();
	void SetDefaultFrame(LPCTSTR newValue);
	BOOL GetInvokeURLs();
	void SetInvokeURLs(BOOL newValue);
	BOOL GetMute();
	void SetMute(BOOL newValue);
	long GetPlayCount();
	void SetPlayCount(long newValue);
	double GetRate();
	void SetRate(double newValue);
	long GetBalance();
	void SetBalance(long newValue);
	long GetVolume();
	void SetVolume(long newValue);
	BOOL GetMode(LPCTSTR bstrMode);
	void SetMode(LPCTSTR bstrMode, BOOL varfMode);
	BOOL GetEnableErrorDialogs();
	void SetEnableErrorDialogs(BOOL newValue);
};
