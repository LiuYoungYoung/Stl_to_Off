#include "stdafx.h"
#include "MainPage.h"

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{

	CPaintManagerUI::SetInstance(hInstance);
	MainPageWnd *duiFrame = new MainPageWnd();
	if (duiFrame == NULL)
		return 0;

	duiFrame->Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame->SetIcon(IDI_ICON1);
	duiFrame->CenterWindow();
	duiFrame->ShowModal();

	return 0;
}