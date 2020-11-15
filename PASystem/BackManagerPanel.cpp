#include "BackManagerPanel.h"

#include <QTreeWidget>
#include <QListWidget>
#include <QTableWidgetItem>
#include <QLineEdit>
#include <QTableWidgetItem>
#include <QList>
#include <QMenu>
#include <QTableWidget>
#include <QPushButton>
#include <QDate>
#include <QMessageBox>

BackManagerPanel::BackManagerPanel(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	initMembers();
	connectMembers();

}

BackManagerPanel::~BackManagerPanel()
{
}

void BackManagerPanel::initMembers()
{
	setWindowTitle(QString::fromLocal8Bit("后台管理"));

	m_sql.init();

	ui.stackedWidget->setCurrentWidget(ui.page);

	ui.tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);//右键菜单  已删除的合同

	m_detail = new QAction(QString::fromLocal8Bit("详情"), ui.tableWidget);
	m_pa = new QAction(QString::fromLocal8Bit("发起绩效考核"), ui.tableWidget);
	m_revoke = new QAction(QString::fromLocal8Bit("吊销机构"), ui.tableWidget);

	//背景
	QPalette pal = palette();
	pal.setBrush(QPalette::Background, QBrush(QPixmap(PATH_IMG(manager_back.jpg))));
	setPalette(pal);

}

