#include "MainPage.h"
#include "GetOpenFileNameDialog.h"
#include "Stl.h"
#include "HelpWnd.h"

void MainPageWnd::InitWindow()
{
	ButtonLoadFile = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("ButtonLoadFile")));
	ButtonHelp = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("ButtonHelp")));
	LabelWait = static_cast<CLabelUI*>(m_PaintManager.FindControl(_T("LabelWait")));
}

void MainPageWnd::OnClick(TNotifyUI & msg)
{
	// ��ȡ������Ϣ�Ŀؼ�����  
	CDuiString msgName = msg.pSender->GetName();
	if (_tcsicmp(msgName, _T("ButtonLoadFile")) == 0)
	{
		GetOpenFileNameDialog dlg;
		std::wstring file = dlg.getName(m_PaintManager.GetPaintWindow());
		ifstream myfile(file.c_str());

		if (file != _T(""))
		{
			int i = ::MessageBox(NULL, _T("�Ƿ�ת��ΪOFF��ʽ�ļ���"), file.c_str(), MB_OKCANCEL);
			if (1 == i)
			{
				LabelWait->SetText(_T("��ʽת���У��ȱ��裬������~~"));
				Stl stl;
				stl.ReadSTLFile(file.c_str());
				stl.WriteOFFFile(file.c_str(), file);
				wstring ws = _T("��ʽת����� �ļ�������") + file;
				LabelWait->SetText(ws.data());
			}
		}	
	}
	else if (_tcsicmp(msgName, _T("ButtonHelp")) == 0) 
	{
		HelpWnd *HelpWnd_Plan = new HelpWnd();
		HelpWnd_Plan->Create(m_PaintManager.GetPaintWindow(), _T(""), UI_WNDSTYLE_DIALOG, WS_EX_TOPMOST, 0, 0, 0, 0, NULL);
		HelpWnd_Plan->InitWindow();
		HelpWnd_Plan->CenterWindow();
	}
	__super::OnClick(msg);
}
