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
	setWindowTitle(QString::fromLocal8Bit("��̨����"));

	m_sql.init();

	ui.stackedWidget->setCurrentWidget(ui.page);

	ui.tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);//�Ҽ��˵�  ��ɾ���ĺ�ͬ

	m_detail = new QAction(QString::fromLocal8Bit("����"), ui.tableWidget);
	m_pa = new QAction(QString::fromLocal8Bit("����Ч����"), ui.tableWidget);
	m_revoke = new QAction(QString::fromLocal8Bit("��������"), ui.tableWidget);

	//����
	QPalette pal = palette();
	pal.setBrush(QPalette::Background, QBrush(QPixmap(PATH_IMG(manager_back.jpg))));
	setPalette(pal);

}

void BackManagerPanel::connectMembers()
{
	/******************** QTableWidget ************************/
	void (QTableWidget::*p_cellClicked)(int, int) = &QTableWidget::cellClicked;
	connect(ui.tableWidget, p_cellClicked,//���һ��
		[=](int row, int col)mutable
	{
		c_row = row;
		COUT "��ǰѡ��� " LK c_row LK "��" LN;
		c_mechanism_id = string(ui.tableWidget->item(row, 0)->text().toLocal8Bit());
		c_mechanism_name = string(ui.tableWidget->item(row, 1)->text().toLocal8Bit());
		COUT "��һ�л������ :" LK c_mechanism_id LK " ���ƣ�" LK c_mechanism_name LN;

	}
	);
	connect(ui.tableWidget, &QTableWidget::customContextMenuRequested,//�Ҽ� ��ͬ
		[=](const QPoint &posAtViewport)mutable
	{
		QMenu menu;

		// [4] ��ȡ�Ҽ��˵���������Ľڵ� (QTableView, QListView ��Ҳ������ô��)
		QModelIndex index = ui.tableWidget->indexAt(posAtViewport);

		// [5] ���ݽڵ���ص㶯̬��ʾ�˵����������Ľڵ�ʱ����ʾɾ���˵���
		if (index.isValid())
		{
			//�˵��Ҽ�����
			menu.addAction(m_detail);
			menu.addAction(m_pa);
			//menu.addAction(m_revoke);//����
		} else
		{
			//�������Ҽ�����
		}

		menu.exec(QCursor::pos());
	}
	);

	/********************* QAction *************************/
	connect(m_detail, &QAction::triggered,//����
		[=]()mutable
	{
		COUT c_row LK " �����ݣ���ţ�" LK c_mechanism_id LK " ���ƣ�" LK c_mechanism_name LK "������" LN;
		POINTER_INS(m_md, MechanismDetail(c_mechanism_id));
		m_md->show();
		SET_NULL(m_md);
	}
	);
	connect(m_pa, &QAction::triggered,//����Ч����
		[=]()mutable
	{
		
		POINTER_INS(m_pa_type, PAType);
		m_pa_type->show();

		/************************ PAType *******************************/
		connect(m_pa_type, &PAType::sigSendPATable,
			[=](const QString &text)mutable
		{
			COUT c_row LK " �����ݣ���ţ�" LK c_mechanism_id LK " ���ƣ�" LK c_mechanism_name LK "�ļ�Ч����" LN;

			property_tree::ini_parser::read_ini(CONFIG_FILE, pt);
			pt.put<string>("CurrentMechanismInfo.pa_type", string(text.toLocal8Bit()));
			property_tree::ini_parser::write_ini(CONFIG_FILE, pt);

			m_sql.search(
				"SELECT * FROM pa_level_result WHERE mechanism_id=" + APOSTROPHE + c_mechanism_id + APOSTROPHE + ";"
			);
			if (m_sql.getRows() == 0)//����Ҳ������Ͳ���
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
					APOSTROPHE + string("��") + APOSTROPHE + "," +
					APOSTROPHE + string(pt.get<string>("CurrentMechanismInfo.pa_type")) + APOSTROPHE +
					");"
				))
				{
					QMessageBox::warning(this, QString::fromLocal8Bit("�ɹ�"), QString::fromLocal8Bit(string("������Ϊ��" + c_mechanism_id + "����Ч���˱�").c_str()));
				} else
				{
					QMessageBox::warning(this, QString::fromLocal8Bit("ʧ��"), QString::fromLocal8Bit(string("����ʧ�ܣ�ԭ��" + m_sql.error()).c_str()));
				}

			} else//�޸Ĳ�����������д���˱�
			{
				if (m_sql.query(
					"UPDATE pa_level_result SET result_level='non',is_write='��',type=" +
					APOSTROPHE + string(pt.get<string>("CurrentMechanismInfo.pa_type")) + APOSTROPHE +
					" WHERE mechanism_id=" +
					APOSTROPHE + c_mechanism_id + APOSTROPHE + ";"
				))
				{
					QMessageBox::warning(this, QString::fromLocal8Bit("�ɹ�"), QString::fromLocal8Bit(string("������Ϊ��" + c_mechanism_id + "����Ч���˱�").c_str()));
				} else
				{
					QMessageBox::warning(this, QString::fromLocal8Bit("ʧ��"), QString::fromLocal8Bit(string("����ʧ�ܣ�ԭ��" + m_sql.error()).c_str()));
				}
			}
			m_pa_type->close();
			SET_NULL(m_pa_type);
		}
		);

	}
	);
	connect(m_revoke, &QAction::triggered,//����
		[=]()mutable
	{
		COUT c_row LK " �����ݣ���ţ�" LK c_mechanism_id LK " ���ƣ�" LK c_mechanism_name LK "�� ����" LN;

	}
	);

	/******************** QListWidget ************************/
	void (QListWidget::*p_currentTextChanged)(const QString &) = &QListWidget::currentTextChanged;
	connect(ui.listWidget, p_currentTextChanged,  //�л����
		[=](const QString &text)mutable
	{
		if (text.compare(QString::fromLocal8Bit("������Ϣ")) == 0)
		{
			ui.stackedWidget->setCurrentWidget(ui.page);

			//��ʾ���ݱ�
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

		} else if (text.compare(QString::fromLocal8Bit("��Ч����")) == 0)
		{
			ui.stackedWidget->setCurrentWidget(ui.page_2);

			//��ʾ���ݱ�
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

		} else if (text.compare(QString::fromLocal8Bit("�鿴")) == 0)
		{
			ui.stackedWidget->setCurrentWidget(ui.page_3);
			freshSeeInfo();

		} else if (text.compare(QString::fromLocal8Bit("����")) == 0)
		{
			ui.stackedWidget->setCurrentWidget(ui.page_4);
		}
	}
	);
	connect(ui.listWidget_see, &QListWidget::itemDoubleClicked,//�鿴��Ϣ
		[=](QListWidgetItem *item)mutable
	{
		//�鿴�ĸ�����������
		string id = string(item->text().toLocal8Bit()).substr(
			string(item->text().toLocal8Bit()).find("(") + 1, string(item->text().toLocal8Bit()).find(")") - string(item->text().toLocal8Bit()).find("(") - 1
		);
		//������ʲô����
		string call_type = string(item->text().toLocal8Bit()).substr(
			string(item->text().toLocal8Bit()).find("{") + 1, string(item->text().toLocal8Bit()).find("}") - string(item->text().toLocal8Bit()).find("{") - 1
		);
		COUT "����" LK id LK "���������ǣ�" LK call_type LN;

		if (call_type.compare("������Ϣ") == 0)//��Ա���������ڲ鿴
		{
			POINTER_INS(m_sfb, SeeFeedBack(id));
			m_sfb->show();
			SET_NULL(m_sfb);
		}

	}
	);

	/********************* QLineEdit *************************/
	connect(ui.lineEdit_search, &QLineEdit::textChanged,//������Ϣ ->��ѯ
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
	connect(ui.pushButton_performanceAll, &QPushButton::clicked,//��ȫ�巢��Ч����
		[=]()mutable
	{
		POINTER_INS(m_pa_type, PAType);
		m_pa_type->show();

		/************************ PAType *******************************/
		connect(m_pa_type, &PAType::sigSendPATable,
			[=](const QString &text)mutable
		{
			COUT "ȫ�巢��" LN;

			property_tree::ini_parser::read_ini(CONFIG_FILE, pt);
			pt.put<string>("CurrentMechanismInfo.pa_type", string(text.toLocal8Bit()));
			property_tree::ini_parser::write_ini(CONFIG_FILE, pt);

			v_all_id.clear();
			v_all_name.clear();

			m_sql.search(
				"SELECT * FROM mechanism_info;"
			);
			if (m_sql.getRows()!=0)//˵����ע��Ļ���
			{
				//������л����ı��
				for (int i=0;i<m_sql.getRows();++i)
				{
					push_back(v_all_id)(m_sql.getRowDatas()[i][0]);
					push_back(v_all_name)(m_sql.getRowDatas()[i][1]);
				}
			}

			//Ϊÿ��Ա����ӿ��˱�
			for (int i=0;i<v_all_id.size();++i)
			{
				m_sql.search(
					"SELECT * FROM pa_level_result WHERE mechanism_id=" + APOSTROPHE + v_all_id[i] + APOSTROPHE+";"
				);
				if (m_sql.getRows() == 0)//��û�����
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
						APOSTROPHE + string("��") + APOSTROPHE + "," +
						APOSTROPHE + string(text.toLocal8Bit()) + APOSTROPHE+
						");"
					))
					{
						//QMessageBox::warning(this, QString::fromLocal8Bit("�ɹ���"), QString::fromLocal8Bit(string("�����Ա�����ͼ�Ч����!").c_str()));
					} else
					{
						QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit(string("���ͼ�Ч����ʧ�ܣ���" + m_sql.error()).c_str()));
					}


				} else//�޸ļ�Ч���λNon
				{
					if (m_sql.query(
						"UPDATE pa_level_result SET result_level='non',date=" +
						APOSTROPHE + string(QDate::currentDate().toString(Qt::LocalDate).toLocal8Bit()) + APOSTROPHE + "," +
						"is_write="+ APOSTROPHE + string("��") + APOSTROPHE + "," +
						"type=" + APOSTROPHE + string(text.toLocal8Bit()) + APOSTROPHE +
						" WHERE mechanism_id="+ APOSTROPHE + v_all_id[i] + APOSTROPHE+";"
					))
					{
						//QMessageBox::warning(this, QString::fromLocal8Bit("�ɹ���"), QString::fromLocal8Bit(string("�����Ա�����ͼ�Ч����!").c_str()));
					} else
					{
						QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit(string("���ͼ�Ч����ʧ�ܣ���" + m_sql.error()).c_str()));
					}
				}
			}

			QMessageBox::warning(this, QString::fromLocal8Bit("�ɹ���"), QString::fromLocal8Bit(string("ȫ�巢�ͳɹ�!").c_str()));

			//end
			m_pa_type->close();
			SET_NULL(m_pa_type);
		}
		);
	}
	);
	connect(ui.pushButton_performance_rules, &QPushButton::clicked,//��Ч����ָ�꼰������ʽ��
		[=]()mutable
	{
		POINTER_INS(m_table, PATable);
		m_table->show();
		SET_NULL(m_table);
	}
	);
	connect(ui.pushButton_see_performanceResult, &QPushButton::clicked,//�鿴��Ч���
		[=]()mutable
	{
		POINTER_INS(m_result, PAResult);
		m_result->show();
		SET_NULL(m_result);
	}
	);
	connect(ui.pushButton_help_me_decision_level, &QPushButton::clicked,//���Ҿ��߼�Ч����
		[=]()mutable
	{
		POINTER_INS(m_hmd, HelpMeDecision);
		m_hmd->show();
		SET_NULL(m_hmd);
	}
	);
	connect(ui.pushButton_alter_passwd, &QPushButton::clicked,// ���� -> �޸�����
		[=]()mutable
	{
		COUT "�޸�����" LN;

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
				QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ��"), QString::fromLocal8Bit(string("���벻��Ϊ�գ�").c_str()));
				return;
			}
			if (string(ui.lineEdit_new_passwd->text().toLocal8Bit()).compare(string(ui.lineEdit_new_passwd_again->text().toLocal8Bit())) == 0)
			{
				COUT "�޸�����" LN;

				if (m_sql.query(
					"UPDATE admin_acc SET login_passwd=" +
					APOSTROPHE + string(ui.lineEdit_new_passwd_again->text().toLocal8Bit()) + APOSTROPHE +
					" WHERE login_name=" + APOSTROPHE + login_name + APOSTROPHE + ";"
				))
				{
					QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ��"), QString::fromLocal8Bit(string("���ĳɹ�����").c_str()));
				} else
				{
					QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ��"), QString::fromLocal8Bit(string("����ʧ�ܣ�ԭ��" + m_sql.error()).c_str()));
				}


			} else
			{
				QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ��"), QString::fromLocal8Bit(string("�����벻һ�£�").c_str()));
			}

		} else
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ��"), QString::fromLocal8Bit(string("�����벻ƥ�䣡").c_str()));
		}

	}
	);


}

void BackManagerPanel::freshSeeInfo()
{
	ui.listWidget_see->clear();

	//��Ϣ����
	m_sql.search(
		"SELECT * FROM mechanism_feedback WHERE is_write='��';"
	);
	for (int row = 0; row < m_sql.getRows(); ++row)
	{
		ui.listWidget_see->addItem(QString::fromLocal8Bit(string(
			"�յ�һ�����Ի�����(" + m_sql.getRowDatas()[row][0] + ")" + " ��{������Ϣ}����鿴�� " + "[" + m_sql.getRowDatas()[row][5] + "]"
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
