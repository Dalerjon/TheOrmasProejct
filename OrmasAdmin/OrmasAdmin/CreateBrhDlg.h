#ifndef CREATEBRHDLG_H
#define CREATEBRHDLG_H
#include "ui_CreateBrhDlg.h"
#include "OrmasBL.h"

class CreateBrhDlg : public QDialog, public Ui::CreateBranch
{
	Q_OBJECT
public:
	CreateBrhDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateBrhDlg(){};
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateBranch();
	void EditBranch();
	void DeleteBranch(){};
	void Close();
private:
	BusinessLayer::Branch *branch = new BusinessLayer::Branch();
	void SetBranchParams(QString, QString, QString, QString, int = 0);
	void FillEditElements(QString, QString, QString, QString);
	QWidget* parentForm;
};

#endif //CREATEBRHDLG_H