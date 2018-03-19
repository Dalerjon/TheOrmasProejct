#ifndef CREATEACCTPDLG_H
#define CREATEACCTPDLG_H
#include "ui_CreateAccTpDlg.h"
#include "OrmasBL.h"

class CreateAccTpDlg : public QDialog, public Ui::CreateAccountType
{
	Q_OBJECT
public:
	CreateAccTpDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateAccTpDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateAccountType();
	void EditAccountType();
	void DeleteAccountType(){};
	void Close();
private:
	BusinessLayer::AccountType *accountType = new BusinessLayer::AccountType();
	void SetAccountTypeParams(QString, int, QString, int = 0);
	void FillEditElements(QString, int, QString);
	QIntValidator *vInt = nullptr;
};

#endif //CREATEACCTPDLG_H