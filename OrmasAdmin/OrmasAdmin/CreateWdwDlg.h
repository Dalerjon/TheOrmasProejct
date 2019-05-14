#ifndef CREATEWDWDLG_H
#define CREATEWDWDLG_H
#include "ui_CreateWdwDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateWdwDlg : public QDialog, public Ui::CreateWithdrawal
{
	Q_OBJECT
public:
	CreateWdwDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateWdwDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateWithdrawal();
	void EditWithdrawal();
	void DeleteWithdrawal(){};
	void Close();
	void TextEditChanged();
	void SATextChanged();
	void UserIsChanged();
	void OpenSAccDlg();
	void OpenUserDlg();
	void AccountIsChenged();
	void SortTable(QTableView *);
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Withdrawal *withdrawal = new BusinessLayer::Withdrawal();
	void SetWithdrawalParams(QString, double, int, int, QString, int, int = 0);
	void FillEditElements(QString, double, int, int, QString, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
};

#endif //CREATEWDWDLG_H