#ifndef CREATECURDLG_H
#define CREATECURDLG_H
#include "ui_CreateCurDlg.h"
#include "OrmasBL.h"

class CreateCurDlg : public QDialog, public Ui::CreateCurrency
{
	Q_OBJECT
public:
	CreateCurDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateCurDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
private slots:
	void CreateCurrency();
	void EditCurrency();
	void DeleteCurrency(){};
	void Close();
private:
	BusinessLayer::Currency *currency = new BusinessLayer::Currency();
	void SetCurrencyParams(int, QString, QString, int, QString, int = 0);
	void FillEditElements(int, QString, QString, int, QString);
	QIntValidator *vInt = nullptr;
	QWidget* parentForm;

};
#endif //CREATECURDLG_H