#ifndef CREATESPECLISTDLG_H
#define CREATESPECLISTDLG_H
#include "ui_CreateSpecListDlg.h"
#include "OrmasBL.h"

class CreateSpecListDlg : public QDialog, public Ui::CreateSpecList
{
	Q_OBJECT
public:
	CreateSpecListDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateSpecListDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	int specificationID = 0;
	private slots:
	void AddProductToList();
	void EditProductInList();
	void DeleteProduct(){};
	void Close();
	void OpenSpecDlg();
	void OpenProdDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::SpecificationList *specificationList = new BusinessLayer::SpecificationList();
	void SetSpecificationListParams(int, int, double, int = 0);
	void FillEditElements(int, int, double);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
};
#endif //CREATESPECLISTDLG_H