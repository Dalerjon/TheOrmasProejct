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
		//QStandardItem *item;
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
	void OpenList(int, int);

	void CrtAcsDlg();
	void UdpAcsDlg();
	void DelAcsDlg();

	void CrtAcsItemDlg();
	void UdpAcsItemDlg();
	void DelAcsItemDlg();

	void CrtBlcDlg();
	void UdpBlcDlg();
	void DelBlcDlg();

	void CrtCltDlg();
	void UdpCltDlg();
	void DelCltDlg();

	void CrtCmpDlg();
	void UdpCmpDlg();
	void DelCmpDlg();
	
	void CrtConPDlg();
	void UdpConPDlg();
	void DelConPDlg();

	void CrtConPListDlg();
	void UdpConPListDlg();
	void DelConPListDlg();

	void CrtConRDlg();
	void UdpConRDlg();
	void DelConRDlg();

	void CrtConRListDlg();
	void UdpConRListDlg();
	void DelConRListDlg();

	void CrtCurDlg();
	void UdpCurDlg();
	void DelCurDlg();

	void CrtEmpDlg();
	void UdpEmpDlg();
	void DelEmpDlg();

	void CrtInvDlg();
	void UdpInvDlg();
	void DelInvDlg();

	void CrtInvListDlg();
	void UdpInvListDlg();
	void DelInvListDlg();

	void CrtLcnDlg();
	void UdpLcnDlg();
	void DelLcnDlg();

	void CrtMsrDlg();
	void UdpMsrDlg();
	void DelMsrDlg();

	void CrtOrdDlg();
	void UdpOrdDlg();
	void DelOrdDlg();

	void CrtOrdListDlg();
	void UdpOrdListDlg();
	void DelOrdListDlg();

	void CrtOrdRDlg();
	void UdpOrdRDlg();
	void DelOrdRDlg();

	void CrtOrdRListDlg();
	void UdpOrdRListDlg();
	void DelOrdRListDlg();

	void CrtPhotoDlg();
	void UdpPhotoDlg();
	void DelPhotoDlg();

	void CrtPmtDlg();
	void UdpPmtDlg();
	void DelPmtDlg();

	void CrtPosDlg();
	void UdpPosDlg();
	void DelPosDlg();

	void CrtPrcDlg();
	void UdpPrcDlg();
	void DelPrcDlg();

	void CrtProdTpDlg();
	void UdpProdTpDlg();
	void DelProdTpDlg();

	void CrtProdDlg();
	void UdpProdDlg();
	void DelProdDlg();

	void CrtProdnDlg();
	void UdpProdnDlg();
	void DelProdnDlg();

	void CrtProdnListDlg();
	void UdpProdnListDlg();
	void DelProdnListDlg();

	void CrtPspDlg();
	void UdpPspDlg();
	void DelPspDlg();

	void CrtRelDlg();
	void UdpRelDlg();
	void DelRelDlg();

	void CrtRelTypeDlg();
	void UdpRelTypeDlg();
	void DelRelTypeDlg();

	void CrtRoleDlg();
	void UdpRoleDlg();
	void DelRoleDlg();

	void CrtRcpPDlg();
	void UdpRcpPDlg();
	void DelRcpPDlg();

	void CrtRcpPListDlg();
	void UdpRcpPListDlg();
	void DelRcpPListDlg();

	void CrtRcpRDlg();
	void UdpRcpRDlg();
	void DelRcpRDlg();

	void CrtRcpRListDlg();
	void UdpRcpRListDlg();
	void DelRcpRListDlg();

	void CrtRfdDlg();
	void UdpRfdDlg();
	void DelRfdDlg();

	void CrtRtrnDlg();
	void UdpRtrnDlg();
	void DelRtrnDlg();

	void CrtRtrnListDlg();
	void UdpRtrnListDlg();
	void DelRtrnListDlg();

	void CrtSlrDlg();
	void UdpSlrDlg();
	void DelSlrDlg();

	void CrtSlrTypeDlg();
	void UdpSlrTypeDlg();
	void DelSlrTypeDlg();

	void CrtStsDlg();
	void UdpStsDlg();
	void DelStsDlg();

	void CrtStockDlg();
	void UdpStockDlg();
	void DelStockDlg();

	void CrtTrsDlg();
	void UdpTrsDlg();
	void DelTrsDlg();

	void CrtTrsListDlg();
	void UdpTrsListDlg();
	void DelTrsListDlg();

	void CrtUserDlg();
	void UdpUserDlg();
	void DelUserDlg();

	void CrtWdwDlg();
	void UdpWdwDlg();
	void DelWdwDlg();

	void CrtWOffDlg();
	void UdpWOffDlg();
	void DelWOffDlg();

	void CrtWOffListDlg();
	void UdpWOffListDlg();
	void DelWOffListDlg();

	void CrtWOffRDlg();
	void UdpWOffRDlg();
	void DelWOffRDlg();

	void CrtWOffRListDlg();
	void UdpWOffRListDlg();
	void DelWOffRListDlg();

	void ChangeBtnState();
	void GetIDValue(QModelIndex index);
	void OnRowsNumberChanged();
	
	public slots:
	void CloseDataForm();
	
	signals:
	void SendID(int ID, QString childName);
	
