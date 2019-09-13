#ifndef CREATEORDRDLG_H
#define CREATEORDRDLG_H

#include "ui_CreateOrdRDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include <QStandardItemModel>

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
	void OpenPurDlg();
	void OpenStsDlg();
	void OpenOrdRListDlg();
	void StatusWasChenged();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void CloseCreatedForms();
private:
	BusinessLayer::OrderRaw *orderRaw = new BusinessLayer::OrderRaw();
	void SetOrderRawParams(int, QString, QString, int, double, double, int, int, int = 0);
	void FillEditElements(int, QString, QString, int, double, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	std::map<std::string, int> statusMap;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
	bool CheckAccess();
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};
#endif //CREATEORDRDLG_H