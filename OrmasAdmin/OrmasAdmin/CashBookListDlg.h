#ifndef CASHBOOKLISTDLG_H
#define CASHBOOKLISTDLG_H

#include "ui_CashBookListDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CashBookListDlg : public QDialog, public Ui::CashBookList
{
	Q_OBJECT
public:
	CashBookListDlg(BusinessLayer::OrmasBL *ormasBL, QWidget *parent = 0);
	~CashBookListDlg();
	BusinessLayer::OrmasBL *dialogBL;
	std::string errorMessage = "";
	private slots:
	void Generate();
	void Close();
private:
	double InSum = 0;
	double OutSum = 0;
	QWidget* parentForm;
	MainForm* mainForm;
};
#endif //CASHBOOKLISTDLG_H