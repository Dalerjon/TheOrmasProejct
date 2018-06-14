#ifndef CREATEACSITEMDLG_H
#define CREATEACSITEMDLG_H
#include "ui_CreateAcsItemDlg.h"
#include "OrmasBL.h"

class CreateAcsItemDlg : public QDialog, public Ui::CreateAccessItem
{
	Q_OBJECT
public:
	CreateAcsItemDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateAcsItemDlg(){};
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateAccessItem();
	void EditAccessItem();
	void DeleteAccessItem(){};
	void Close();
private:
	BusinessLayer::AccessItem *accessItem = new BusinessLayer::AccessItem();
	void SetAccessItemParams(QString, QString, QString, int = 0);
	void FillEditElements(QString, QString, QString);
	QWidget* parentForm;
};

#endif //CREATEACSITEMDLG_H
