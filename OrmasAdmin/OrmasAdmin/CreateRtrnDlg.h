#ifndef CREATERTRNDLG_H
#define CREATERTRNDLG_H

#include "ui_CreateRtrnDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateRtrnDlg : public QDialog, public Ui::CreateReturn
{
	Q_OBJECT
public:
	CreateRtrnDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateRtrnDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateReturn();
	void EditReturn();
	void DeleteReturn(){};
	void Close();
	void OpenCltDlg();
	void OpenEmpDlg();
	void OpenStsDlg();
	void OpenRtrnListDlg();
	void StatusWasChenged();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
	signals:
	void CloseCreatedForms();
private:
	BusinessLayer::Return *ret = new BusinessLayer::Return();
	void SetReturnParams(int, QString, QString, int, double, double, int, int, int = 0);
	void FillEditElements(int, QString, QString, int, double, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	std::map<std::string, int> statusMap;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
	bool CheckAccess();
};
#endif //CREATERTRNDLG_H