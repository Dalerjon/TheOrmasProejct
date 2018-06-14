#ifndef CREATETAXDLG_H
#define CREATETAXDLG_H
#include "ui_CreateTaxDlg.h"
#include "OrmasBL.h"

class CreateTaxDlg : public QDialog, public Ui::CreateTax
{
	Q_OBJECT
public:
	CreateTaxDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateTaxDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateTax();
	void EditTax();
	void DeleteTax(){};
	void Close();
private:
	BusinessLayer::Tax *tax = new BusinessLayer::Tax();
	void SetTaxParams(QString, QString, double, int, QString, int = 0);
	void FillEditElements(QString, QString, double, int, QString);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	QWidget* parentForm;
};

#endif //CREATETAXDLG_H