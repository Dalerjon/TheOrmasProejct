#ifndef CREATEPRCDLG_H
#define CREATEPRCDLG_H
#include "ui_CreatePrcDlg.h"
#include "OrmasBL.h"

class CreatePrcDlg : public QDialog, public Ui::CreatePrice
{
	Q_OBJECT
public:
	CreatePrcDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreatePrcDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreatePrice();
	void EditPrice();
	void DeletePrice(){};
	void Close();
	void OpenPrdDlg();
	void OpenCurDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Price *price = new BusinessLayer::Price();
	void SetPriceParams(QString, double, int, int, int = 0);
	void FillEditElements(QString, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
};

#endif //CREATEPRCDLG_H