#include "StdAfx.h"
#include <WinBase.h>
#include "MainWnd.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skin"));

	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr)) return 0;

	MainWnd* pFrame = new MainWnd();
	if (pFrame == NULL) return 0;
	pFrame->Create(NULL, _T("DiskCleaner"), UI_WNDSTYLE_FRAME, 0L, 0, 0, 800, 572);
	pFrame->CenterWindow();
	::ShowWindow(*pFrame, SW_SHOW);

	CPaintManagerUI::MessageLoop();

	::CoUninitialize();
	return 0;
}
