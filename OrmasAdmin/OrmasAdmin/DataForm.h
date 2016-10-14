#ifndef DATAFORM_H
#define DATAFORM_H

#include "ui_DataForm.h"
#include "OrmasBL.h"
#include <QStandardItem>

class DataForm : public QWidget, public Ui::DataForm
{
	Q_OBJECT
public:
	DataForm(QWidget *parent = 0);
	~DataForm(){};
	
	template<class T>
	void FillTable()
	{
		QStringList header = GetTableHeader<T>();
		QStandardItem *item;
		QStandardItemModel *itemModel = new QStandardItemModel(this);
		itemModel->setHorizontalHeaderLabels(header);
		tableView->setModel(itemModel);
		std::vector<T> dataVector = ((MainForm*)parentWidget())->oBL.getAllDataForClass<T>();
		if (!dataVector.empty())
		{
			for (int i = 0; i < dataVector.size();i++)
			{
				itemModel->appendRow(GetDataFromClass<T>(dataVector[i]));
			}
		}
	}

	template<class T>
	QStringList GetTableHeader();
	

	template<class T>
	QList<QStandardItem*> GetDataFromClass(T& data);
	
};
#endif //DATAFORM_H