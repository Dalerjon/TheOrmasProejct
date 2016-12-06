#ifndef DATAFORM_H
#define DATAFORM_H

#include "ui_DataForm.h"
#include "OrmasBL.h"
#include <QStandardItem>
#include "AllDlgHeaders.h"

class DataForm : public QWidget, public Ui::DataForm
{
	Q_OBJECT
public:
	DataForm(BusinessLayer::OrmasBL *ormasBL, QWidget *parent = 0);
	~DataForm(){};
	
	template<class T>
	void FillTable(std::string& errorMessage)
	{
		QStringList header = GetTableHeader<T>();
		QStandardItem *item;
		QStandardItemModel *itemModel = new QStandardItemModel(this);
		itemModel->setHorizontalHeaderLabels(header);
		tableView->setModel(itemModel);
		std::vector<T> dataVector = dataFormBL->GetAllDataForClass<T>(errorMessage);
		if (!dataVector.empty())
		{
			for (int i = 0; i < dataVector.size();i++)
			{
				itemModel->appendRow(GetDataFromClass<T>(dataVector[i]));
			}
		}
	}

	template<class T>
	void QtConnect();

	template<class T>
	QStringList GetTableHeader();
	

	template<class T>
	QList<QStandardItem*> GetDataFromClass(T& data);
private:
	void DisableButtons();
	void EnableButtons();
private slots:
	void CloseDataForm();
	void CrtCompanyDlg();
	void UdpCompanyDlg();
	void DelCompanyDlg();
	void CrtCurrencyDlg();
	void UdpCurrencyDlg();
	void DelCurrencyDlg();
	void CrtMeasureDlg();
	void UdpMeasureDlg();
	void DelMeasureDlg();
	void CrtProdTpDlg();
	void UdpProdTpDlg();
	void DelProdTpDlg();
	void CrtLocationDlg();
	void UdpLocationDlg();
	void DelLocationDlg();
	void CrtRoleDlg();
	void UdpRoleDlg();
	void DelRoleDlg();
	void CrtStatusDlg();
	void UdpStatusDlg();
	void DelStatusDlg();
	void ChangeBtnState();
public:
	BusinessLayer::OrmasBL *dataFormBL;
	QWidget* parentForm;
};
#endif //DATAFORM_H