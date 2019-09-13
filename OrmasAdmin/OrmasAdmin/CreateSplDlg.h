#ifndef CREATESPLDLG_H
#define CREATESPLDLG_H

#include "ui_CreateSplDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include <QStandardItemModel>


class CreateSplDlg : public QDialog, public Ui::CreateSpoilage
{
	Q_OBJECT
public:
	CreateSplDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateSplDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateSpoilage();
	void EditSpoilage();
	void DeleteSpoilage(){};
	void Close();
	void OpenEmpDlg();
	void OpenStsDlg();
	void OpenSplListDlg();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void CloseCreatedForms();
private:
	BusinessLayer::Spoilage *spoilage = new BusinessLayer::Spoilage();
	void SetSpoilageParams(QString, int, double, double, int, int, int = 0);
	void FillEditElements(QString, int, double, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	std::map<std::string, int> statusMap;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};
#endif //CREATESPLDLG_H