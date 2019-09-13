#ifndef CREATESACCDLG_H
#define CREATESACCDLG_H
#include "ui_CreateSAccDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include <QStandardItemModel>

class CreateSAccDlg : public QDialog, public Ui::CreateSubaccount
{
	Q_OBJECT
public:
	CreateSAccDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateSAccDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateSubaccount();
	void EditSubaccount();
	void DeleteSubaccount(){};
	void Close();
	void OpenStsDlg();
	void TextEditChanged();
	void GenerateNumber();
	void OpenCOADlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Subaccount *subaccount = new BusinessLayer::Subaccount();
	void SetSubaccountParams(QString, double, double, int, int, QString, QString, QString, int = 0);
	void FillEditElements(QString, double, double, int, int, QString, QString, QString);
	int GetParentAccNumber(std::string subNumber);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
	int parentAccID = 0;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};

#endif //CREATESACCDLG_H