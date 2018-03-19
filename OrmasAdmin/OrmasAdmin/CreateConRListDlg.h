#ifndef CREATECONRLISTDLG_H
#define CREATECONRLISTDLG_H
#include "ui_CreateConRListDlg.h"
#include "OrmasBL.h"

class CreateConRListDlg : public QDialog, public Ui::CreateConRList
{
	Q_OBJECT
public:
	CreateConRListDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateConRListDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	int consumeRawID = 0;
	private slots:
	void AddProductToList();
	void EditProductInList();
	void DeleteProduct(){};
	void Close();
	void OpenConRDlg();
	void OpenProdDlg();
	void OpenStsDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::ConsumeRawList *consumeRawList = new BusinessLayer::ConsumeRawList();
	void SetConRListParams(int, int, int, double, int, int, int = 0);
	void FillEditElements(int, int, int, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
};
#endif //CREATEORDLITDLG_H