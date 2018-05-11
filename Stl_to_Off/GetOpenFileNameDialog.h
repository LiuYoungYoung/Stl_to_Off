#pragma once
class GetOpenFileNameDialog
{
public:
	GetOpenFileNameDialog();
	~GetOpenFileNameDialog();

	std::wstring getName(HWND Windows_HWND);
};

