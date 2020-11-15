#pragma once

#include <iostream>
using namespace std;

#define COUT cout<<
#define COUT_LN cout<<endl
#define CIN cin>>
#define LK <<
#define LN <<endl

#define TO_STRING(X) #X
#define TO_SINGLE_CHAR(C) #@C

#define DELETE_OBJ(T) \
	if (T)\
	{\
		delete T;\
		T=nullptr;\
	}

#define DELETE_OBJ_ARR(T)\
	if (T)\
	{\
		delete[] T;\
		T=nullptr;\
	}

#define NEW_OBJ(TYPE,OBJ) \
	TYPE *OBJ=new TYPE

#define POINTER_INIT(TYPE,OBJ)\
	TYPE *OBJ=nullptr
	
#define POINTER_INS(OBJ,TYPE)\
	OBJ=new TYPE

#define SET_NULL(OBJ)\
	OBJ=nullptr

#define APOSTROPHE std::string("\'")
#define CONFIG_FILE TO_STRING(./config/config.ini)
#define PATH_IMG(PATH) TO_STRING(./Resources/images/PATH)
#define PATH_HTML(PATH) TO_STRING(./Resources/link/PATH)
#define EPSINON 1.e-6f
