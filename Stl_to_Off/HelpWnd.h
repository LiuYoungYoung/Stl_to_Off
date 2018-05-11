#pragma once
#include "stdafx.h"

class HelpWnd : public WindowImplBase
{
public:
	virtual LPCTSTR    GetWindowClassName() const { return _T("DUIHelpWnd"); }
	virtual CDuiString GetSkinFile() { return _T("help.xml"); }
	virtual CDuiString GetSkinFolder() { return _T("skin"); }
	virtual void InitWindow();
	virtual void OnClick(TNotifyUI& msg);

private:
	CRichEditUI *RichEdit;
};