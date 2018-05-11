#pragma once
#include "stdafx.h"

class MainPageWnd : public WindowImplBase
{
public:
	virtual LPCTSTR    GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual CDuiString GetSkinFile() { return _T("skin.xml"); }
	virtual CDuiString GetSkinFolder() { return _T("skin"); }
	virtual void InitWindow();
	virtual void OnClick(TNotifyUI& msg);

private:
	CButtonUI *ButtonLoadFile;
	CButtonUI *ButtonHelp;
	CLabelUI *LabelWait;
};