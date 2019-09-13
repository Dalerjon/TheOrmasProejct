#ifndef CREATERFDDLG_H
#define CREATERFDDLG_H
#include "ui_CreateRfdDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include <QStandardItemModel>

class CreateRfdDlg : public QDialog, public Ui::CreateRefund
{
	Q_OBJECT
public:
	CreateRfdDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateRfdDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateRefund();
	void EditRefund();
	void DeleteRefund(){};
	void Close();
	void OpenUserDlg();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Refund *refund = new BusinessLayer::Refund();
	void SetRefundParams(QString, double, int, int, int = 0);
	void FillEditElements(QString, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};

#endif //CREATERfdDLG_H