#ifndef CREATECARDLG_H
#define CREATECARDLG_H
#include "ui_CreateCARDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include <QStandardItemModel>

class CreateCARDlg : public QDialog, public Ui::CreateCompanyAccount
{
	Q_OBJECT
public:
	CreateCARDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateCARDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateCompanyAccount();
	void EditCompanyAccount();
	void DeleteCompanyAccount(){};
	void Close();
	void OpenAccDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::CompanyAccountRelation *companyAccount = new BusinessLayer::CompanyAccountRelation();
	void SetCompanyAccountParams(int, int, int = 0);
	void FillEditElements(int, int);
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};

#endif //CREATECARDLG_H