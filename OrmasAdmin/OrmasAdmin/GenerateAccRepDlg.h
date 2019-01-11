#ifndef GENERATEACCREPDLG_H
#define GENERATEACCREPDLG_H

#include "ui_GenerateAccRepDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class GenerateAccCardRep : public QDialog, public Ui::GenerateAccountCardReport
{
	Q_OBJECT
public:
	GenerateAccCardRep(BusinessLayer::OrmasBL *ormasBL, QWidget *parent = 0);
	~GenerateAccCardRep();
	BusinessLayer::OrmasBL *dialogBL;
	std::string errorMessage = "";
	private slots:
	void Generate();
	void Close();
	void OpenAccDlg();
	void OpenSAccDlg();
	void AccTextChanged();
	
	public slots:
	void SetID(int ID, QString childName);
	signals:
	void CloseCreatedForms();
private:
	QWidget* parentForm;
	MainForm* mainForm;
	QIntValidator *vInt = nullptr;
	std::string prevFromMonth;
	std::string prevTillMonth;
};
#endif