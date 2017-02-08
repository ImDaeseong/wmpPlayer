#pragma once

class CWMPMedia;
class CWMPPlaylist : public COleDispatchDriver
{
public:
	CWMPPlaylist(){} 
	CWMPPlaylist(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPPlaylist(const CWMPPlaylist& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

public:
	long GetCount();
	CString GetName();
	void SetName(LPCTSTR newValue);
	long GetAttributeCount();
	CString GetAttributeName(long lIndex);
	CWMPMedia GetItem(long lIndex);
	CString GetItemInfo(LPCTSTR bstrName);
	void SetItemInfo(LPCTSTR bstrName, LPCTSTR bstrValue);
	BOOL GetIsIdentical(LPDISPATCH pIWMPPlaylist);
	void Clear();
	void InsertItem(long lIndex, LPDISPATCH pIWMPMedia);
	void AppendItem(LPDISPATCH pIWMPMedia);
	void RemoveItem(LPDISPATCH pIWMPMedia);
	void MoveItem(long lIndexOld, long lIndexNew);
};
