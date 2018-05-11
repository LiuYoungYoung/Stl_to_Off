#include "stdafx.h"
#include "GetOpenFileNameDialog.h"
#include <commdlg.h> //�ļ�ѡ�񴰿�


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

	/**********���岢��ֵGetOpenFileName�����Ľṹ�����ͱ���Open_File_Name_Structure***********/
	OPENFILENAME Open_File_Name_Structure;   //GetOpenFileName�����Ľṹ�����ͱ���

	TCHAR szFile[MAX_PATH] = _T("");   //MAX_PATHΪ�궨�壬=260
	ZeroMemory(&Open_File_Name_Structure, sizeof(Open_File_Name_Structure));

	Open_File_Name_Structure.lStructSize = sizeof(Open_File_Name_Structure);
	Open_File_Name_Structure.hwndOwner = Windows_HWND;   //�˱���������øô򿪶Ի���Ĵ��ھ����Ӱ������ڵĵ���˳��
	Open_File_Name_Structure.lpstrFile = szFile;
	Open_File_Name_Structure.nMaxFile = sizeof(szFile);
	Open_File_Name_Structure.lpstrFilter = STR_FILE_FILTER;
	Open_File_Name_Structure.nFilterIndex = 1;
	Open_File_Name_Structure.lpstrFileTitle = NULL;
	Open_File_Name_Structure.nMaxFileTitle = 0;
	Open_File_Name_Structure.lpstrInitialDir = NULL;
	// OFN_NOCHANGEDIR ���ԣ� ���޸ĵ�ǰ����Ŀ¼
	Open_File_Name_Structure.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;
	/*******************************************************************************************/

	/*****************************����ϵͳ���ļ��Ի���**********************************************************/
	std::wstring result;
	if (GetOpenFileName(&Open_File_Name_Structure))
	{
		result = szFile;
	}
	return result;
}
