#pragma once

#include <cstring>
#include <vector>

#include <boost/assign.hpp>

#include "Good.h"

using namespace std;
using namespace boost::assign;

class ProvincesOfChina
{
private:
	ProvincesOfChina();
	~ProvincesOfChina();
public:
	static void init();
public:
	static vector<string> provinces;
	static vector< vector<string> > city;
};

