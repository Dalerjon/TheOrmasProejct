#ifndef CREATEACCTBDLG_H
#define CREATEACCTBDLG_H
#include "ui_CreateAcctbDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateAcctbDlg : public QDialog, public Ui::CreateAccountable
{
	Q_OBJECT
public:
	CreateAcctbDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateAcctbDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateAccountable();
	void EditAccountable();
	void DeleteAccountable(){};
	void Close();
	void OpenEmpDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Accountable *accountable = new BusinessLayer::Accountable();
	void SetAccountableParams(QString, int);
	void FillEditElements(QString, int);
	QWidget* parentForm;
	MainForm* mainForm;
};

#endif //CREATEAcctbDLG_H