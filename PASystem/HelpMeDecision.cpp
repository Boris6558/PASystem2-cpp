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
	setWindowTitle(QString::fromLocal8Bit("辅助决策"));

	m_sql.init();

	ui.stackedWidget->setCurrentWidget(ui.page_wait);

	//背景
	QPalette pal = palette();
	pal.setBrush(QPalette::Background, QBrush(QPixmap(PATH_IMG(dialog_back.jpg))));
	setPalette(pal);
}

void HelpMeDecision::connectMembers()
{
	/**************** QTimer *******************/
	QTimer::singleShot(5000, this,//系统帮帮忙决策 5秒后的时间系统分析
		[=]()mutable
	{
		int ret = QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("分析成功！是否现在打开查看").c_str()), QMessageBox::Ok | QMessageBox::Cancel);
		if (ret == QMessageBox::Ok)
		{
			ui.stackedWidget->setCurrentWidget(ui.page_main);

			//从数据库读取数据到表格  读取评级结果(全部)
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.result_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='是' ORDER BY b.result_level;"
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
		//根据选择不同，显示不同的评级结果
		if (text.compare(QString::fromLocal8Bit("综合整体(默认)")) == 0)
		{
			//删除所有行
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}

			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.result_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='是' ORDER BY b.result_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}

		} else if (text.compare(QString::fromLocal8Bit("投诉率")) == 0)
		{
			//删除所有行
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.complaints_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='是' ORDER BY b.complaints_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("手续规范率")) == 0)
		{
			//删除所有行
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.norm_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='是' ORDER BY b.norm_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("发放贷款效率")) == 0)
		{
			//删除所有行
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.loan_efficiency_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='是' ORDER BY b.loan_efficiency_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("归集出错率")) == 0)
		{
			//删除所有行
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.muster_error_rate_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='是' ORDER BY b.muster_error_rate_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("贷款出错率")) == 0)
		{
			//删除所有行
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.loan_error_rate_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='是' ORDER BY b.loan_error_rate_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("归集资金到账率")) == 0)
		{
			//删除所有行
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.get_muster_rate_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='是' ORDER BY b.get_muster_rate_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("贷款资金到账率")) == 0)
		{
			//删除所有行
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.get_loan_rate_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='是' ORDER BY b.get_loan_rate_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("网络缴存出错率")) == 0)
		{
			//删除所有行
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.net_save_error_rate_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='是' ORDER BY b.net_save_error_rate_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("网络提取出错率")) == 0)
		{
			//删除所有行
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.net_get_error_rate_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='是' ORDER BY b.net_get_error_rate_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("网络贷款出错率")) == 0)
		{
			//删除所有行
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.net_loan_error_rata_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='是' ORDER BY b.net_loan_error_rata_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("网络还款出错率")) == 0)
		{
			//删除所有行
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.net_return_error_rate_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='是' ORDER BY b.net_return_error_rate_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("网络逾期出错率")) == 0)
		{
			//删除所有行
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.net_over_error_rate_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='是' ORDER BY b.net_over_error_rate_level;"
			);
			ui.tableWidget->setRowCount(m_sql.getRows());
			for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
			{
				for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
				{
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
				}
			}
		} else if (text.compare(QString::fromLocal8Bit("网络负时效概率")) == 0)
		{
			//删除所有行
			for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
			{
				ui.tableWidget->removeRow(0);
			}
			m_sql.search(
				"SELECT a.mechanism_id,a.mechanism_name,b.net_time_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='是' ORDER BY b.net_time_level;"
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
	connect(ui.lineEdit_search, &QLineEdit::textChanged,//搜索表格
		[=](const QString &text)mutable
	{
		findEmpInfoFromTable(string(text.toLocal8Bit()));
	}
	);
	connect(ui.lineEdit_id, &QLineEdit::textChanged,//修改机构编号
		[=](const QString &text)mutable
	{
		findEmpInfoFromTable(string(text.toLocal8Bit()));
	}
	);

	/**************** QPushButton *******************/
	connect(ui.pushButton_fresh, &QPushButton::clicked,//刷新数据
		[=]()mutable
	{
		COUT "刷新数据" LN;
		ui.comboBox_reference->setCurrentIndex(0);
		ui.lineEdit_id->setText("");

		//删除所有行
		for (int row = 0; row < ui.tableWidget->rowCount(); ++row)
		{
			ui.tableWidget->removeRow(0);
		}

		m_sql.search(
			"SELECT a.mechanism_id,a.mechanism_name,b.result_level,a.date,a.type FROM pa_level_result AS a,pa_each_level AS b WHERE a.mechanism_id=b.mechanism_id AND a.is_write='是' ORDER BY b.result_level;"
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
	connect(ui.pushButton_alter, &QPushButton::clicked,//修改
		[=]()mutable
	{
		m_sql.search(
			"SELECT * FROM pa_each_level WHERE mechanism_id=" + APOSTROPHE + string(ui.lineEdit_id->text().toLocal8Bit()) + APOSTROPHE + ";"
		);
		if (m_sql.getRows() != 0)//找得到
		{
			if (m_sql.query(
				"UPDATE pa_each_level SET "
				"result_level=" + APOSTROPHE + string(ui.comboBox_levelAlter->currentText().toLocal8Bit()) + APOSTROPHE +
				" WHERE mechanism_id=" + APOSTROPHE + string(ui.lineEdit_id->text().toLocal8Bit()) + APOSTROPHE + ";"
			))
			{
				QMessageBox::information(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit(string("修改成功！请刷新表格查看新结果！").c_str()));
			} else
			{
				QMessageBox::information(this, QString::fromLocal8Bit("失败"), QString::fromLocal8Bit(string("插入失败！原因" + m_sql.error()).c_str()));

			}

		} else
		{
			QMessageBox::information(this, QString::fromLocal8Bit("失败"), QString::fromLocal8Bit(string("找不到此机构！").c_str()));
		}

	}
	);
	connect(ui.pushButton_commit, &QPushButton::clicked,//采用此决策评级结果
		[=]()mutable
	{
		COUT "采用此决策评级结果" LN;
		//获得表格所有员工的id 
		for (int i = 0; i < ui.tableWidget->rowCount(); ++i)
		{
			//COUT string(ui.tableWidget->item(i, 0)->text().toLocal8Bit()) LK "-";

			//更新显示已经填写绩效考核表的员工的绩效评级
			if (m_sql.query(
				"UPDATE pa_level_result SET result_level=" + APOSTROPHE + string(ui.tableWidget->item(i, 2)->text().toLocal8Bit()) + APOSTROPHE +
				" WHERE mechanism_id=" + APOSTROPHE + string(ui.tableWidget->item(i, 0)->text().toLocal8Bit()) + APOSTROPHE + ";"
			))
			{
				QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("成功使用该决策！").c_str()));
			} else
			{
				QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("使用该决策失败！失败原因：！" + m_sql.error()).c_str()));
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
