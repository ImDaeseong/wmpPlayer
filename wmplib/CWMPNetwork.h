#pragma once

class CWMPNetwork : public COleDispatchDriver
{
public:
	CWMPNetwork(){} 
	CWMPNetwork(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPNetwork(const CWMPNetwork& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

public:
	long GetBandWidth();
	long GetRecoveredPackets();
	CString GetSourceProtocol();
	long GetReceivedPackets();
	long GetLostPackets();
	long GetReceptionQuality();
	long GetBufferingCount();
	long GetBufferingProgress();
	long GetBufferingTime();
	void SetBufferingTime(long newValue);
	long GetFrameRate();
	long GetMaxBitRate();
	long GetBitRate();
	long GetProxySettings(LPCTSTR bstrProtocol);
	void SetProxySettings(LPCTSTR bstrProtocol, long lProxySetting);
	CString GetProxyName(LPCTSTR bstrProtocol);
	void SetProxyName(LPCTSTR bstrProtocol, LPCTSTR bstrProxyName);
	long GetProxyPort(LPCTSTR bstrProtocol);
	void SetProxyPort(LPCTSTR bstrProtocol, long lProxyPort);
	CString GetProxyExceptionList(LPCTSTR bstrProtocol);
	void SetProxyExceptionList(LPCTSTR bstrProtocol, LPCTSTR pbstrExceptionList);
	BOOL GetProxyBypassForLocal(LPCTSTR bstrProtocol);
	void SetProxyBypassForLocal(LPCTSTR bstrProtocol, BOOL fBypassForLocal);
	long GeMaxBandwidth();
	void SetMaxBandwidth(long newValue);
	long GetDownloadProgress();
	long GetEncodedFrameRate();
	long GetFramesSkipped();
};
