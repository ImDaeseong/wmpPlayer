#pragma once

class CWMPErrorItem;
class CWMPError : public COleDispatchDriver
{
public:
	CWMPError(){} 
	CWMPError(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPError(const CWMPError& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}
	
public:
	void ClearErrorQueue();
	long GetErrorCount();
	CWMPErrorItem GetItem(long dwIndex);
	void WebHelp();
};
