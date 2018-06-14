#ifndef GENERATEONEACCDLG_H
#define GENERATEONEACCDLG_H

#include "ui_GenerateOneAccDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class GenerateOneAcc : public QDialog, public Ui::GenerateOneAccount
{
	Q_OBJECT
public:
	GenerateOneAcc(BusinessLayer::OrmasBL *ormasBL, QWidget *parent = 0);
	~GenerateOneAcc();
	BusinessLayer::OrmasBL *dialogBL;
	std::string errorMessage = "";
	private slots:
	void Generate();
	void Close();
	void OpenCOADlg();
	public slots:
	void SetID(int ID, QString childName);
	signals:
	void CloseCreatedForms();
private:
	BusinessLayer::CompanyAccountRelation *caRelation = new BusinessLayer::CompanyAccountRelation();
	BusinessLayer::Subaccount *subaccount = new BusinessLayer::Subaccount();
	BusinessLayer::Status *status = new BusinessLayer::Status();
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
};
#endif