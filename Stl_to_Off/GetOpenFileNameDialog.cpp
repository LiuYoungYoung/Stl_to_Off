#include "stdafx.h"
#include "GetOpenFileNameDialog.h"
#include <commdlg.h> //文件选择窗口


GetOpenFileNameDialog::GetOpenFileNameDialog()
{
}


GetOpenFileNameDialog::~GetOpenFileNameDialog()
{
}

std::wstring GetOpenFileNameDialog::getName(HWND Windows_HWND)
{
	const TCHAR STR_FILE_FILTER[] =
		_T("STL Files(*.stl,etc)\0*.stl;\0")
		_T("All Files(*.*)\0*.*\0");
	/***********************************************/

	/**********定义并赋值GetOpenFileName函数的结构体类型变量Open_File_Name_Structure***********/
	OPENFILENAME Open_File_Name_Structure;   //GetOpenFileName函数的结构体类型变量

	TCHAR szFile[MAX_PATH] = _T("");   //MAX_PATH为宏定义，=260
	ZeroMemory(&Open_File_Name_Structure, sizeof(Open_File_Name_Structure));

	Open_File_Name_Structure.lStructSize = sizeof(Open_File_Name_Structure);
	Open_File_Name_Structure.hwndOwner = Windows_HWND;   //此变量代表调用该打开对话框的窗口句柄，影响各窗口的叠放顺序
	Open_File_Name_Structure.lpstrFile = szFile;
	Open_File_Name_Structure.nMaxFile = sizeof(szFile);
	Open_File_Name_Structure.lpstrFilter = STR_FILE_FILTER;
	Open_File_Name_Structure.nFilterIndex = 1;
	Open_File_Name_Structure.lpstrFileTitle = NULL;
	Open_File_Name_Structure.nMaxFileTitle = 0;
	Open_File_Name_Structure.lpstrInitialDir = NULL;
	// OFN_NOCHANGEDIR 属性， 不修改当前工作目录
	Open_File_Name_Structure.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;
	/*******************************************************************************************/

	/*****************************调用系统打开文件对话框**********************************************************/
	std::wstring result;
	if (GetOpenFileName(&Open_File_Name_Structure))
	{
		result = szFile;
	}
	return result;
}
