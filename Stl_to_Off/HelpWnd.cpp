#include "HelpWnd.h"

void HelpWnd::InitWindow()
{
	RichEdit = static_cast<CRichEditUI*>(m_PaintManager.FindControl(_T("RichEdit")));
	RichEdit->SetText(_T("1.�������������stl��ʽ��off��ʽ��ת��\n\n2.����м�Ĳ���ѡ��stl�ļ�\n\n3.�����off�ļ������ڴ򿪵�stl�ļ�Ŀ¼��\n\n4.ʱ�����ޣ�Ŀǰת��Ч���е��������ҿ��ܴ���Bug�������ڴ�2.0�汾"));
}

void HelpWnd::OnClick(TNotifyUI & msg)
{
	// ��ȡ������Ϣ�Ŀؼ�����  
	CDuiString msgName = msg.pSender->GetName();
	if (_tcsicmp(msgName, _T("ButtonClose")) == 0)
	{
		Close();
	}
	__super::OnClick(msg);
}
