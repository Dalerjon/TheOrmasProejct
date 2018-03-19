#ifndef CREATEAccDLG_H
#define CREATEAccDLG_H
#include "ui_CreateAccDlg.h"
#include "OrmasBL.h"

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
	void OpenStsDlg();
	void OpenCOADlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Account *account = new BusinessLayer::Account();
	void SetAccountParams(QString, double, double, int, int, QString, QString, QString, int = 0);
	void FillEditElements(QString, double, double, int, int, QString, QString, QString);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
};

#endif //CREATEACCDLG_H