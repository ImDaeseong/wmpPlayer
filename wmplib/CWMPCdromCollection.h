#pragma once

class CWMPCdrom;
class CWMPCdromCollection : public COleDispatchDriver
{
public:
	CWMPCdromCollection(){} 
	CWMPCdromCollection(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPCdromCollection(const CWMPCdromCollection& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

public:
	long GetCount();
	CWMPCdrom Item(long lIndex);
	CWMPCdrom GetByDriveSpecifier(LPCTSTR bstrDriveSpecifier);
};
