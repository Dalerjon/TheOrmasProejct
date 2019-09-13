#ifndef CREATECONPLISTDLG_H
#define CREATECONPLISTDLG_H
#include "ui_CreateConPListDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateConPListDlg : public QDialog, public Ui::CreateConPList
{
	Q_OBJECT
public:
	CreateConPListDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateConPListDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	int consumeProductID = 0;
	int employeeID = 0;
	private slots:
	void AddProductToList();
	void EditProductInList();
	void DeleteProduct(){};
	void Close();
	void OpenConPDlg();
	void OpenProdDlg();
	void OpenStsDlg();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void DataIsChanged();
private:
	BusinessLayer::ConsumeProductList *consumeProductList = new BusinessLayer::ConsumeProductList();
	void SetConPListParams(int, int, double, double, int, int, int = 0);
	void FillEditElements(int, int, double, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
	
};
#endif //CREATEORDLITDLG_H