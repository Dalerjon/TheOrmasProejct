#ifndef DATAFORM_H
#define DATAFORM_H

#include "ui_DataForm.h"
#include "OrmasBL.h"
#include <QStandardItem>
#include <QStringList>
#include <QDialog>


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
			for (unsigned int i = 0; i < dataVector.size();i++)
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

	void CrtAccDlg();
	void UdpAccDlg();
	void DelAccDlg();

	void CrtAccTpDlg();
	void UdpAccTpDlg();
	void DelAccTpDlg();

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

	void CrtCARDlg();
	void UdpCARDlg();
	void DelCARDlg();

	void CrtCERDlg();
	void UdpCERDlg();
	void DelCERDlg();

	void CrtCOADlg();
	void UdpCOADlg();
	void DelCOADlg();
	
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

	void CrtDivDlg();
	void UdpDivDlg();
	void DelDivDlg();

	void CrtEmpDlg();
	void UdpEmpDlg();
	void DelEmpDlg();

	void CrtEtrDlg();
	void UdpEtrDlg();
	void DelEtrDlg();

	void CrtEtrRtDlg();
	void UdpEtrRtDlg();
	void DelEtrRtDlg();

	void CrtInvDlg();
	void UdpInvDlg();
	void DelInvDlg();

	void CrtInvListDlg();
	void UdpInvListDlg();
	void DelInvListDlg();

	void CrtJbpDlg();
	void UdpJbpDlg();
	void DelJbpDlg();

	void CrtJbsDlg();
	void UdpJbsDlg();
	void DelJbsDlg();

	void CrtLcnDlg();
	void UdpLcnDlg();
	void DelLcnDlg();

	void CrtMsrDlg();
	void UdpMsrDlg();
	void DelMsrDlg();

	void CrtNetCDlg();
	void UdpNetCDlg();
	void DelNetCDlg();

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

	void CrtPcrDlg();
	void UdpPcrDlg();
	void DelPcrDlg();

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

	void CrtProdConRDlg();
	void UdpProdConRDlg();
	void DelProdConRDlg();

	void CrtProdConRListDlg();
	void UdpProdConRListDlg();
	void DelProdConRListDlg();

	void CrtProdnStockDlg();
	void UdpProdnStockDlg();
	void DelProdnStockDlg();

	void CrtProdnListDlg();
	void UdpProdnListDlg();
	void DelProdnListDlg();

	void CrtPPlanDlg();
	void UdpPPlanDlg();
	void DelPPlanDlg();

	void CrtPPlanListDlg();
	void UdpPPlanListDlg();
	void DelPPlanListDlg();

	void CrtPspDlg();
	void UdpPspDlg();
	void DelPspDlg();

	void CrtPurDlg();
	void UdpPurDlg();
	void DelPurDlg();

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

	void CrtStsRuleDlg();
	void UdpStsRuleDlg();
	void DelStsRuleDlg();

	void CrtSpecDlg();
	void UdpSpecDlg();
	void DelSpecDlg();
	
	void CrtSpecListDlg();
	void UdpSpecListDlg();
	void DelSpecListDlg();

	void CrtSplDlg();
	void UdpSplDlg();
	void DelSplDlg();

	void CrtSplListDlg();
	void UdpSplListDlg();
	void DelSplListDlg();

	void CrtStockDlg();
	void UdpStockDlg();
	void DelStockDlg();

	void CrtSAccDlg();
	void UdpSAccDlg();
	void DelSAccDlg();

	void CrtTmsDlg();
	void UdpTmsDlg();
	void DelTmsDlg();

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
	void AcsDenied();
	
	public slots:
	void CloseDataForm();
	
	signals:
	void SendID(int ID, QString childName);
	
public:
	BusinessLayer::OrmasBL* dataFormBL;
	QWidget* parentForm;
	QDialog* parentDialog;
	BusinessLayer::User* loggedUser;
	void HileSomeRow();
	bool IsClosed();
	
	unsigned int orderID = 0;
	unsigned int returnID = 0;
	unsigned int productionID = 0;
	unsigned int writeOffID = 0;
	unsigned int consumeProductID = 0;
	unsigned int consumeRawID = 0;
	unsigned int inventorizationID = 0;
	unsigned int orderRawID = 0;
	unsigned int productionPlanID = 0;
	unsigned int pConsumeRawID = 0;
	unsigned int receiptProductID = 0;
	unsigned int receiptRawID = 0;
	unsigned int specificationID = 0;
	unsigned int spoilageID = 0;
	unsigned int transportID = 0;
	unsigned int writeOffRawID = 0;
};
#endif //DATAFORM_H