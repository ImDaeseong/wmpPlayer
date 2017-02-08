#pragma once

class CWMPMedia : public COleDispatchDriver
{
public:
	CWMPMedia(){} 
	CWMPMedia(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPMedia(const CWMPMedia& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

public:
	BOOL GetIsIdentical(LPDISPATCH pIWMPMedia);
	CString GetSourceURL();
	CString GetName();
	void SetName(LPCTSTR newValue);
	long GetImageSourceWidth();
	long GetImageSourceHeight();
	long GetMarkerCount();
	double GetMarkerTime(long MarkerNum);
	CString GetMarkerName(long MarkerNum);
	double GetDuration();
	CString GetDurationString();
	long GetAttributeCount();
	CString GetAttributeName(long lIndex);
	CString GetItemInfo(LPCTSTR bstrItemName);
	void SetItemInfo(LPCTSTR bstrItemName, LPCTSTR bstrVal);
	CString GetItemInfoByAtom(long lAtom);
	BOOL IsMemberOf(LPDISPATCH pPlaylist);
	BOOL IsReadOnlyItem(LPCTSTR bstrItemName);
};