void BackManagerPanel::connectMembers()
{
	/******************** QTableWidget ************************/
	void (QTableWidget::*p_cellClicked)(int, int) = &QTableWidget::cellClicked;
	connect(ui.tableWidget, p_cellClicked,//点击一行
		[=](int row, int col)mutable
	{
		c_row = row;
		COUT "当前选择第 " LK c_row LK "行" LN;
		c_mechanism_id = string(ui.tableWidget->item(row, 0)->text().toLocal8Bit());
		c_mechanism_name = string(ui.tableWidget->item(row, 1)->text().toLocal8Bit());
		COUT "这一行机构编号 :" LK c_mechanism_id LK " 名称：" LK c_mechanism_name LN;

	}
	);
	connect(ui.tableWidget, &QTableWidget::customContextMenuRequested,//右键 合同
		[=](const QPoint &posAtViewport)mutable
	{
		QMenu menu;

		// [4] 获取右键菜单点击的树的节点 (QTableView, QListView 里也可以这么用)
		QModelIndex index = ui.tableWidget->indexAt(posAtViewport);

		// [5] 根据节点的特点动态显示菜单项，点击到树的节点时才显示删除菜单项
		if (index.isValid())
		{
			//菜单右键创建
			menu.addAction(m_detail);
			menu.addAction(m_pa);
			//menu.addAction(m_revoke);//吊销
		} else
		{
			//在外面右键创建
		}

		menu.exec(QCursor::pos());
	}
	);

	/********************* QAction *************************/
	connect(m_detail, &QAction::triggered,//详情
		[=]()mutable
	{
		COUT c_row LK " 的数据，编号：" LK c_mechanism_id LK " 名称：" LK c_mechanism_name LK "的详情" LN;
		POINTER_INS(m_md, MechanismDetail(c_mechanism_id));
		m_md->show();
		SET_NULL(m_md);
	}
	);
	connect(m_pa, &QAction::triggered,//发起绩效考核
		[=]()mutable
	{
		
		POINTER_INS(m_pa_type, PAType);
		m_pa_type->show();

		/************************ PAType *******************************/
		connect(m_pa_type, &PAType::sigSendPATable,
			[=](const QString &text)mutable
		{
			COUT c_row LK " 的数据，编号：" LK c_mechanism_id LK " 名称：" LK c_mechanism_name LK "的绩效考核" LN;

			property_tree::ini_parser::read_ini(CONFIG_FILE, pt);
			pt.put<string>("CurrentMechanismInfo.pa_type", string(text.toLocal8Bit()));
			property_tree::ini_parser::write_ini(CONFIG_FILE, pt);

			m_sql.search(
				"SELECT * FROM pa_level_result WHERE mechanism_id=" + APOSTROPHE + c_mechanism_id + APOSTROPHE + ";"
			);
			if (m_sql.getRows() == 0)//如果找不到，就插入
			{
				if (m_sql.query(
					"INSERT INTO pa_level_result("
					"mechanism_id,"
					"mechanism_name,"
					"result_level,"
					"date,"
					"is_write,"
					"type)"
					" VALUES(" +
					APOSTROPHE + c_mechanism_id + APOSTROPHE + "," +
					APOSTROPHE + c_mechanism_name + APOSTROPHE + "," +
					APOSTROPHE + string("non") + APOSTROPHE + "," +
					APOSTROPHE + string(QDate::currentDate().toString(Qt::LocalDate).toLocal8Bit()) + APOSTROPHE + "," +
					APOSTROPHE + string("否") + APOSTROPHE + "," +
					APOSTROPHE + string(pt.get<string>("CurrentMechanismInfo.pa_type")) + APOSTROPHE +
					");"
				))
				{
					QMessageBox::warning(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit(string("已向编号为：" + c_mechanism_id + "发起绩效考核表！").c_str()));
				} else
				{
					QMessageBox::warning(this, QString::fromLocal8Bit("失败"), QString::fromLocal8Bit(string("发起失败！原因：" + m_sql.error()).c_str()));
				}

			} else//修改参数，重新填写考核表
			{
				if (m_sql.query(
					"UPDATE pa_level_result SET result_level='non',is_write='否',type=" +
					APOSTROPHE + string(pt.get<string>("CurrentMechanismInfo.pa_type")) + APOSTROPHE +
					" WHERE mechanism_id=" +
					APOSTROPHE + c_mechanism_id + APOSTROPHE + ";"
				))
				{
					QMessageBox::warning(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit(string("已向编号为：" + c_mechanism_id + "发起绩效考核表！").c_str()));
				} else
				{
					QMessageBox::warning(this, QString::fromLocal8Bit("失败"), QString::fromLocal8Bit(string("发起失败！原因：" + m_sql.error()).c_str()));
				}
			}
			m_pa_type->close();
			SET_NULL(m_pa_type);
		}
		);

	}
	);
	connect(m_revoke, &QAction::triggered,//吊销
		[=]()mutable
	{
		COUT c_row LK " 的数据，编号：" LK c_mechanism_id LK " 名称：" LK c_mechanism_name LK "的 吊销" LN;

	}
	);

	/******************** QListWidget ************************/
	void (QListWidget::*p_currentTextChanged)(const QString &) = &QListWidget::currentTextChanged;
	connect(ui.listWidget, p_currentTextChanged,  //切换面板
		[=](const QString &text)mutable
	{
		if (text.compare(QString::fromLocal8Bit("机构信息")) == 0)
		{
			ui.stackedWidget->setCurrentWidget(ui.page);

			//显示数据表
			m_sql.search(
				"SELECT mechanism_id,mechanism_name,type,address,register,status FROM mechanism_info;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}

		} else if (text.compare(QString::fromLocal8Bit("绩效评级")) == 0)
		{
			ui.stackedWidget->setCurrentWidget(ui.page_2);

			//显示数据表
			m_sql.search(
				"SELECT mechanism_id,mechanism_name,type,address,register,status FROM mechanism_info;"
			);
			ui.tableWidget_2->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget_2->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}

		} else if (text.compare(QString::fromLocal8Bit("查看")) == 0)
		{
			ui.stackedWidget->setCurrentWidget(ui.page_3);
			freshSeeInfo();

		} else if (text.compare(QString::fromLocal8Bit("设置")) == 0)
		{
			ui.stackedWidget->setCurrentWidget(ui.page_4);
		}
	}
	);
	connect(ui.listWidget_see, &QListWidget::itemDoubleClicked,//查看消息
		[=](QListWidgetItem *item)mutable
	{
		//查看哪个机构发来的
		string id = string(item->text().toLocal8Bit()).substr(
			string(item->text().toLocal8Bit()).find("(") + 1, string(item->text().toLocal8Bit()).find(")") - string(item->text().toLocal8Bit()).find("(") - 1
		);
		//发来的什么请求
		string call_type = string(item->text().toLocal8Bit()).substr(
			string(item->text().toLocal8Bit()).find("{") + 1, string(item->text().toLocal8Bit()).find("}") - string(item->text().toLocal8Bit()).find("{") - 1
		);
		COUT "机构" LK id LK "发来请求是：" LK call_type LN;

		if (call_type.compare("反馈信息") == 0)//打开员工反馈窗口查看
		{
			POINTER_INS(m_sfb, SeeFeedBack(id));
			m_sfb->show();
			SET_NULL(m_sfb);
		}

	}
	);

	/********************* QLineEdit *************************/
	connect(ui.lineEdit_search, &QLineEdit::textChanged,//机构信息 ->查询
		[=](const QString &text)mutable
	{
		findEmpInfoFromTable(string(text.toLocal8Bit()), ui.tableWidget);
	}
	);

	/********************* QPushButton *************************/
	connect(ui.pushButton_fresh, &QPushButton::clicked, 
		[=]()mutable
	{
		freshSeeInfo();
	}
		);
	connect(ui.pushButton_performanceAll, &QPushButton::clicked,//向全体发起绩效考核
		[=]()mutable
	{
		POINTER_INS(m_pa_type, PAType);
		m_pa_type->show();

		/************************ PAType *******************************/
		connect(m_pa_type, &PAType::sigSendPATable,
			[=](const QString &text)mutable
		{
			COUT "全体发起" LN;

			property_tree::ini_parser::read_ini(CONFIG_FILE, pt);
			pt.put<string>("CurrentMechanismInfo.pa_type", string(text.toLocal8Bit()));
			property_tree::ini_parser::write_ini(CONFIG_FILE, pt);

			v_all_id.clear();
			v_all_name.clear();

			m_sql.search(
				"SELECT * FROM mechanism_info;"
			);
			if (m_sql.getRows()!=0)//说明有注册的机构
			{
				//获得所有机构的编号
				for (int i=0;i<m_sql.getRows();++i)
				{
					push_back(v_all_id)(m_sql.getRowDatas()[i][0]);
					push_back(v_all_name)(m_sql.getRowDatas()[i][1]);
				}
			}

			//为每个员工添加考核表
			for (int i=0;i<v_all_id.size();++i)
			{
				m_sql.search(
					"SELECT * FROM pa_level_result WHERE mechanism_id=" + APOSTROPHE + v_all_id[i] + APOSTROPHE+";"
				);
				if (m_sql.getRows() == 0)//还没有添加
				{
					if (m_sql.query(
						"INSERT INTO pa_level_result("
						"mechanism_id,"
						"mechanism_name,"
						"result_level,"
						"date,"
						"is_write,"
						"type)"
						"VALUES("+
						APOSTROPHE + v_all_id[i] + APOSTROPHE+","+
						APOSTROPHE + v_all_name[i] + APOSTROPHE + "," +
						APOSTROPHE + string("non") + APOSTROPHE + "," +
						APOSTROPHE + string(QDate::currentDate().toString(Qt::LocalDate).toLocal8Bit()) + APOSTROPHE + "," +
						APOSTROPHE + string("否") + APOSTROPHE + "," +
						APOSTROPHE + string(text.toLocal8Bit()) + APOSTROPHE+
						");"
					))
					{
						//QMessageBox::warning(this, QString::fromLocal8Bit("成功！"), QString::fromLocal8Bit(string("以向该员工发送绩效考核!").c_str()));
					} else
					{
						QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit(string("发送绩效考核失败！：" + m_sql.error()).c_str()));
					}


				} else//修改绩效结果位Non
				{
					if (m_sql.query(
						"UPDATE pa_level_result SET result_level='non',date=" +
						APOSTROPHE + string(QDate::currentDate().toString(Qt::LocalDate).toLocal8Bit()) + APOSTROPHE + "," +
						"is_write="+ APOSTROPHE + string("否") + APOSTROPHE + "," +
						"type=" + APOSTROPHE + string(text.toLocal8Bit()) + APOSTROPHE +
						" WHERE mechanism_id="+ APOSTROPHE + v_all_id[i] + APOSTROPHE+";"
					))
					{
						//QMessageBox::warning(this, QString::fromLocal8Bit("成功！"), QString::fromLocal8Bit(string("以向该员工发送绩效考核!").c_str()));
					} else
					{
						QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit(string("发送绩效考核失败！：" + m_sql.error()).c_str()));
					}
				}
			}

			QMessageBox::warning(this, QString::fromLocal8Bit("成功！"), QString::fromLocal8Bit(string("全体发送成功!").c_str()));

			//end
			m_pa_type->close();
			SET_NULL(m_pa_type);
		}
		);
	}
	);
	connect(ui.pushButton_performance_rules, &QPushButton::clicked,//绩效评级指标及考核样式表
		[=]()mutable
	{
		POINTER_INS(m_table, PATable);
		m_table->show();
		SET_NULL(m_table);
	}
	);
	connect(ui.pushButton_see_performanceResult, &QPushButton::clicked,//查看绩效结果
		[=]()mutable
	{
		POINTER_INS(m_result, PAResult);
		m_result->show();
		SET_NULL(m_result);
	}
	);
	connect(ui.pushButton_help_me_decision_level, &QPushButton::clicked,//帮我决策绩效评级
		[=]()mutable
	{
		POINTER_INS(m_hmd, HelpMeDecision);
		m_hmd->show();
		SET_NULL(m_hmd);
	}
	);
	connect(ui.pushButton_alter_passwd, &QPushButton::clicked,// 设置 -> 修改密码
		[=]()mutable
	{
		COUT "修改密码" LN;

		m_sql.search(
			"SELECT * FROM admin_acc;"
		);

		string login_name = m_sql.getRowDatas()[0][0];

		if (string(ui.lineEdit_old_passwd->text().toLocal8Bit()).compare(m_sql.getRowDatas()[0][1]) == 0)
		{
			if (string(ui.lineEdit_new_passwd->text().toLocal8Bit()).compare("") == 0 ||
				string(ui.lineEdit_new_passwd_again->text().toLocal8Bit()).compare("") == 0
				)
			{
				QMessageBox::warning(this, QString::fromLocal8Bit("提示！"), QString::fromLocal8Bit(string("输入不能为空！").c_str()));
				return;
			}
			if (string(ui.lineEdit_new_passwd->text().toLocal8Bit()).compare(string(ui.lineEdit_new_passwd_again->text().toLocal8Bit())) == 0)
			{
				COUT "修改密码" LN;

				if (m_sql.query(
					"UPDATE admin_acc SET login_passwd=" +
					APOSTROPHE + string(ui.lineEdit_new_passwd_again->text().toLocal8Bit()) + APOSTROPHE +
					" WHERE login_name=" + APOSTROPHE + login_name + APOSTROPHE + ";"
				))
				{
					QMessageBox::warning(this, QString::fromLocal8Bit("提示！"), QString::fromLocal8Bit(string("更改成功！！").c_str()));
				} else
				{
					QMessageBox::warning(this, QString::fromLocal8Bit("提示！"), QString::fromLocal8Bit(string("更改失败！原因：" + m_sql.error()).c_str()));
				}


			} else
			{
				QMessageBox::warning(this, QString::fromLocal8Bit("提示！"), QString::fromLocal8Bit(string("新密码不一致！").c_str()));
			}

		} else
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示！"), QString::fromLocal8Bit(string("旧密码不匹配！").c_str()));
		}

	}
	);


}

