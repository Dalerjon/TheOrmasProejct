#ifndef CREATEORDDLG_H
#define CREATEORDDLG_H

#include "ui_CreateOrdDlg.h"
#include "OrmasBL.h"

class CreateOrdDlg : public QDialog, public Ui::CreateOrder
{
	Q_OBJECT
public:
	CreateOrdDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateOrdDlg(){};
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateOrder();
	void EditOrder();
	void DeleteOrder(){};
	void Close();
	void OpenUserDlg();
	void OpenWorkerDlg();
	void OpenStsDlg();
	void OpenCurDlg();
	void OpenAddProdDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Order *order = new BusinessLayer::Order();
	void SetOrderParams(int, QString, int, int, double, int, int);
	void FillEditElements(int, QString, int, int, double, int, int);
};
#endif //CREATEORDDLG_H