#ifndef CREATECOADLG_H
#define CREATECOADLG_H
#include "ui_CreateCOADlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateCOADlg : public QDialog, public Ui::CreateChartOfAccounts
{
	Q_OBJECT
public:
	CreateCOADlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateCOADlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateChartOfAccounts();
	void EditChartOfAccounts();
	void DeleteChartOfAccounts(){};
	void Close();
	void OpenAccTpDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::ChartOfAccounts *chartOfAccounts = new BusinessLayer::ChartOfAccounts();
	void SetChartOfAccountsParams(QString, QString, int, int = 0);
	void FillEditElements(QString, QString, int);
	QIntValidator *vInt = nullptr;
	QWidget* parentForm;
	MainForm* mainForm;
};

#endif //CREATECOADLG_H