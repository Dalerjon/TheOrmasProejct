#ifndef CREATECONPDLG_H
#define CREATECONPDLG_H

#include "ui_CreateConPDlg.h"
#include "OrmasBL.h"

class CreateConPDlg : public QDialog, public Ui::CreateConsumeProduct
{
	Q_OBJECT
public:
	CreateConPDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateConPDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateConsumeProduct();
	void EditConsumeProduct();
	void DeleteConsumeProduct(){};
	void Close();
	void OpenEmpDlg();
	void OpenSkEmpDlg();
	void OpenStsDlg();
	void OpenCurDlg();
	void OpenConPListDlg();
	void StatusWasChenged();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void CloseCreatedForms();
private:
	BusinessLayer::ConsumeProduct *consumeProduct = new BusinessLayer::ConsumeProduct();
	void SetConsumeProductParams(int, QString, QString, int, int, double, int, int, int = 0);
	void FillEditElements(int, QString, QString, int, int, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	std::map<std::string, int> statusMap;
};
#endif //CREATECONPDLG_H