#ifndef CREATEJBPDLG_H
#define CREATEJBPDLG_H
#include "ui_CreateJbpDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include <QStandardItemModel>

class CreateJbpDlg : public QDialog, public Ui::CreateJobprice
{
	Q_OBJECT
public:
	CreateJbpDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateJbpDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateJobprice();
	void EditJobprice();
	void DeleteJobprice(){};
	void Close();
	void OpenProdDlg();
	void OpenPosDlg();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Jobprice *jobprice = new BusinessLayer::Jobprice();
	void SetJobpriceParams(int, double, int, double, int, int, int = 0);
	void FillEditElements(int, double, int, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};

#endif //CREATEJBPDLG_H