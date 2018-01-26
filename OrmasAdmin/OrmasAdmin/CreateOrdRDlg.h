#ifndef CREATEORDRDLG_H
#define CREATEORDRDLG_H

#include "ui_CreateOrdRDlg.h"
#include "OrmasBL.h"

class CreateOrdRDlg : public QDialog, public Ui::CreateOrderRaw
{
	Q_OBJECT
public:
	CreateOrdRDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateOrdRDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateOrderRaw();
	void EditOrderRaw();
	void DeleteOrderRaw(){};
	void Close();
	void OpenEmpDlg();
	void OpenSkEmpDlg();
	void OpenStsDlg();
	void OpenCurDlg();
	void OpenOrdRListDlg();
	void StatusWasChenged();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void CloseCreatedForms();
private:
	BusinessLayer::OrderRaw *orderRaw = new BusinessLayer::OrderRaw();
	void SetOrderRawParams(int, QString, QString, int, int, double, int, int, int = 0);
	void FillEditElements(int, QString, QString, int, int, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	std::map<std::string, int> statusMap;
};
#endif //CREATEORDRDLG_H