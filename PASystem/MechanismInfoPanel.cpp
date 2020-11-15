#include "MechanismInfoPanel.h"

#include <QListWidget>
#include <QImage>
#include <QPixmap>
#include <QTreeWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QLineEdit>
#include <QTableWidgetItem>
#include <QList>
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>
#include <vector>
#include <QMenu>
#include <QDate>

MechanismInfoPanel::MechanismInfoPanel(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	initMembers();
	connectMembers();

}

MechanismInfoPanel::~MechanismInfoPanel()
{
}

void MechanismInfoPanel::initMembers()
{
	setWindowTitle(QString::fromLocal8Bit("机构管理"));

	m_sql.init();

	ui.stackedWidget->setCurrentIndex(0);

	//加载公司名字 和logo
	property_tree::ini_parser::read_ini(CONFIG_FILE, pt);
	m_sql.search(
		"SELECT * FROM mechanism_info WHERE login_name="+
		APOSTROPHE+pt.get<string>("CurrentMechanismInfo.login_name")+APOSTROPHE+";"
	);
	if (m_sql.getRows() != 0)
	{
		ui.label_name_team_name->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][1].c_str()));

		if (m_sql.getRowDatas()[0][18].compare("") != 0)
		{
			QImage img;
			img.load(QString::fromLocal8Bit(m_sql.getRowDatas()[0][18].c_str()));
			ui.label_name_logo->setPixmap(QPixmap::fromImage(img));
		} else
		{
			ui.label_name_logo->setText(QString::fromLocal8Bit("LOGO HEER"));
		}
	}

	ui.tableWidget_contract->setContextMenuPolicy(Qt::CustomContextMenu);//右键菜单  合同
	ui.tableWidget_del_contract_2->setContextMenuPolicy(Qt::CustomContextMenu);//右键菜单  已删除的合同

	contract_del = new QAction(QString::fromLocal8Bit("删除"), ui.tableWidget_contract);
	contract_re = new QAction(QString::fromLocal8Bit("恢复"), ui.tableWidget_contract);

	//背景
	QPalette pal = palette();
	pal.setBrush(QPalette::Background, QBrush(QPixmap(PATH_IMG(mechanism_back.jpg))));
	setPalette(pal);
}

