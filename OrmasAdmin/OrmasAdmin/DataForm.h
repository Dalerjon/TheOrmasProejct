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
	void FillTable(std::string& errorMessage, std::string filter = "")
	{
		QStringList header = GetTableHeader<T>();
		QStandardItem *item;
		QStandardItemModel *itemModel = new QStandardItemModel(this);
		itemModel->setHorizontalHeaderLabels(header);
		tableView->setModel(itemModel);
		std::vector<T> dataVector = dataFormBL->GetAllDataForClass<T>(errorMessage, filter);
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

	QWidget* GetParent();
	
private:
	void DisableButtons();
	void EnableButtons();
private slots:
	void CloseDataForm();
	void OpenList(int, int);

	void CrtCompanyDlg();
	void UdpCompanyDlg();
	void DelCompanyDlg();

	void CrtCurrencyDlg();
	void UdpCurrencyDlg();
	void DelCurrencyDlg();

	void CrtMeasureDlg();
	void UdpMeasureDlg();
	void DelMeasureDlg();

	void CrtOrdDlg();
	void UdpOrdDlg();
	void DelOrdDlg();

	void CrtProdTpDlg();
	void UdpProdTpDlg();
	void DelProdTpDlg();

	void CrtProdnDlg();
	void UdpProdnDlg();
	void DelProdnDlg();

	void CrtProdDlg();
	void UdpProdDlg();
	void DelProdDlg();

	void CrtProdListDlg();
	void UdpProdListDlg();
	void DelProdListDlg();

	void CrtLocationDlg();
	void UdpLocationDlg();
	void DelLocationDlg();

	void CrtRtrnDlg();
	void UdpRtrnDlg();
	void DelRtrnDlg();

	void CrtRoleDlg();
	void UdpRoleDlg();
	void DelRoleDlg();

	void CrtStatusDlg();
	void UdpStatusDlg();
	void DelStatusDlg();

	void CrtUserDlg();
	void UdpUserDlg();
	void DelUserDlg();

	void ChangeBtnState();
	void GetIDValue(QModelIndex index);
	void OnRowsNumberChanged();

	signals:
	void SendID(int ID, QString childName);
	
public:
	BusinessLayer::OrmasBL *dataFormBL;
	QWidget* parentForm;
	CreateUserDlg* createUserDlg = nullptr;
	CreateProdDlg* createProdDlg = nullptr;
	CreateProdnDlg* createProdnDlg = nullptr;
	AddProdDlg* addProdDlg = nullptr;
	CreateOrdDlg* createOrdDlg = nullptr;
	CreateRtrnDlg* createRtrnDlg = nullptr;
	int orderID = 0;
	int returnID = 0;
	int productionID = 0;
};
#endif //DATAFORM_H