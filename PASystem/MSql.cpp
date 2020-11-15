#include "MSql.h"

MSql::MSql()
{
}


MSql::~MSql()
{
}

bool MSql::init()
{
	bool ret = false;

	if (mysql_library_init(0, nullptr, nullptr) == 0)
	{
		COUT "mysql_library_init() success\n";
		ret = true;
	} else
	{
		COUT "mysql_library_init() failed\n";
		ret = false;
	}

	if (mysql_init(&m_data))
	{
		COUT "mysql_init() success\n";
		ret = true;
	} else
	{
		COUT "mysql_init() failed\n";
		ret = false;
	}

	//设置字符集
//可以设置的选项很多，这里设置字符集，否则无法处理中文
	if (0 == mysql_options(&m_data, MYSQL_SET_CHARSET_NAME, "gb2312"))
	{
		COUT "mysql_options() succeed" LN;
		ret = true;
	} else
	{
		COUT "mysql_options() failed" LN;
		ret = false;
	}

	//链接数据库
	if (mysql_real_connect(&m_data, "127.0.0.1", "root", "rootroot", "pasystem", 3306, nullptr, 0))
	{
		COUT "mysql_real_connect() success\n";
		ret = true;
	} else
	{
		COUT "mysql_real_connect() failed\n";
		ret = false;
	}

	return ret;
}

bool MSql::query(string query_str)
{
	bool ret = false;

	if (mysql_query(&m_data,query_str.c_str())!=0)
	{
		ret=false;
	} else
	{
		ret=true;
	}

	return ret;
}

bool MSql::search(string search_str)
{
	bool ret = false;

	v_field_names.clear();
	v_row_datas.clear();

	if (mysql_query(&m_data, search_str.c_str()) != 0)
	{
		ret = false;
	} else
	{
		//一次性取得数据集
		m_result = mysql_store_result(&m_data);;
		cols = mysql_num_fields(m_result);

		//获得每个字段
		for (unsigned int i = 0; i < cols; ++i)
		{
			m_field = mysql_fetch_field_direct(m_result, i);
			push_back(v_field_names)(m_field->name);
		}

		row_datas = mysql_fetch_row(m_result);
		while (row_datas)
		{
			vector<string> v_row;
			for (unsigned int i = 0; i < cols; ++i)
			{
				push_back(v_row)(string(row_datas[i]));
			}
			push_back(v_row_datas)(v_row);
			row_datas = mysql_fetch_row(m_result);
		}
		rows = v_row_datas.size();

		ret = true;
	}
	mysql_free_result(m_result);

	return ret;
}

MYSQL MSql::getData()
{
	return m_data;
}

int MSql::getRows()
{
	return rows;
}

unsigned int MSql::getCols()
{
	return cols;
}

vector<string> MSql::getFieldNames()
{
	return v_field_names;
}

vector< vector<string> > MSql::getRowDatas()
{
	return v_row_datas;
}

string MSql::error()
{
	return string(mysql_error(&m_data));
}
