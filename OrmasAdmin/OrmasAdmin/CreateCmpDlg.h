#ifndef CREATECMPDLG_H
#define CREATECMPDLG_H
#include "ui_CreateCmpDlg.h"
#include "OrmasBL.h"

class CreateCmpDlg : public QDialog, public Ui::CreateCompany
{
	Q_OBJECT
public:
	CreateCmpDlg(BusinessLayer::OrmasBL *ormasBL,bool updateFlag,QWidget *parent = 0);
	~CreateCmpDlg(){};
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
private slots:
	void CreateCompany();
	void EditCompany();
	void DeleteCompany(){};
	void Close();
	void TextEditChanged();
private:
	BusinessLayer::Company *company = new BusinessLayer::Company();
	void SetCompanyParams(QString, QString, QString, QString, int = 0);
	void FillEditElements(QString, QString, QString, QString);
	QWidget* parentForm;
};

#endif //CREATECMPDLG_H