#ifndef CREATETRSLISTDLG_H
#define CREATETRSLISTDLG_H
#include "ui_CreateTrsListDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateTrsListDlg : public QDialog, public Ui::CreateTrsList
{
	Q_OBJECT
public:
	CreateTrsListDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateTrsListDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	int transportID = 0;
	private slots:
	void AddProductToList();
	void EditProductInList();
	void DeleteProduct(){};
	void Close();
	void OpenTrsDlg();
	void OpenProdDlg();
	void OpenStsDlg();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void DataIsChanged();
private:
	BusinessLayer::TransportList *transportList = new BusinessLayer::TransportList();
	void SetTrsListParams(int, int, double, double, int, int, int = 0);
	void FillEditElements(int, int, double, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
};
#endif //CREATETRSLISTDLG_H