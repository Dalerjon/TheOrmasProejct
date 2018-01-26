#ifndef CREATETRSDLG_H
#define CREATETRSDLG_H

#include "ui_CreateTrsDlg.h"
#include "OrmasBL.h"

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
	void OpenSkEmpDlg();
	void OpenStsDlg();
	void OpenCurDlg();
	void OpenTrsListDlg();
	void StatusWasChenged();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void CloseCreatedForms();
private:
	BusinessLayer::Transport *transport = new BusinessLayer::Transport();
	void SetTransportParams(int, QString, QString, int, int, double, int, int, int = 0);
	void FillEditElements(int, QString, QString, int, int, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	std::map<std::string, int> statusMap;
};
#endif //CreateTrsDLG_H