void MechanismInfoPanel::connectMembers()
{
	/******************** QListWidget ************************/
	void (QListWidget::*p_currentTextChanged)(const QString &) = &QListWidget::currentTextChanged;//切换模块
	connect(ui.listWidget, p_currentTextChanged,
		[=](const QString &text)mutable
	{
		if (text.compare(QString::fromLocal8Bit("公司概况")) == 0)
		{
			ui.stackedWidget->setCurrentIndex(0);
			showMechanismInfo();

		}else if (text.compare(QString::fromLocal8Bit("人力资源")) == 0)
		{
			ui.stackedWidget->setCurrentIndex(1);
			ui.stackedWidget_3->setCurrentIndex(0);

			showHR();
		} else if (text.compare(QString::fromLocal8Bit("合同管理")) == 0)
		{
			ui.stackedWidget->setCurrentIndex(2);
			ui.stackedWidget_2->setCurrentWidget(ui.page_add_mechanism);

			showContractManager();
		} else if (text.compare(QString::fromLocal8Bit("查看")) == 0)
		{
			ui.stackedWidget->setCurrentIndex(3);
			showSee();
			freshSeeInfo();


		} else if (text.compare(QString::fromLocal8Bit("设置")) == 0)
		{
			ui.stackedWidget->setCurrentIndex(4);
			showSet();
		}
	
	});
	connect(ui.listWidget_see, &QListWidget::itemDoubleClicked,//查看消息
		[=](QListWidgetItem *item)mutable
	{
		property_tree::ini_parser::read_ini(CONFIG_FILE, pt);

		COUT string(item->text().toLocal8Bit()) LN;
		string str_key = string(item->text().toLocal8Bit()).substr(
			string(item->text().toLocal8Bit()).find("(") + 1, string(item->text().toLocal8Bit()).find(")") - string(item->text().toLocal8Bit()).find("(") - 1
		);
		string path_img = pt.get<string>("CurrentMechanismInfo.path_mechanism_logo");
		//如果关键字有绩效考核表，打开表填写核对
		if (str_key.compare("绩效考核表") == 0)
		{
			COUT "打开考核表填写" LN;
			POINTER_INS(m_table, PATable(
				pt.get<string>("CurrentMechanismInfo.mechanism_id"),
				pt.get<string>("CurrentMechanismInfo.pa_type")
			));
			m_table->show();
			SET_NULL(m_table);

		} else if (str_key.compare("绩效考核结果") == 0)
		{
			POINTER_INS(m_result, PAResult("Mechanism Mark"));
			m_result->show();
			SET_NULL(m_result);
		} else if (str_key.compare("招聘信息") == 0)
		{
			COUT "打开招聘信息表格" LN;
			POINTER_INS(m_hr_info, HREcruitmentInfo(
				pt.get<string>("CurrentMechanismInfo.mechanism_id")
			));
			m_hr_info->show();
			SET_NULL(m_hr_info);
		}
	}
	);

	/******************** QTableWidget ************************/
	void (QTableWidget::*p_cellClicked)(int, int) = &QTableWidget::cellClicked;
	connect(ui.tableWidget_contract, p_cellClicked,//点击一行
		[=](int row, int col)mutable
	{
		c_row = row;
		COUT "当前选择第 " LK c_row LK "行" LN;
		COUT "这一行合同编号 :";
		c_ctract_id = string(ui.tableWidget_contract->item(row, 0)->text().toLocal8Bit());
		COUT c_ctract_id LN;

	}
	);
	connect(ui.tableWidget_contract, &QTableWidget::customContextMenuRequested,//右键 合同
		[=](const QPoint &posAtViewport)mutable
	{
		QMenu menu;

		// [4] 获取右键菜单点击的树的节点 (QTableView, QListView 里也可以这么用)
		QModelIndex index = ui.tableWidget_contract->indexAt(posAtViewport);

		// [5] 根据节点的特点动态显示菜单项，点击到树的节点时才显示删除菜单项
		if (index.isValid())
		{
			//菜单右键创建
			menu.addAction(contract_del);
		} else
		{
			//在外面右键创建
		}

		menu.exec(QCursor::pos());
	}
	);
	connect(ui.tableWidget_del_contract_2, p_cellClicked,//点击一行
		[=](int row, int col)mutable
	{
		c_row = row;
		COUT "当前选择第 " LK c_row LK "行" LN;
		COUT "这一行合同编号 :";
		c_ctract_id = string(ui.tableWidget_del_contract_2->item(row, 0)->text().toLocal8Bit());
		COUT c_ctract_id LN;

	}
	);
	connect(ui.tableWidget_del_contract_2, &QTableWidget::customContextMenuRequested,//右键 恢复删除合同
		[=](const QPoint &posAtViewport)mutable
	{
		QMenu menu;

		// [4] 获取右键菜单点击的树的节点 (QTableView, QListView 里也可以这么用)
		QModelIndex index = ui.tableWidget_del_contract_2->indexAt(posAtViewport);

		// [5] 根据节点的特点动态显示菜单项，点击到树的节点时才显示删除菜单项
		if (index.isValid())
		{
			//菜单右键创建
			menu.addAction(contract_re);
		} else
		{
			//在外面右键创建
		}

		menu.exec(QCursor::pos());
	}
	);


	/********************* QAction *************************/
	connect(contract_del, &QAction::triggered,//删除合同
		[=]()mutable
	{
		if (c_row != -1)
		{
			property_tree::ini_parser::read_ini(CONFIG_FILE, pt);

			COUT "删除第" LK c_row LK "行" LN;
			ui.tableWidget_contract->removeRow(c_row);
			m_sql.query(
				"UPDATE contract_info SET is_del='是',"
				"del_time=" +
				APOSTROPHE + string(QDate::currentDate().toString(Qt::LocalDate).toLocal8Bit()) + APOSTROPHE +
				" WHERE mechanism_id=" +
				APOSTROPHE + pt.get<string>("CurrentMechanismInfo.mechanism_id") + APOSTROPHE + " AND "
				"contract_id="+ APOSTROPHE + c_ctract_id + APOSTROPHE + ";"
			);
		}

	}
	);
	connect(contract_re, &QAction::triggered,//恢复合同
		[=]()mutable
	{
		if (c_row != -1)
		{
			property_tree::ini_parser::read_ini(CONFIG_FILE, pt);

			COUT "恢复第" LK c_row LK "行" LN;
			ui.tableWidget_del_contract_2->removeRow(c_row);
			m_sql.query(
				"UPDATE contract_info SET is_del='否',"
				"del_time=" +
				APOSTROPHE + string("") + APOSTROPHE +
				" WHERE mechanism_id=" +
				APOSTROPHE + pt.get<string>("CurrentMechanismInfo.mechanism_id") + APOSTROPHE + " AND "
				"contract_id=" + APOSTROPHE + c_ctract_id + APOSTROPHE + ";"
			);
		}

	}
	);

	/******************** QTreeWidget ************************/
	void (QTreeWidget::*p_currentItemChanged)(QTreeWidgetItem*, QTreeWidgetItem*) = &QTreeWidget::currentItemChanged;
	connect(ui.treeWidget_2, p_currentItemChanged,//人力资源模块->treewidget
		[=](QTreeWidgetItem *current, QTreeWidgetItem *previous)mutable
	{
		if (current->text(0).compare(QString::fromLocal8Bit("公司员工概况")) == 0)
		{
			ui.stackedWidget_3->setCurrentWidget(ui.page_teamInfo);

		} else if (current->text(0).compare(QString::fromLocal8Bit("招聘员工")) == 0)
		{
			ui.stackedWidget_3->setCurrentWidget(ui.page_recruitmentEmp);
		} else if (current->text(0).compare(QString::fromLocal8Bit("简历查看")) == 0)
		{
			ui.stackedWidget_3->setCurrentWidget(ui.page_seeResume);

			ui.label_resume1->setPixmap(QPixmap::fromImage(QImage(PATH_IMG(1.jpg))));
			ui.label_resume2->setPixmap(QPixmap::fromImage(QImage(PATH_IMG(2.jpg))));
			ui.label_resume3->setPixmap(QPixmap::fromImage(QImage(PATH_IMG(3.jpg))));
		}
	}
	);
	connect(ui.treeWidget, p_currentItemChanged,//合同管理模块->treewidget
		[=](QTreeWidgetItem *current, QTreeWidgetItem *previous)mutable
	{
		if (current->text(0).compare(QString::fromLocal8Bit("添加机构")) == 0)
		{
			ui.stackedWidget_2->setCurrentWidget(ui.page_add_mechanism);

		} else if (current->text(0).compare(QString::fromLocal8Bit("机构查询")) == 0)
		{
			ui.stackedWidget_2->setCurrentWidget(ui.page_search_mechanism);

			property_tree::ini_parser::read_ini(CONFIG_FILE, pt);
			//显示数据表
			m_sql.search(
				"SELECT * FROM add_mechanism WHERE mechanism_id="+
				APOSTROPHE +pt.get<string>("CurrentMechanismInfo.mechanism_id")+APOSTROPHE+";"
			);
			ui.tableWidget_mechanism->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 1; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget_mechanism->setItem(i, j-1, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}

		} else if (current->text(0).compare(QString::fromLocal8Bit("新增合同类别")) == 0)
		{
			ui.stackedWidget_2->setCurrentWidget(ui.page_add_contract_class);
		} else if (current->text(0).compare(QString::fromLocal8Bit("合同类别查询")) == 0)
		{
			ui.stackedWidget_2->setCurrentWidget(ui.page_search_contract_class);

			property_tree::ini_parser::read_ini(CONFIG_FILE, pt);
			//显示数据表
			m_sql.search(
				"SELECT * FROM contract_class_info WHERE mechanism_id="+
				APOSTROPHE + pt.get<string>("CurrentMechanismInfo.mechanism_id")+APOSTROPHE+";"
			);
			ui.tableWidget_contractClass->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 1; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget_contractClass->setItem(i, j-1, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}

		} else if (current->text(0).compare(QString::fromLocal8Bit("新增合同")) == 0)
		{
			ui.stackedWidget_2->setCurrentWidget(ui.page_add_contract);
		} else if (current->text(0).compare(QString::fromLocal8Bit("合同查询")) == 0)
		{
			ui.stackedWidget_2->setCurrentWidget(ui.page_search_contract);

			property_tree::ini_parser::read_ini(CONFIG_FILE, pt);
			//显示数据表
			m_sql.search("SELECT contract_id,contract_class_id,contract_class_name,commit_man,commit_date FROM contract_info WHERE is_del='否';");
			ui.tableWidget_contract->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget_contract->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}

		} else if (current->text(0).compare(QString::fromLocal8Bit("已删除合同")) == 0)
		{
			ui.stackedWidget_2->setCurrentWidget(ui.page_has_del_contract);
			m_sql.search("SELECT contract_id,contract_class_id,contract_class_name,commit_man,commit_date,del_time FROM contract_info WHERE is_del='是';");
			ui.tableWidget_del_contract_2->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget_del_contract_2->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}

		} else if (current->text(0).compare(QString::fromLocal8Bit("合同注意事项")) == 0)
		{
			ui.stackedWidget_2->setCurrentWidget(ui.page_contract_tip);
		}
	}
	);

	/********************* QLineEdit *************************/
	connect(ui.lineEdit_HR_search, &QLineEdit::textChanged,//人力资源给-> 公司概况 ->查询
		[=](const QString &text)mutable
	{
		findEmpInfoFromTable(string(text.toLocal8Bit()), ui.tableWidget_HR);
	}
	);
	connect(ui.lineEdit_mechanismSearch, &QLineEdit::textChanged,//机构 ->查询
		[=](const QString &text)mutable
	{
		findEmpInfoFromTable(string(text.toLocal8Bit()), ui.tableWidget_mechanism);
	}
	);
	connect(ui.lineEdit_searchContractClass, &QLineEdit::textChanged,//合同类别 ->查询
		[=](const QString &text)mutable
	{
		findEmpInfoFromTable(string(text.toLocal8Bit()), ui.tableWidget_contractClass);
	}
	);
	connect(ui.lineEdit_addcontract_contractId, &QLineEdit::textChanged,//新增合同 -> 合同类别编号
		[=](const QString &text)mutable
	{
		property_tree::ini_parser::read_ini(CONFIG_FILE, pt);
		m_sql.search(
			"SELECT contract_name FROM contract_class_info WHERE mechanism_id="+
			APOSTROPHE+ pt.get<string>("CurrentMechanismInfo.mechanism_id")+APOSTROPHE+" AND "
			"contract_id="+APOSTROPHE+string(text.toLocal8Bit())+APOSTROPHE+";"
		);
		if (m_sql.getRows())
		{
			ui.lineEdit_addcontract_contractClass->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][0].c_str()));
		}else{
			ui.lineEdit_addcontract_contractClass->setText("");
		}
	}
	);
	connect(ui.lineEdit_addcontract_mechanismId, &QLineEdit::textChanged,//新增合同 -> 机构编号
		[=](const QString &text)mutable
	{
		property_tree::ini_parser::read_ini(CONFIG_FILE, pt);
		m_sql.search(
			"SELECT add_mechanism_name FROM add_mechanism WHERE mechanism_id=" +
			APOSTROPHE + pt.get<string>("CurrentMechanismInfo.mechanism_id") + APOSTROPHE + " AND "
			"add_mechanism_id=" + APOSTROPHE + string(text.toLocal8Bit()) + APOSTROPHE + ";"
		);
		if (m_sql.getRows())
		{
			ui.lineEdit_addcontract_mechanismName->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][0].c_str()));
		} else
		{
			ui.lineEdit_addcontract_mechanismName->setText("");
		}
	}
	);
	connect(ui.lineEdit_search_contract, &QLineEdit::textChanged,//合同查询 ->查询
		[=](const QString &text)mutable
	{
		findEmpInfoFromTable(string(text.toLocal8Bit()), ui.tableWidget_contract);
	}
	);
	connect(ui.lineEdit_search_del_contract_2, &QLineEdit::textChanged,//已经删除的合同 ->查询
		[=](const QString &text)mutable
	{
		findEmpInfoFromTable(string(text.toLocal8Bit()), ui.tableWidget_del_contract_2);
	}
	);


	/********************* QPushButton *************************/
	connect(ui.pushButton,&QPushButton::clicked,
		[=]()mutable
	{
		POINTER_INS(fb, FeedBack(string(ui.lineEdit_team_name_2->text().toLocal8Bit())));
		fb->show();
		SET_NULL(fb);
	}
		);
	connect(ui.pushButton_mechanismAdd, &QPushButton::clicked,//添加机构
		[=]()mutable
	{

		if (ui.lineEdit_mechanismId->text().compare("") == 0 ||
			ui.lineEdit_mechanismName->text().compare("") == 0 ||
			ui.lineEdit_mechanismSimpleName->text().compare("") == 0 ||
			ui.lineEdit_mechanismPerson->text().compare("") == 0 ||
			ui.lineEdit_mechanismRegisterMoney->text().compare("") == 0 ||
			ui.lineEdit_mechanismRegisterAddress->text().compare("") == 0
			)
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("失败！请检查输入是否有空！").c_str()));
			return;
		}

		property_tree::ini_parser::read_ini(CONFIG_FILE, pt);
		if (m_sql.query(
			"INSERT INTO add_mechanism("
			"mechanism_id,"
			"add_mechanism_id,"
			"add_mechanism_name,"
			"add_mechanism_simple_name,"
			"add_mechanism_man,"
			"add_mechanism_registerMoney,"
			"add_mechanism_address)"
			"VALUES(" +
			APOSTROPHE + pt.get<string>("CurrentMechanismInfo.mechanism_id") + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_mechanismId->text().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_mechanismName->text().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_mechanismSimpleName->text().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_mechanismPerson->text().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_mechanismRegisterMoney->text().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_mechanismRegisterAddress->text().toLocal8Bit()) + APOSTROPHE +
			");"
		))
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("机构添加成功"));
		} else
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit(string("失败原因：" + m_sql.error()).c_str()));
		}
	}
	);
	connect(ui.pushButton_contractClassAdd, &QPushButton::clicked,//新增合同类别
		[=]()mutable
	{

		if (ui.lineEdit_contractClassId->text().compare("") == 0 ||
			ui.lineEdit_contractClassName->text().compare("") == 0
			)
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("失败！请检查输入是否有空！").c_str()));
			return;
		}

		property_tree::ini_parser::read_ini(CONFIG_FILE, pt);
		if (m_sql.query(
			"INSERT INTO contract_class_info("
			"mechanism_id,"
			"contract_id,"
			"contract_name)"
			"VALUES(" +
			APOSTROPHE + pt.get<string>("CurrentMechanismInfo.mechanism_id") + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_contractClassId->text().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_contractClassName->text().toLocal8Bit()) + APOSTROPHE +
			");"
		))
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("合同类别添加成功"));
		} else
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit(string("失败原因：" + m_sql.error()).c_str()));
		}
	}
	);
	connect(ui.pushButton_recruitment_submit, &QPushButton::clicked,//人力资源-> 招聘 发布
		[=]()mutable
	{
		COUT "发布" LN;
		regex reg_number(str_number);

		if (ui.textBrowser_recruitment_intro->toPlainText().compare("") == 0||
			ui.lineEdit_recruitment_post->text().compare("") == 0 ||
			ui.plainTextEdit_recruitment_post_intro->toPlainText().compare("") == 0 ||
			ui.lineEdit_recruitment_count->text().compare("") == 0 ||
			ui.lineEdit_recruitment_money_start->text().compare("") == 0 ||
			ui.lineEdit_recruitment_money_end->text().compare("") == 0 ||
			ui.lineEdit_recruitment_address->text().compare("") == 0 ||
			ui.plainTextEdit_recruitment_other->toPlainText().compare("") == 0 
			)
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("内容不能为空！").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_recruitment_count->text().toLocal8Bit()), reg_number)==false)//招聘人数
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("招聘人数格式不对！").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_recruitment_money_start->text().toLocal8Bit()), reg_number) == false)//薪资 start
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("薪资格式不对！").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_recruitment_money_end->text().toLocal8Bit()), reg_number) == false)//薪资 end 
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("薪资格式不对！").c_str()));
			return;
		}

		property_tree::ini_parser::read_ini(CONFIG_FILE, pt);

		m_sql.search(
			"SELECT * FROM hr_ecruitment WHERE mechanism_id="+
			APOSTROPHE+pt.get<string>("CurrentMechanismInfo.mechanism_id")+APOSTROPHE+" AND "
			"recruitment_post="+APOSTROPHE+string(ui.lineEdit_recruitment_post->text().toLocal8Bit())+APOSTROPHE+
			";"
		);
		if (m_sql.getRows()==0)
		{
			if (m_sql.query(
				"INSERT INTO hr_ecruitment("
				"mechanism_id,"
				"recruitment_post,"
				"mechanism_introduce,"
				"post_introduce,"
				"recruitment_count,"
				"money_start,"
				"money_end,"
				"work_address,"
				"status,"
				"other,"
				"time)"
				" VALUES(" +
				APOSTROPHE + pt.get<string>("CurrentMechanismInfo.mechanism_id") + APOSTROPHE + "," +
				APOSTROPHE + string(ui.lineEdit_recruitment_post->text().toLocal8Bit()) + APOSTROPHE + "," +
				APOSTROPHE + string(ui.textBrowser_recruitment_intro->toPlainText().toLocal8Bit()) + APOSTROPHE + "," +
				APOSTROPHE + string(ui.plainTextEdit_recruitment_post_intro->toPlainText().toLocal8Bit()) + APOSTROPHE + "," +
				APOSTROPHE + string(ui.lineEdit_recruitment_count->text().toLocal8Bit()) + APOSTROPHE + "," +//
				APOSTROPHE + string(ui.lineEdit_recruitment_money_start->text().toLocal8Bit()) + APOSTROPHE + "," +
				APOSTROPHE + string(ui.lineEdit_recruitment_money_end->text().toLocal8Bit()) + APOSTROPHE + "," +
				APOSTROPHE + string(ui.lineEdit_recruitment_address->text().toLocal8Bit()) + APOSTROPHE + "," +
				APOSTROPHE + string(ui.comboBox_recruitment_status->currentText().toLocal8Bit()) + APOSTROPHE + "," +
				APOSTROPHE + string(ui.plainTextEdit_recruitment_other->toPlainText().toLocal8Bit()) + APOSTROPHE + ","+
				APOSTROPHE + string(QDate::currentDate().toString(Qt::LocalDate).toLocal8Bit()) + APOSTROPHE+
				");"
			))
			{
				QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("发布成功！").c_str()));
			} else
			{
				QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("发布失败！原因：" + m_sql.error()).c_str()));
			}
			
		} else
		{
			if (m_sql.query(
				"UPDATE hr_ecruitment SET "
				"mechanism_introduce="+ APOSTROPHE + string(ui.textBrowser_recruitment_intro->toPlainText().toLocal8Bit()) + APOSTROPHE + "," +
				"post_introduce="+ APOSTROPHE + string(ui.plainTextEdit_recruitment_post_intro->toPlainText().toLocal8Bit()) + APOSTROPHE + "," +
				"recruitment_count="+ APOSTROPHE + string(ui.lineEdit_recruitment_count->text().toLocal8Bit()) + APOSTROPHE + "," +
				"money_start="+ APOSTROPHE + string(ui.lineEdit_recruitment_money_start->text().toLocal8Bit()) + APOSTROPHE + "," +
				"money_end="+ APOSTROPHE + string(ui.lineEdit_recruitment_money_end->text().toLocal8Bit()) + APOSTROPHE + "," +
				"work_address="+ APOSTROPHE + string(ui.lineEdit_recruitment_address->text().toLocal8Bit()) + APOSTROPHE + "," +
				"status="+ APOSTROPHE + string(ui.comboBox_recruitment_status->currentText().toLocal8Bit()) + APOSTROPHE + "," +
				"other="+ APOSTROPHE + string(ui.plainTextEdit_recruitment_other->toPlainText().toLocal8Bit()) + APOSTROPHE+","
				"time="+ APOSTROPHE + string(QDate::currentDate().toString(Qt::LocalDate).toLocal8Bit()) + APOSTROPHE +
				" WHERE mechanism_id="+ APOSTROPHE + pt.get<string>("CurrentMechanismInfo.mechanism_id") + APOSTROPHE + " AND "
				"recruitment_post="+ APOSTROPHE + string(ui.lineEdit_recruitment_post->text().toLocal8Bit()) + APOSTROPHE+";"

			))
			{
				QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("发布成功！").c_str()));
			} else
			{
				QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("发布失败！原因：" + m_sql.error()).c_str()));
			}
		}
	}
		);
	connect(ui.pushButton_del_contract_text, &QPushButton::clicked,//合同管理 -> 新增合同 -> 清除合同内容）
		[=]()mutable
	{
		ui.label_contract_positive->clear();
		ui.label_contract_positive->setText(QString::fromLocal8Bit("正面"));

		ui.label_contract_signature->clear();
		ui.label_contract_signature->setText(QString::fromLocal8Bit("内容（签字面）"));
	}
	);
	connect(ui.pushButton_upload_contract_positive, &QPushButton::clicked,//合同管理 -> 新增合同 -> 上传（正面）
		[=]()mutable
	{
		path_positive = QFileDialog::getOpenFileName(this,
			QString::fromLocal8Bit("打开合同内容"),
			"./",
			"image(*.png *.jpeg *.jpg *.bmp)").toLocal8Bit().toStdString();
		ui.label_contract_positive->setPixmap(QPixmap(QString(path_positive.c_str())));
	}
	);
	connect(ui.pushButton_upload_contract_signature, &QPushButton::clicked,//合同管理 -> 新增合同 -> 上传（签字面）
		[=]()mutable
	{
		path_signature = QFileDialog::getOpenFileName(this,
			QString::fromLocal8Bit("打开合同内容"),
			"./",
			"image(*.png *.jpeg *.jpg *.bmp)").toLocal8Bit().toStdString();
		ui.label_contract_signature->setPixmap(QPixmap(QString(path_signature.c_str())));
	}
	);
	connect(ui.pushButton_add_contract, &QPushButton::clicked,//合同管理 -> 新增合同 -> 新增
		[=]()mutable
	{

		if (ui.lineEdit_addcontract_id->text().compare("") == 0 ||
			ui.lineEdit_addcontract_contractId->text().compare("") == 0||
			ui.lineEdit_addcontract_contractClass->text().compare("") == 0 ||
			ui.lineEdit_addcontract_mechanismId->text().compare("") == 0 ||
			ui.lineEdit_addcontract_mechanismName->text().compare("") == 0 ||
			ui.lineEdit_contract_submitName->text().compare("") == 0 
			)
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("失败！请检查输入是否有空！").c_str()));
			return;
		}

		property_tree::ini_parser::read_ini(CONFIG_FILE, pt);
		if (m_sql.query(
			"INSERT INTO contract_info("
			"mechanism_id,"
			"contract_id,"
			"contract_class_id,"
			"contract_class_name,"
			"add_mechanism_id,"
			"add_mechanism_name,"
			"start,"
			"end,"
			"commit_man,"
			"commit_date,"
			"path_contract_face,"
			"path_contract_text,"
			"is_del,"
			"del_time) "
			"VALUES(" +
			APOSTROPHE + pt.get<string>("CurrentMechanismInfo.mechanism_id") + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_addcontract_id->text().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_addcontract_contractId->text().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_addcontract_contractClass->text().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_addcontract_mechanismId->text().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_addcontract_mechanismName->text().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(QString(ui.dateEdit_contract_start->sectionText(QDateTimeEdit::YearSection) + "-" + ui.dateEdit_contract_start->sectionText(QDateTimeEdit::MonthSection) + "-" + ui.dateEdit_contract_start->sectionText(QDateTimeEdit::DaySection)).toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(QString(ui.dateEdit_contract_end->sectionText(QDateTimeEdit::YearSection) + "-" + ui.dateEdit_contract_end->sectionText(QDateTimeEdit::MonthSection) + "-" + ui.dateEdit_contract_end->sectionText(QDateTimeEdit::DaySection)).toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_contract_submitName->text().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(QString(ui.dateEdit_contract_submit->sectionText(QDateTimeEdit::YearSection) + "-" + ui.dateEdit_contract_submit->sectionText(QDateTimeEdit::MonthSection) + "-" + ui.dateEdit_contract_submit->sectionText(QDateTimeEdit::DaySection)).toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + path_positive + APOSTROPHE + "," +
			APOSTROPHE + path_signature + APOSTROPHE + "," +
			APOSTROPHE + string("否") + APOSTROPHE + "," +
			APOSTROPHE + string("") + APOSTROPHE +
			");"
		))
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("合同添加成功"));
		} else
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit(string("失败原因：" + m_sql.error()).c_str()));
		}

	}
	);
	connect(ui.pushButton_del_all_contract, &QPushButton::clicked,//合同管理 -> 合同查询 -> 删除所有合同
		[=]()mutable
	{
		property_tree::ini_parser::read_ini(CONFIG_FILE, pt);

		int ret = QMessageBox::warning(this, QString::fromLocal8Bit("确认删除？"), QString::fromLocal8Bit("合同即将删除（您可以在删除列表恢复）"), QMessageBox::Ok | QMessageBox::Cancel);
		if (ret == QMessageBox::Ok)
		{
			for (int row = 0; row <= ui.tableWidget_contract->rowCount(); ++row)
			{
				ui.tableWidget_contract->removeRow(0);
			}
			ui.tableWidget_contract->removeRow(0);

			m_sql.search(
				"SELECT contract_id FROM contract_info WHERE mechanism_id=" +
				APOSTROPHE + pt.get<string>("CurrentMechanismInfo.mechanism_id") + APOSTROPHE + ";"
			);
			int rows = m_sql.getRows();
			vector< vector<string> > v_get = m_sql.getRowDatas();
			if (rows)
			{
				for (int i = 0; i < rows; ++i)
				{
					if (!m_sql.query(
						"UPDATE contract_info SET is_del='是',"
						"del_time=" +
						APOSTROPHE + string(QDate::currentDate().toString(Qt::LocalDate).toLocal8Bit()) + APOSTROPHE +
						" WHERE mechanism_id=" +
						APOSTROPHE + pt.get<string>("CurrentMechanismInfo.mechanism_id") + APOSTROPHE + " AND "
						"contract_id=" + APOSTROPHE + v_get[i][0] + APOSTROPHE + ";"
					))
					{
						QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit(string("失败原因：" + m_sql.error()).c_str()));
						break;
					}

				}
			}
		}

	}
	);
	connect(ui.pushButton_del_all_contract_2, &QPushButton::clicked,//合同管理 -> 合同查询 -> 恢复所有合同
		[=]()mutable
	{
		property_tree::ini_parser::read_ini(CONFIG_FILE, pt);

		int ret = QMessageBox::warning(this, QString::fromLocal8Bit("确认恢复？"), QString::fromLocal8Bit("合同即将恢复）"), QMessageBox::Ok | QMessageBox::Cancel);
		if (ret == QMessageBox::Ok)
		{ 
			for (int row = 0; row <= ui.tableWidget_del_contract_2->rowCount(); ++row)
			{
				ui.tableWidget_del_contract_2->removeRow(0);
			}
			ui.tableWidget_del_contract_2->removeRow(0);

			m_sql.search(
				"SELECT contract_id FROM contract_info WHERE mechanism_id=" +
				APOSTROPHE + pt.get<string>("CurrentMechanismInfo.mechanism_id") + APOSTROPHE + ";"
			);
			int rows = m_sql.getRows();
			vector< vector<string> > v_get = m_sql.getRowDatas();
			if (rows)
			{
				for (int i = 0; i < rows; ++i)
				{
					if (!m_sql.query(
						"UPDATE contract_info SET is_del='否',"
						"del_time=" +
						APOSTROPHE + string(QDate::currentDate().toString(Qt::LocalDate).toLocal8Bit()) + APOSTROPHE +
						" WHERE mechanism_id=" +
						APOSTROPHE + pt.get<string>("CurrentMechanismInfo.mechanism_id") + APOSTROPHE + " AND "
						"contract_id=" + APOSTROPHE + v_get[i][0] + APOSTROPHE + ";"
					))
					{
						QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit(string("失败原因：" + m_sql.error()).c_str()));
						break;
					}

				}
			}
		}

	}
	);
	connect(ui.pushButton_fresh, &QPushButton::clicked,//查看 -> 刷新
		[=]()mutable
	{
		freshSeeInfo();
	}
	);
	connect(ui.pushButton_alter_passwd, &QPushButton::clicked,// 设置 -> 修改密码
		[=]()mutable
	{
		COUT "修改密码" LN;

		property_tree::ini_parser::read_ini(CONFIG_FILE, pt);
		m_sql.search(
			"SELECT login_name,login_passwd FROM mechanism_info WHERE mechanism_id="+
			APOSTROPHE+ pt.get<string>("CurrentMechanismInfo.mechanism_id")+APOSTROPHE+";"
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
					"UPDATE mechanism_info SET login_passwd=" +
					APOSTROPHE + string(ui.lineEdit_new_passwd_again->text().toLocal8Bit()) + APOSTROPHE +
					" WHERE login_name=" + APOSTROPHE + login_name + APOSTROPHE +" AND "+
					"mechanism_id="+ APOSTROPHE + pt.get<string>("CurrentMechanismInfo.mechanism_id") + APOSTROPHE + ";"
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
	connect(ui.pushButton_uploadLOGO, &QPushButton::clicked,// 设置 -> 上传LOGO
		[=]()mutable
	{
		COUT "上传logo" LN;

		property_tree::ini_parser::read_ini(CONFIG_FILE, pt);
		string path_headImg = QFileDialog::getOpenFileName(this,
			QString::fromLocal8Bit("上传LOGO"),
			"./",
			"image(*.png *.jpeg *.jpg *.bmp)").toLocal8Bit().toStdString();
		ui.label_headImg->setPixmap(QPixmap(QString(path_headImg.c_str())));

		if (m_sql.query(
			"UPDATE mechanism_info SET path_logo=" + APOSTROPHE + path_headImg + APOSTROPHE + 
			" WHERE mechanism_id=" + APOSTROPHE + pt.get<string>("CurrentMechanismInfo.mechanism_id") + APOSTROPHE + ";"
		))
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示！"), QString::fromLocal8Bit(string("LOGO上传成功！下次登录时便可显示！").c_str()));
		} else
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示！"), QString::fromLocal8Bit(string("上传失败！原因：" + m_sql.error()).c_str()));
		}


	}
	);
}

