#ifndef CREATEORDDLG_H
#define CREATEORDDLG_H

#include "ui_CreateOrdDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateOrdDlg : public QDialog, public Ui::CreateOrder
{
	Q_OBJECT
public:
	CreateOrdDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateOrdDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateOrder();
	void EditOrder();
	void DeleteOrder(){};
	void Close();
	void OpenCltDlg();
	void OpenEmpDlg();
	void OpenStsDlg();
	void OpenOrdListDlg();
	void StatusWasChenged();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
	signals:
	void CloseCreatedForms();
private:
	BusinessLayer::Order *order = new BusinessLayer::Order();
	void SetOrderParams(int, QString, QString, int, double, double, int, int, int = 0);
	void FillEditElements(int, QString, QString, int, double, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	std::map<std::string, int> statusMap;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
	bool CheckAccess();
};
#endif //CREATEORDDLG_H