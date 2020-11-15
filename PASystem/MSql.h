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
	vector<string> getFieldNames();//����ֶ�����
	vector< vector<string> > getRowDatas();//���һ������

	string error();

private:
	MYSQL m_data;
	int rows;//��
	unsigned int cols;//�ֶ�

	POINTER_INIT(MYSQL_RES, m_result);//������ݿ�Ĳ�������
	POINTER_INIT(MYSQL_FIELD, m_field);//���Ի���ֶ�
	MYSQL_ROW row_datas;//��ӡ����  һ������

	vector<string> v_field_names;//����ֶε�����
	vector< vector<string> > v_row_datas;//���һ������

};