void MechanismInfoPanel::showMechanismInfo()
{
	property_tree::ini_parser::read_ini(CONFIG_FILE, pt);
	m_sql.search(
		"SELECT * FROM mechanism_info WHERE login_name=" +
		APOSTROPHE + pt.get<string>("CurrentMechanismInfo.login_name") + APOSTROPHE + ";"
	);
	if (m_sql.getRows() != 0)
	{
		if (m_sql.getRowDatas()[0][18].compare("") != 0)
		{
			QImage img;
			img.load(QString::fromLocal8Bit(m_sql.getRowDatas()[0][18].c_str()));
			ui.label_name_logo_2->setPixmap(QPixmap::fromImage(img));
		} else
		{
			ui.label_name_logo_2->setText(QString::fromLocal8Bit("LOGO HEER"));
		}

		ui.lineEdit_team_name_2->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][0].c_str()));
		ui.lineEdit_team_name_3->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][1].c_str()));
		ui.plainTextEdit->setPlainText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][2].c_str()));
		ui.lineEdit_team_name_4->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][3].c_str()));
		ui.lineEdit_team_name_5->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][4].c_str()));
		ui.lineEdit_team_name_6->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][5].c_str()));
		ui.lineEdit_team_name_7->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][6].c_str()));
		ui.lineEdit_team_name_8->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][7].c_str()));
		ui.lineEdit_team_name_9->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][8].c_str()));
		ui.lineEdit_team_name_10->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][9].c_str()));
		//机构证书
		if (m_sql.getRowDatas()[0][10].compare("") != 0)
		{
			QImage img;
			img.load(QString::fromLocal8Bit(m_sql.getRowDatas()[0][10].c_str()));
			ui.label_5->setPixmap(QPixmap::fromImage(img));
		} else
		{
			ui.label_5->setText(QString::fromLocal8Bit("未上传"));
		}
		ui.plainTextEdit_2->setPlainText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][17].c_str()));
	}
}

