#include "PAResult.h"

#include <QTableWidgetItem>
#include <QList>

PAResult::PAResult(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	initMembers();
	connectMembers();

}

PAResult::PAResult(string mark, QWidget * parent) : QWidget(parent)
{
	ui.setupUi(this);

	setWindowTitle(QString::fromLocal8Bit("绩效结果"));

	m_sql.init();

	//记载数据
	m_sql.search("SELECT * FROM pa_level_result WHERE is_write='是' ORDER BY result_level;");
	ui.tableWidget_level->setRowCount(m_sql.getRows());
	for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
	{
		for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
		{
			ui.tableWidget_level->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
		}
	}

	connectMembers();

	//背景
	QPalette pal = palette();
	pal.setBrush(QPalette::Background, QBrush(QPixmap(PATH_IMG(dialog_back.jpg))));
	setPalette(pal);
}

PAResult::~PAResult()
{
}

void PAResult::initMembers()
{
	setWindowTitle(QString::fromLocal8Bit("绩效结果"));

	m_sql.init();

	//记载数据
	m_sql.search("SELECT * FROM pa_level_result ORDER BY result_level;");
	ui.tableWidget_level->setRowCount(m_sql.getRows());
	for (int i = 0; i < m_sql.getRowDatas().size(); ++i)
	{
		for (int j = 0; j < m_sql.getRowDatas()[i].size(); ++j)
		{
			ui.tableWidget_level->setItem(i, j, new QTableWidgetItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][j].c_str())));
		}
	}

	//背景
	QPalette pal = palette();
	pal.setBrush(QPalette::Background, QBrush(QPixmap(PATH_IMG(dialog_back.jpg))));
	setPalette(pal);
}

void PAResult::connectMembers()
{
	/***********************  QLineEdit ****************************/
	connect(ui.lineEdit_search, &QLineEdit::textChanged,//搜索表格
		[=](const QString &text)mutable
	{
		findEmpInfoFromTable(string(text.toLocal8Bit()));
	}
	);
}

void PAResult::findEmpInfoFromTable(string & str)
{
	if (ui.tableWidget_level == Q_NULLPTR)
	{
		return;
	}

	QList<QTableWidgetItem*> findItems = ui.tableWidget_level->findItems(QString::fromLocal8Bit(str.c_str()), Qt::MatchContains);
	bool b_row_hide = true;
	for (int i = 0; i < ui.tableWidget_level->rowCount(); ++i)
	{
		b_row_hide = true;
		foreach(QTableWidgetItem* item, findItems)
		{
			if (Q_NULLPTR == item) continue;
			if (ui.tableWidget_level->row(item) == i)
			{
				b_row_hide = false;
				break;
			}
		}
		ui.tableWidget_level->setRowHidden(i, b_row_hide);
	}
}
