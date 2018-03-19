#ifndef CREATEPCRDLG_H
#define CREATEPCRDLG_H
#include "ui_CreatePcrDlg.h"
#include "OrmasBL.h"

class CreatePcrDlg : public QDialog, public Ui::CreatePercentRate
{
	Q_OBJECT
public:
	CreatePcrDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreatePcrDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreatePercentRate();
	void EditPercentRate();
	void DeletePercentRate(){};
	void Close();
	void OpenPosDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::PercentRate *percentRate = new BusinessLayer::PercentRate();
	void SetPercentRateParams(double, QString, int, int = 0);
	void FillEditElements(double, QString, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
};

#endif //CreatePcrDLG_H