void MechanismInfoPanel::showHR()
{
	ui.stackedWidget_3->setCurrentIndex(0);
	//显示数据表
	m_sql.search(
		"SELECT * FROM HR_emp_info WHERE mechanism_id=" +
		APOSTROPHE + pt.get<string>("CurrentMechanismInfo.mechanism_id") + APOSTROPHE + ";"
	);
	ui.tableWidget_HR->setRowCount(m_sql.getRows());
	for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
	{
		for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
		{
			ui.tableWidget_HR->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
		}
	}

	property_tree::ini_parser::read_ini(CONFIG_FILE, pt);
	m_sql.search(
		"SELECT * FROM mechanism_info WHERE login_name=" +
		APOSTROPHE + pt.get<string>("CurrentMechanismInfo.login_name") + APOSTROPHE + ";"
	);
	if (m_sql.getRows())
	{
		ui.label_HR_team_count->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][11].c_str()));
		ui.label_HR_accounting_male->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][12].c_str()));
		ui.label_HR_accounting_female->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][13].c_str()));
		ui.label_undergraduate_course->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][14].c_str()));
		ui.label_non_undergraduate_course->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][15].c_str()));
		ui.label_HR_master->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][16].c_str()));
	}
}

void MechanismInfoPanel::showContractManager()
{
}

