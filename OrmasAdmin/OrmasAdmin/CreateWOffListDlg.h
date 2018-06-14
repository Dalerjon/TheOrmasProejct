#ifndef CREATEWOFFLISTDLG_H
#define CREATEWOFFLISTDLG_H
#include "ui_CreateWOffListDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateWOffListDlg : public QDialog, public Ui::CreateWOffList
{
	Q_OBJECT
public:
	CreateWOffListDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateWOffListDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	int writeOffID = 0;
	private slots:
	void AddProductToList();
	void EditProductInList();
	void DeleteProduct(){};
	void Close();
	void OpenWOffDlg();
	void OpenProdDlg();
	void OpenStsDlg();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void DataIsChanged();
private:
	BusinessLayer::WriteOffList *writeOffList = new BusinessLayer::WriteOffList();
	void SetWriteOffListParams(int, int, double, double, int, int, int = 0);
	void FillEditElements(int, int, double, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
};
#endif //CREATEWOFFLITDLG_H