#ifndef CREATEAMGRDLG_H
#define CREATEAMGRDLG_H
#include "ui_CreateAmGrDlg.h"
#include "OrmasBL.h"
#include <QStandardItemModel>

class CreateAmGrDlg : public QDialog, public Ui::CreateAmortizeGroup
{
	Q_OBJECT
public:
	CreateAmGrDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateAmGrDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateAmortizeGroup();
	void EditAmortizeGroup();
	void DeleteAmortizeGroup(){};
	void Close();
private:
	BusinessLayer::AmortizeGroup *amortizeGroup = new BusinessLayer::AmortizeGroup();
	void SetAmortizeGroupParams(int, int, int, int = 0);
	void FillEditElements(int, int, int);
	QIntValidator *vInt = nullptr;
	QWidget* parentForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};

#endif //CREATEAmGrDLG_H