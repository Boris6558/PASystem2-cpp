#include "HelpMeDecision.h"

#include <QTimer>
#include <QMessageBox>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidgetItem>

HelpMeDecision::HelpMeDecision(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	initMembers();
	connectMembers();
}

HelpMeDecision::~HelpMeDecision()
{
}

void HelpMeDecision::initMembers()
{
	setWindowTitle(QString::fromLocal8Bit("��������"));

	m_sql.init();

	ui.stackedWidget->setCurrentWidget(ui.page_wait);

	//����
	QPalette pal = palette();
	pal.setBrush(QPalette::Background, QBrush(QPixmap(PATH_IMG(dialog_back.jpg))));
	setPalette(pal);
}

void HelpMeDecision::connectMembers()
{
	/**************** QTimer *******************/
	QTimer::singleShot(5000, this,//ϵͳ���æ���� 5����ʱ��ϵͳ����
		[=]()mutable
	{
		int ret = QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit(string("�����ɹ����Ƿ����ڴ򿪲鿴").c_str()), QMessageBox::Ok | QMessageBox::Cancel);
		if (ret == QMessageBox::Ok)
		{
			ui.stackedWidget->setCurrentWidget(ui.page_main);

			//�����ݿ��ȡ���ݵ����  ��ȡ�������(ȫ��)
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.result_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='��' ORDER BY b.result_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}

		} else
		{
			close();
		}

	}
	);

	/**************** QComboBox *******************/
	void (QComboBox::*p_currentTextChanged)(const QString &) = &QComboBox::currentTextChanged;
	connect(ui.comboBox_reference, p_currentTextChanged,
		[=](const QString &text)mutable
	{
		//����ѡ��ͬ����ʾ��ͬ���������
		if (text.compare(QString::fromLocal8Bit("�ۺ�����(Ĭ��)")) == 0)
		{
			//ɾ��������
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}

			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.result_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='��' ORDER BY b.result_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}

		} else if (text.compare(QString::fromLocal8Bit("Ͷ����")) == 0)
		{
			//ɾ��������
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.complaints_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='��' ORDER BY b.complaints_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("�����淶��")) == 0)
		{
			//ɾ��������
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.norm_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='��' ORDER BY b.norm_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("���Ŵ���Ч��")) == 0)
		{
			//ɾ��������
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.loan_efficiency_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='��' ORDER BY b.loan_efficiency_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("�鼯������")) == 0)
		{
			//ɾ��������
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.muster_error_rate_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='��' ORDER BY b.muster_error_rate_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("���������")) == 0)
		{
			//ɾ��������
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.loan_error_rate_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='��' ORDER BY b.loan_error_rate_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("�鼯�ʽ�����")) == 0)
		{
			//ɾ��������
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.get_muster_rate_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='��' ORDER BY b.get_muster_rate_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("�����ʽ�����")) == 0)
		{
			//ɾ��������
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.get_loan_rate_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='��' ORDER BY b.get_loan_rate_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("����ɴ������")) == 0)
		{
			//ɾ��������
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.net_save_error_rate_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='��' ORDER BY b.net_save_error_rate_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("������ȡ������")) == 0)
		{
			//ɾ��������
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.net_get_error_rate_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='��' ORDER BY b.net_get_error_rate_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("������������")) == 0)
		{
			//ɾ��������
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.net_loan_error_rata_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='��' ORDER BY b.net_loan_error_rata_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("���绹�������")) == 0)
		{
			//ɾ��������
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.net_return_error_rate_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='��' ORDER BY b.net_return_error_rate_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("�������ڳ�����")) == 0)
		{
			//ɾ��������
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.net_over_error_rate_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='��' ORDER BY b.net_over_error_rate_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("���縺ʱЧ����")) == 0)
		{
			//ɾ��������
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.net_time_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='��' ORDER BY b.net_time_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		}
	}
	);

	/**************** QLineEdit *******************/
	connect(ui.lineEdit_search, &QLineEdit::textChanged,//�������
		[=](const QString &text)mutable
	{
		findEmpInfoFromTable(string(text.toLocal8Bit()));
	}
	);
	connect(ui.lineEdit_id, &QLineEdit::textChanged,//�޸Ļ������
		[=](const QString &text)mutable
	{
		findEmpInfoFromTable(string(text.toLocal8Bit()));
	}
	);

	/**************** QPushButton *******************/
	connect(ui.pushButton_fresh, &QPushButton::clicked,//ˢ������
		[=]()mutable
	{
		COUT "ˢ������" LN;
		ui.comboBox_reference->setCurrentIndex(0);
		ui.lineEdit_id->setText("");

		//ɾ��������
		for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
		{
			ui.tableWidget->removeRow(0);
		}

		m_sql.search(
			"SELECT a.mechanism_id,a.mechanism_name,b.result_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='��' ORDER BY b.result_level;"
		);
		ui.tableWidget->setRowCount(m_sql.getRows());
		for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
		{
			for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
			{
				ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
			}
		}
	}
	);
	connect(ui.pushButton_alter, &QPushButton::clicked,//�޸�
		[=]()mutable
	{
		m_sql.search(
			"SELECT * FROM pa_each_level WHERE mechanism_id=" + APOSTROPHE + string(ui.lineEdit_id->text().toLocal8Bit()) + APOSTROPHE + ";"
		);
		if (m_sql.getRows() != 0)//�ҵõ�
		{
			if (m_sql.query(
				"UPDATE pa_each_level SET "
				"result_level=" + APOSTROPHE + string(ui.comboBox_levelAlter->currentText().toLocal8Bit()) + APOSTROPHE +
				" WHERE mechanism_id=" + APOSTROPHE + string(ui.lineEdit_id->text().toLocal8Bit()) + APOSTROPHE + ";"
			))
			{
				QMessageBox::information(this, QString::fromLocal8Bit("�ɹ�"), QString::fromLocal8Bit(string("�޸ĳɹ�����ˢ�±��鿴�½����").c_str()));
			} else
			{
				QMessageBox::information(this, QString::fromLocal8Bit("ʧ��"), QString::fromLocal8Bit(string("����ʧ�ܣ�ԭ��" + m_sql.error()).c_str()));

			}

		} else
		{
			QMessageBox::information(this, QString::fromLocal8Bit("ʧ��"), QString::fromLocal8Bit(string("�Ҳ����˻�����").c_str()));
		}

	}
	);
	connect(ui.pushButton_commit, &QPushButton::clicked,//���ô˾����������
		[=]()mutable
	{
		COUT "���ô˾����������" LN;
		//��ñ������Ա����id 
		for (int i = 0; i < ui.tableWidget->rowCount(); ++i)
		{
			//COUT string(ui.tableWidget->item(i, 0)->text().toLocal8Bit()) LK "-";

			//������ʾ�Ѿ���д��Ч���˱��Ա���ļ�Ч����
			if (m_sql.query(
				"UPDATE pa_level_result SET result_level=" + APOSTROPHE + string(ui.tableWidget->item(i, 2)->text().toLocal8Bit()) + APOSTROPHE +
				" WHERE mechanism_id=" + APOSTROPHE + string(ui.tableWidget->item(i, 0)->text().toLocal8Bit()) + APOSTROPHE + ";"
			))
			{
				QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit(string("�ɹ�ʹ�øþ��ߣ�").c_str()));
			} else
			{
				QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit(string("ʹ�øþ���ʧ�ܣ�ʧ��ԭ�򣺣�" + m_sql.error()).c_str()));
			}

		}



	}
	);

}

void HelpMeDecision::findEmpInfoFromTable(string & str)
{
	if (ui.tableWidget == Q_NULLPTR)
	{
		return;
	}

	QList<QTableWidgetItem*> findItems = ui.tableWidget->findItems(QString::fromLocal8Bit(str.c_str()), Qt::MatchContains);
	bool b_row_hide = true;
	for (int i = 0; i < ui.tableWidget->rowCount(); ++i)
	{
		b_row_hide = true;
		foreach(QTableWidgetItem* item, findItems)
		{
			if (Q_NULLPTR == item) continue;
			if (ui.tableWidget->row(item) == i)
			{
				b_row_hide = false;
				break;
			}
		}
		ui.tableWidget->setRowHidden(i, b_row_hide);
	}
}
