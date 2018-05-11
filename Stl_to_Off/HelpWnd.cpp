#include "HelpWnd.h"

void HelpWnd::InitWindow()
{
	RichEdit = static_cast<CRichEditUI*>(m_PaintManager.FindControl(_T("RichEdit")));
	RichEdit->SetText(_T("1.本软件仅适用于stl格式到off格式的转换\n\n2.点击中间的菠萝选择stl文件\n\n3.输出的off文件保存在打开的stl文件目录中\n\n4.时间有限，目前转换效率有点慢，而且可能存在Bug，后期期待2.0版本"));
}

void HelpWnd::OnClick(TNotifyUI & msg)
{
	// 获取产生消息的控件名称  
	CDuiString msgName = msg.pSender->GetName();
	if (_tcsicmp(msgName, _T("ButtonClose")) == 0)
	{
		Close();
	}
	__super::OnClick(msg);
}
