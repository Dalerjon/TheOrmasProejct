#ifndef CREATEDIVACCDLG_H
#define CREATEDIVACCDLG_H

#include "ui_CreateDivAccDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include <QStandardItemModel>

class CreateDivAccDlg : public QDialog, public Ui::CreateDivisionAccount
{
	Q_OBJECT
public:
	CreateDivAccDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateDivAccDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateDivisionAccount();
	void EditDivisionAccount();
	void DeleteDivisionAccount(){};
	void Close();
	void OpenAccDlg();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void CloseCreatedForms();
private:
	BusinessLayer::DivisionAccountRelation *divisionAccount = new BusinessLayer::DivisionAccountRelation();
	void SetDivisionAccountParams(int, int, QString, int = 0);
	void FillEditElements(int, int, QString);
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};
#endif //CREATEDivAccDLG_H