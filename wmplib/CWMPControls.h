#pragma once

class CWMPMedia;
class CWMPControls : public COleDispatchDriver
{
public:
	CWMPControls(){} 
	CWMPControls(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPControls(const CWMPControls& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

public:
	BOOL GetIsAvailable(LPCTSTR bstrItem);
	void Play();
	void Stop();
	void Pause();
	void FastForward();
	void FastReverse();
	double GetCurrentPosition();
	void SetCurrentPosition(double newValue);
	CString GetCurrentPositionString();
	void Next();
	void Previous();
	CWMPMedia GetCurrentItem();
	void SetCurrentItem(LPDISPATCH newValue);
	long GetCurrentMarker();
	void SettCurrentMarker(long newValue);
	void PlayItem(LPDISPATCH pIWMPMedia);
};
