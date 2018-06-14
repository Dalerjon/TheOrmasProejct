#ifndef CREATEWOFFRLISTDLG_H
#define CREATEWOFFRLISTDLG_H
#include "ui_CreateWOffRListDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateWOffRListDlg : public QDialog, public Ui::CreateWOffRList
{
	Q_OBJECT
public:
	CreateWOffRListDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateWOffRListDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	int writeOffRawID = 0;
	private slots:
	void AddProductToList();
	void EditProductInList();
	void DeleteProduct(){};
	void Close();
	void OpenWOffRDlg();
	void OpenProdDlg();
	void OpenStsDlg();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void DataIsChanged();
private:
	BusinessLayer::WriteOffRawList *writeOffRawList = new BusinessLayer::WriteOffRawList();
	void SetWOffRListParams(int, int, double, double, int, int, int = 0);
	void FillEditElements(int, int, double, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
};
#endif //CREATEWOFFRLISTDLG_H