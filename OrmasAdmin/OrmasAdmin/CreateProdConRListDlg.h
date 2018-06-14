#ifndef CREATEPRODCONRLISTDLG_H
#define CREATEPRODCONRLISTDLG_H
#include "ui_CreateProdConRListDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateProdConRListDlg : public QDialog, public Ui::CreateProdConRList
{
	Q_OBJECT
public:
	CreateProdConRListDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateProdConRListDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	int pConsumeRawID = 0;
	private slots:
	void AddProductToList();
	void EditProductInList();
	void DeleteProduct(){};
	void Close();
	void OpenConRDlg();
	void OpenProdDlg();
	void OpenStsDlg();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void DataIsChanged();
private:
	BusinessLayer::ProductionConsumeRawList *pConsumeRawList = new BusinessLayer::ProductionConsumeRawList();
	void SetConRListParams(int, int, double, double, int, int, int = 0);
	void FillEditElements(int, int, double, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
};
#endif //CREATEORDLITDLG_H