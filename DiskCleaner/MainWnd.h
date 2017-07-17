#pragma once

#include "DiskCleanSys.h"

class MainWnd : public WindowImplBase, public ISysStatusCallback
{
public:

protected:
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
	virtual LPCTSTR GetWindowClassName(void) const;
	virtual void InitWindow();

	DUI_DECLARE_MESSAGE_MAP()
	void OnSwitchTab(TNotifyUI &msg);

	virtual void OnConnected();
	virtual void OnDisconnected();
};