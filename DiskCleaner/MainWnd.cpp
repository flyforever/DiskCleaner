#include "StdAfx.h"
#include "MainWnd.h"


DUI_BEGIN_MESSAGE_MAP(MainWnd, WindowImplBase)
DUI_ON_SELECTCHANGED_CTRNAME(_T("frontoption"), OnSwitchTab)
DUI_ON_SELECTCHANGED_CTRNAME(_T("portoption"), OnSwitchTab)
DUI_ON_SELECTCHANGED_CTRNAME(_T("logoption"), OnSwitchTab)
DUI_END_MESSAGE_MAP()

CDuiString MainWnd::GetSkinFolder()
{
	return CPaintManagerUI::GetInstancePath() + _T("skin\\");
}

CDuiString MainWnd::GetSkinFile()
{
	return _T("MainWnd.xml");
}

LPCTSTR MainWnd::GetWindowClassName(void) const
{
	return _T("MainWnd");
}

void MainWnd::OnSwitchTab(TNotifyUI &msg)
{
	CDuiString name = msg.pSender->GetName();
	CTabLayoutUI* pControl = static_cast<CTabLayoutUI*>(m_PaintManager.FindControl(_T("switch")));
	if (name == _T("frontoption"))
	{
		pControl->SelectItem(0);
	}
	else if (name == _T("portoption"))
	{
		pControl->SelectItem(1);
	}
	else if (name == _T("logoption"))
	{
		pControl->SelectItem(2);
	}
}

void MainWnd::InitWindow()
{
	DiskCleanSys& sys = DiskCleanSys::GetInstance();
	sys.Init(this);
}

void MainWnd::OnConnected()
{

}

void MainWnd::OnDisconnected()
{

}