public:
	BusinessLayer::OrmasBL *dataFormBL;
	QWidget* parentForm;
	ClcWagesDlg* clcWagesDlg = nullptr;
	CreateAcsDlg* createAcsDlg = nullptr;
	CreateBlcDlg* createBlcDlg = nullptr;
	CreateCltDlg* createCltDlg = nullptr;
	CreateConPDlg* createConPDlg = nullptr;
	CreateConPListDlg* createConPListDlg = nullptr;
	CreateConRDlg* createConRDlg = nullptr;
	CreateConRListDlg* createConRListDlg = nullptr;
	CreateEmpDlg* createEmpDlg = nullptr;
	CreateInvDlg* createInvDlg = nullptr;
	CreateInvListDlg* createInvListDlg = nullptr;
	CreateOrdDlg* createOrdDlg = nullptr;
	CreateOrdListDlg* createOrdListDlg = nullptr;
	CreateOrdRDlg* createOrdRDlg = nullptr;
	CreateOrdRListDlg* createOrdRListDlg = nullptr;
	CreatePhtDlg* createPhtDlg = nullptr;
	CreatePmtDlg* createPmtDlg = nullptr;
	CreatePrcDlg* createPrcDlg = nullptr;
	CreateProdnListDlg* createProdnListDlg = nullptr;
	CreatePspDlg* createPspDlg = nullptr;
	CreateRelDlg* createRelDlg = nullptr;
	CreateRcpPDlg* createRcpPDlg = nullptr;
	CreateRcpPListDlg* createRcpPListDlg = nullptr;
	CreateRcpRDlg* createRcpRDlg = nullptr;
	CreateRcpRListDlg* createRcpRListDlg = nullptr;
	CreateRfdDlg* createRfdDlg = nullptr;
	CreateRtrnListDlg* createRtrnListDlg = nullptr;
	CreateSlrDlg* createSlrDlg = nullptr;
	CreateStockDlg* createStockDlg = nullptr;
	CreateTrsDlg* createTrsDlg = nullptr;
	CreateTrsListDlg* createTrsListDlg = nullptr;
	CreateUserDlg* createUserDlg = nullptr;
	CreateProdDlg* createProdDlg = nullptr;
	CreateProdnDlg* createProdnDlg = nullptr;
	CreateRtrnDlg* createRtrnDlg = nullptr;
	CreateWdwDlg* createWdwDlg = nullptr;
	CreateWOffDlg* createWOffDlg = nullptr;
	CreateWOffListDlg* createWOffListDlg = nullptr;
	CreateWOffRDlg* createWOffRDlg = nullptr;
	CreateWOffRListDlg* createWOffRListDlg = nullptr;
	
	int orderID = 0;
	int returnID = 0;
	int productionID = 0;
	int writeOffID = 0;
	int consumeProductID = 0;
	int consumeRawID = 0;
	int inventorizationID = 0;
	int orderRawID = 0;
	int receiptProductID = 0; 
	int receiptRawID = 0;
	int transportID = 0;
	int writeOffRawID = 0;
};
#endif //DATAFORM_H