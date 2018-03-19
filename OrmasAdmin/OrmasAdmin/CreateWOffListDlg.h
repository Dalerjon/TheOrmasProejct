#ifndef CREATEWOFFLISTDLG_H
#define CREATEWOFFLISTDLG_H
#include "ui_CreateWOffListDlg.h"
#include "OrmasBL.h"

class CreateWOffListDlg : public QDialog, public Ui::CreateWrOffList
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
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::WriteOffList *writeOffList = new BusinessLayer::WriteOffList();
	void SetWriteOffListParams(int, int, int, double, int, int, int = 0);
	void FillEditElements(int, int, int, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
};
#endif //CREATEWOFFLITDLG_H