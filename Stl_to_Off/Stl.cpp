#include "Stl.h"

int Stl::facet_count = 0;
int Stl::point_count = 0;

Stl::Stl()
{
}

Stl::~Stl()
{
}

bool Stl::ReadSTLFile(const wchar_t *cfilename)
{
	if (cfilename == NULL)
	{
		return false;
	}

	ifstream in(cfilename, ios::in);
	if (!in)
	{
		return false;
	}
	string headStr;
	getline(in, headStr);

	in.close();


	if (headStr.empty())
	{
		return false;
	}

	if (headStr[0] == 's')
	{
		ReadASCII(cfilename);
	}
	else
	{
		return 2;
	}

	return true;
}

bool Stl::ReadASCII(const wchar_t *cfilename)
{
	ifstream myfile(cfilename);
	string temp;
	while (getline(myfile, temp))
	{
		s.push_back(temp);
		for (int i = 0; i < 6; i++)
		{
			if (temp[i] == 'o' && temp[i+1] == 'u')
			{
				facet_count++;
				break;
			}
		}
		for (int i = 0; i < 8; i++)
		{
			if (temp[i] == 'v' && temp[i+1] == 'e')
			{
				temp.erase(0, i+6);
				auto search = point.find(temp);
				if (search == point.end())
					point.insert(std::make_pair(temp, point_count++));
				break;
			}
		}
	
	}
	return true;
}

bool Stl::WriteOFFFile(const wchar_t * cfilename, wstring name)
{
	int lyy = name.size();
	name.erase(lyy - 3, lyy - 1);
	name.insert(lyy - 3, _T("off"));
	/*name.erase(0, name.find_last_of('\\')+1);*/

	ifstream myfile(cfilename);
	string temp;

	ofstream SaveFile(name.c_str());
	
	int count = 0;
	while (getline(myfile, temp))
	{
		for (int i = 0; i < 5; i++)
		{
			if (temp[i] == 's' && temp[i+1] == 'o'&& temp[i - 1] != 'd')
			{		
				SaveFile << "OFF" << endl;
				SaveFile << facet_count << " " << point_count << " " << 0 << endl;
				for (auto it = point.begin(); it != point.end(); ++it)
				{
					SaveFile << it->first << endl;
				}
				break;
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (temp[i] == 'v' && temp[i + 1] == 'e')
			{
				temp.erase(0, i+6);
				auto search = point.find(temp);
				if (search != point.end())
				{
					switch (count)
					{
					case 0:
						SaveFile << 3 << " " << search->second << " ";
						count = 1;
						break;
					case 1:
						SaveFile << search->second << " ";
						count = 2;
						break;
					case 2:
						SaveFile << search->second << endl;
						count = 0;
						break;
					}
					break;
				}
			}
		}
	}

	SaveFile.close();
	return true;
}
