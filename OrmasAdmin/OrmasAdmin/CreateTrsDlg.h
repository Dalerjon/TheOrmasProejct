#ifndef CREATETRSDLG_H
#define CREATETRSDLG_H

#include "ui_CreateTrsDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateTrsDlg : public QDialog, public Ui::CreateTransport
{
	Q_OBJECT
public:
	CreateTrsDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateTrsDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateTransport();
	void EditTransport();
	void DeleteTransport(){};
	void Close();
	void OpenEmpDlg();
	void OpenUserDlg();
	void OpenStsDlg();
	void OpenTrsListDlg();
	void StatusWasChenged();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void CloseCreatedForms();
private:
	BusinessLayer::Transport *transport = new BusinessLayer::Transport();
	void SetTransportParams(int, QString, QString, int, double, double, int, int, int = 0);
	void FillEditElements(int, QString, QString, int, double, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	std::map<std::string, int> statusMap;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
};
#endif //CreateTrsDLG_H