#ifndef CREATEBLCDLG_H
#define CREATEBLCDLG_H

#include "ui_CreateBlcDlg.h"
#include "OrmasBL.h"

class CreateBlcDlg : public QDialog, public Ui::CreateBalance
{
	Q_OBJECT
public:
	CreateBlcDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateBlcDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateBalance();
	void EditBalance();
	void DeleteBalance(){};
	void Close();
	void OpenUserDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Balance *balance = new BusinessLayer::Balance();
	void SetBalanceParams(int, int, int = 0);
	void FillEditElements(int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
};

#endif //CREATEBLCDLG_H