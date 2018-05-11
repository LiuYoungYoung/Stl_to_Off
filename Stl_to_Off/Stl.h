#pragma once
#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

template <int D, class T = double>
class Vec {
private:
	T v[D];
public:
	void SetParam(double &x, double &y, double &z) {
		v[0] = x;
		v[1] = y;
		v[2] = z;
	}
};

typedef Vec<3, double> Vec3d;

class Stl
{
public:
	Stl();
	~Stl();

	bool ReadSTLFile(const wchar_t *cfilename);

	bool ReadASCII(const wchar_t *cfilename);

	bool WriteOFFFile(const wchar_t *cfilename,wstring name);

private:

	std::vector<std::string> s;
	std::map<std::string,int > point;

	static int facet_count;
	static int point_count;
};



