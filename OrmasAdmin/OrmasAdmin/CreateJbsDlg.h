#ifndef CREATEJBSDLG_H
#define CREATEJBSDLG_H
#include "ui_CreateJbsDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include <QStandardItemModel>

class CreateJbsDlg : public QDialog, public Ui::CreateJobsheet
{
	Q_OBJECT
public:
	CreateJbsDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateJbsDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateJobsheet();
	void EditJobsheet();
	void DeleteJobsheet(){};
	void Close();
	void OpenEmpDlg();
	void OpenProdDlg();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Jobsheet *jobsheet = new BusinessLayer::Jobsheet();
	void SetJobsheetParams(QString, double, int, int, int = 0);
	void FillEditElements(QString, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	QWidget* parentForm;
	MainForm* mainForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};

#endif //CREATEJBSDLG_H