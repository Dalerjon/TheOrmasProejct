#ifndef CREATERTRNDLG_H
#define CREATERTRNDLG_H

#include "ui_CreateRtrnDlg.h"
#include "OrmasBL.h"

class CreateRtrnDlg : public QDialog, public Ui::CreateReturn
{
	Q_OBJECT
public:
	CreateRtrnDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateRtrnDlg(){};
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateReturn();
	void EditReturn();
	void DeleteReturn(){};
	void Close();
	void OpenUserDlg();
	void OpenWorkerDlg();
	void OpenStsDlg();
	void OpenCurDlg();
	void OpenAddProdDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Return *ret = new BusinessLayer::Return();
	void SetReturnParams(int, QString, int, int, double, int, int);
	void FillEditElements(int, QString, int, int, double, int, int);
};
#endif //CREATERTRNDLG_H