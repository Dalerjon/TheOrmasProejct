#ifndef CREATEWOFFDLG_H
#define CREATEWOFFDLG_H

#include "ui_CreateWOffDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateWOffDlg : public QDialog, public Ui::CreateWriteOff
{
	Q_OBJECT
public:
	CreateWOffDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateWOffDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateWriteOff();
	void EditWriteOff();
	void DeleteWriteOff(){};
	void Close();
	void OpenCltDlg();
	void OpenEmpDlg();
	void OpenStsDlg();
	void OpenWOffListDlg();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
	signals:
	void CloseCreatedForms();
private:
	BusinessLayer::WriteOff *writeOff = new BusinessLayer::WriteOff();
	void SetWriteOffParams(int, QString, int, double, double, int, int, int = 0);
	void FillEditElements(int, QString, int, double, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
};
#endif //CREATEWOFFDLG_H