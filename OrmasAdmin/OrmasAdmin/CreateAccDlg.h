#ifndef CREATEAccDLG_H
#define CREATEAccDLG_H
#include "ui_CreateAccDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateAccDlg : public QDialog, public Ui::CreateAccount
{
	Q_OBJECT
public:
	CreateAccDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateAccDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateAccount();
	void EditAccount();
	void DeleteAccount(){};
	void Close();
	void OpenCOADlg();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Account *account = new BusinessLayer::Account();
	void SetAccountParams(QString, double, double, int = 0);
	void FillEditElements(QString, double, double);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	QWidget* parentForm;
	MainForm* mainForm;
};

#endif //CREATEACCDLG_H