#ifndef CREATEPURDLG_H
#define CREATEPURDLG_H

#include "ui_CreatePurDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include <QStandardItemModel>

class CreatePurDlg : public QDialog, public Ui::CreatePurveyor
{
	Q_OBJECT
public:
	CreatePurDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreatePurDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreatePurveyor();
	void EditPurveyor();
	void DeletePurveyor(){};
	void Close();
	void OpenLcnDlg();
	void OpenRoleDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Purveyor *purveyor = new BusinessLayer::Purveyor();
	void SetPurveyorParams(QString, QString, QString, QString, QString, int, QString, QString, QString, int, int = 0);
	void FillEditElements(QString, QString, QString, QString, QString, int, QString, QString, QString, int);
	QIntValidator *vInt = nullptr;
	QWidget* parentForm;
	MainForm* mainForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};

#endif //CREATEPurDLG_H