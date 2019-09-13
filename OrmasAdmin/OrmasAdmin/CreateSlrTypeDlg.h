#ifndef CREATESLRTYPEDLG_H
#define CREATESLRTYPEDLG_H
#include "ui_CreateSlrTypeDlg.h"
#include "OrmasBL.h"
#include <QStandardItemModel>

class CreateSlrTypeDlg : public QDialog, public Ui::CreateSalaryType
{
	Q_OBJECT
public:
	CreateSlrTypeDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateSlrTypeDlg(){};
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateSalaryType();
	void EditSalaryType();
	void DeleteSalaryType(){};
	void Close();
private:
	BusinessLayer::SalaryType *salaryType = new BusinessLayer::SalaryType();
	void SetSalaryTypeParams(QString, QString, int = 0);
	void FillEditElements(QString, QString);
	QWidget* parentForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};

#endif //CREATESLRDLG_H