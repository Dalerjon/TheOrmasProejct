#ifndef CREATEMSRDLG_H
#define CREATEMSRDLG_H
#include "ui_CreateMsrDlg.h"
#include "OrmasBL.h"
#include <QStandardItemModel>

class CreateMsrDlg :public QDialog, public Ui::CreateMeasure
{
	Q_OBJECT
public:
	CreateMsrDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateMsrDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
private slots:
	void CreateMeasure();
	void EditMeasure();
	void DeleteMeasure(){};
	void Close();
private:
	BusinessLayer::Measure *measure = new BusinessLayer::Measure();
	void SetMeasureParams(QString, QString, int, int = 0);
	void FillEditElements(QString, QString, int);
	QIntValidator *vInt = nullptr;
	QWidget* parentForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};
#endif //CREATEMSRDLG_H