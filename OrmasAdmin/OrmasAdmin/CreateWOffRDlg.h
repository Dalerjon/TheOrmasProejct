#ifndef CREATEWOFFRDLG_H
#define CREATEWOFFRDLG_H

#include "ui_CreateWOffRDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateWOffRDlg : public QDialog, public Ui::CreateWriteOffR
{
	Q_OBJECT
public:
	CreateWOffRDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateWOffRDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateWriteOffRaw();
	void EditWriteOffRaw();
	void DeleteWriteOffRaw(){};
	void Close();
	void OpenEmpDlg();
	void OpenSkEmpDlg();
	void OpenStsDlg();
	void StatusWasChenged();
	void TextEditChanged();
	void OpenWOffRListDlg();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void CloseCreatedForms();
private:
	BusinessLayer::WriteOffRaw *writeOffRaw = new BusinessLayer::WriteOffRaw();
	void SetWriteOffRawParams(int, QString, QString, int, double, double, int, int, int = 0);
	void FillEditElements(int, QString, QString, int, double, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	std::map<std::string, int> statusMap;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
	bool CheckAccess();
};
#endif //CREATEWOFFRDLG_H