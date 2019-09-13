#ifndef CREATEPRCDLG_H
#define CREATEPRCDLG_H
#include "ui_CreatePrcDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include <QStandardItemModel>

class CreatePrcDlg : public QDialog, public Ui::CreatePrice
{
	Q_OBJECT
public:
	CreatePrcDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreatePrcDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreatePrice();
	void EditPrice();
	void DeletePrice(){};
	void Close();
	void OpenPrdDlg();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Price *price = new BusinessLayer::Price();
	void SetPriceParams(QString, double, int, int, QString, int = 0);
	void FillEditElements(QString, double, int, int, QString);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};

#endif //CREATEPRCDLG_H