#ifndef GENERATEACCDLG_H
#define GENERATEACCDLG_H

#include "ui_GenerateAccDlg.h"
#include "OrmasBL.h"

class GenerateAcc : public QDialog, public Ui::GenerateAccounts
{
	Q_OBJECT
public:
	GenerateAcc(BusinessLayer::OrmasBL *ormasBL, QWidget *parent = 0);
	~GenerateAcc();
	BusinessLayer::OrmasBL *dialogBL;
	std::string errorMessage = "";
	private slots:
	void Generate();
	void Close();
private:
	BusinessLayer::CompanyAccountRelation *caRelation = new BusinessLayer::CompanyAccountRelation();
	BusinessLayer::Account *account = new BusinessLayer::Account();
	BusinessLayer::Status *status = new BusinessLayer::Status();
	void InitComboBox();
};
#endif