#ifndef CREATENETCDLG_H
#define CREATENETCDLG_H
#include "ui_CreateNetCDlg.h"
#include "OrmasBL.h"

class CreateNetCDlg : public QDialog, public Ui::CreateNetCost
{
	Q_OBJECT
public:
	CreateNetCDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateNetCDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateNetCost();
	void EditNetCost();
	void DeleteNetCost(){};
	void Close();
	void OpenPrdDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::NetCost *netCost = new BusinessLayer::NetCost();
	void SetNetCostParams(QString, double, int, int, QString, int = 0);
	void FillEditElements(QString, double, int, int, QString);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
};

#endif //CREATENETCDLG_H