#ifndef CREATERTRNLISTDLG_H
#define CREATERTRNLISTDLG_H
#include "ui_CreateRtrnListDlg.h"
#include "OrmasBL.h"

class CreateRtrnListDlg : public QDialog, public Ui::CreateRtrnList
{
	Q_OBJECT
public:
	CreateRtrnListDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateRtrnListDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	int returnID = 0;
	private slots:
	void AddProductToList();
	void EditProductInList();
	void DeleteProduct(){};
	void Close();
	void OpenRtrnDlg();
	void OpenProdDlg();
	void OpenStsDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::ReturnList *returnList = new BusinessLayer::ReturnList();
	void SetReturnListParams(int, int, int, double, int, int, int = 0);
	void FillEditElements(int, int, int, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
};
#endif //CREATEORDLITDLG_H