void MechanismInfoPanel::showSee()
{
}

void MechanismInfoPanel::showSet()
{
}

void MechanismInfoPanel::freshSeeInfo()
{
	ui.listWidget_see->clear();

	property_tree::ini_parser::read_ini(CONFIG_FILE, pt);

	//绩效考核表
	m_sql.search(
		"SELECT * FROM pa_level_result WHERE mechanism_id=" +
		APOSTROPHE + pt.get<string>("CurrentMechanismInfo.mechanism_id") + APOSTROPHE + ";"
	);
	COUT m_sql.error() LN;
	if (m_sql.getRows())
	{
		if (m_sql.getRowDatas()[0][2].compare("non") == 0
			)
		{
			ui.listWidget_see->addItem(QString::fromLocal8Bit(string(
				"您收到一张(绩效考核表),请认真填写！[" + m_sql.getRowDatas()[0][3] + "]"
			).c_str()
			));
		} else
		{
			ui.listWidget_see->addItem(QString::fromLocal8Bit(string(
				"您的绩效结果已出炉！点击查看(绩效考核结果)[" + m_sql.getRowDatas()[0][3] + "]"
			).c_str()
			));
		}

	}

	//查看信息反馈
	m_sql.search(
		"SELECT feedback_time,is_write FROM mechanism_feedback WHERE mechanism_id=" +
		APOSTROPHE + string(ui.lineEdit_team_name_2->text().toLocal8Bit()) + APOSTROPHE + ";"
	);
	if (m_sql.getRows())
	{
		if (m_sql.getRowDatas()[0][1].compare("是") == 0)//说明信息反馈管理员已经接收了
		{
			ui.listWidget_see->addItem(QString::fromLocal8Bit(string(
				"您于[" + m_sql.getRowDatas()[0][0] + "]发布的信息反馈管理员已接收！"
			).c_str()
			));
		}
	}

	//招聘信息
	m_sql.search(
		"SELECT * FROM hr_ecruitment WHERE mechanism_id=" +
		APOSTROPHE + string(ui.lineEdit_team_name_2->text().toLocal8Bit()) + APOSTROPHE + ";"
	);
	if (m_sql.getRows())
	{
		ui.listWidget_see->addItem(QString::fromLocal8Bit(string(
			"(招聘信息)已发布！双击查看["+ string(QDate::currentDate().toString(Qt::LocalDate).toLocal8Bit())+"]"
		).c_str()
		));
	}
}

void MechanismInfoPanel::findEmpInfoFromTable(string & str, QTableWidget * widget)
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
