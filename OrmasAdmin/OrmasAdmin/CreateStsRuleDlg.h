#ifndef CREATESTRULESDLG_H
#define CREATESTRULESDLG_H
#include "ui_CreateStsRuleDlg.h"
#include "OrmasBL.h"

class CreateStsRuleDlg :public QDialog, public Ui::CreateStatusRule
{
	Q_OBJECT
public:
	CreateStsRuleDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateStsRuleDlg(){};
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
private slots:
	void CreateStatusRule();
	void EditStatusRule();
	void DeleteStatusRule(){};
	void Close();
	void OpenStsDlg();
signals:
	void CloseCreatedForms();
private:
	BusinessLayer::StatusRule *statusRule = new BusinessLayer::StatusRule();
	void SetStatusRuleParams(QString, int, int = 0);
	void FillEditElements(QString, int);
	QIntValidator *vInt = nullptr;
	QWidget* parentForm;
};
#endif //CREATESTRULESDLG_H