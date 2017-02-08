#pragma once

class CWMPStringCollection : public COleDispatchDriver
{
public:
	CWMPStringCollection(){} 
	CWMPStringCollection(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPStringCollection(const CWMPStringCollection& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

public:
	long GetCount();
	CString Item(long lIndex);
};
