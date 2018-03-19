#ifndef CREATESPECDLG_H
#define CREATESPECDLG_H

#include "ui_CreateSpecDlg.h"
#include "OrmasBL.h"

class CreateSpecDlg : public QDialog, public Ui::CreateSpecification
{
	Q_OBJECT
public:
	CreateSpecDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateSpecDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateSpecification();
	void EditSpecification();
	void DeleteSpecification(){};
	void Close();
	void OpenProdDlg();
	void OpenEmpDlg();
	void OpenSpecListDlg();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void CloseCreatedForms();
private:
	BusinessLayer::Specification *specification = new BusinessLayer::Specification();
	void SetSpecificationParams(int, double, int, int, QString, int = 0);
	void FillEditElements(int, double, int, int, QString);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
};
#endif //CreateSpecDLG_H