void BackManagerPanel::freshSeeInfo()
{
	ui.listWidget_see->clear();

	//信息反馈
	m_sql.search(
		"SELECT * FROM mechanism_feedback WHERE is_write='否';"
	);
	for (int row = 0; row < m_sql.getRows(); ++row)
	{
		ui.listWidget_see->addItem(QString::fromLocal8Bit(string(
			"收到一条来自机构：(" + m_sql.getRowDatas()[row][0] + ")" + " 的{反馈信息}，请查看！ " + "[" + m_sql.getRowDatas()[row][5] + "]"
		).c_str()
		));
	}
}

void BackManagerPanel::findEmpInfoFromTable(string & str, QTableWidget * widget)
{
	if (widget == Q_NULLPTR)
	{
		return;
	}

	QList<QTableWidgetItem*> findItems = widget->findItems(QString::fromLocal8Bit(str.c_str()), Qt::MatchContains);
	bool b_row_hide = true;
	for (int i = 0; i < widget->rowCount(); ++i)
	{
		b_row_hide = true;
		foreach(QTableWidgetItem* item, findItems)
		{
			if (Q_NULLPTR == item) continue;
			if (widget->row(item) == i)
			{
				b_row_hide = false;
				break;
			}
		}
		widget->setRowHidden(i, b_row_hide);
	}
}
