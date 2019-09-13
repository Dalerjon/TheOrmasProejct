#ifndef CREATEBRWDLG_H
#define CREATEBRWDLG_H
#include "ui_CreateBrwDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include <QStandardItemModel>

class CreateBrwDlg : public QDialog, public Ui::CreateBorrower
{
	Q_OBJECT
public:
	CreateBrwDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateBrwDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateBorrower();
	void EditBorrower();
	void DeleteBorrower(){};
	void Close();
	void OpenEmpDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Borrower *borrower = new BusinessLayer::Borrower();
	void SetBorrowerParams(QString, int);
	void FillEditElements(QString, int);
	QWidget* parentForm;
	MainForm* mainForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};

#endif //CREATEBrwDLG_H