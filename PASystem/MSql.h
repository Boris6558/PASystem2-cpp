#pragma once

#include <mysql/mysql.h>
#include <cstring>
#include <string>
#include <vector>

#include <boost/assign.hpp>

#include "Good.h"

using namespace boost::assign;
class MSql
{
public:
	MSql();
	~MSql();

public:
	bool init();
	bool query(string query_str);
	bool search(string search_str);

	MYSQL getData();
	int getRows();
	unsigned int getCols();
	vector<string> getFieldNames();//获得字段数组
	vector< vector<string> > getRowDatas();//获得一行数据

	string error();

private:
	MYSQL m_data;
	int rows;//行
	unsigned int cols;//字段

	POINTER_INIT(MYSQL_RES, m_result);//获得数据库的查找数据
	POINTER_INIT(MYSQL_FIELD, m_field);//可以获得字段
	MYSQL_ROW row_datas;//打印各行  一行数据

	vector<string> v_field_names;//获得字段的名字
	vector< vector<string> > v_row_datas;//获得一行数据

};

