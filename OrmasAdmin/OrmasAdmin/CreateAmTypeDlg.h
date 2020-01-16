#ifndef CREATEAMTYPEDLG_H
#define CREATEAMTYPEDLG_H
#include "ui_CreateAmTypeDlg.h"
#include "OrmasBL.h"
#include <QStandardItemModel>

class CreateAmTypeDlg : public QDialog, public Ui::CreateAmortizeType
{
	Q_OBJECT
public:
	CreateAmTypeDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateAmTypeDlg(){};
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateAmortizeType();
	void EditAmortizeType();
	void DeleteAmortizeType(){};
	void Close();
private:
	BusinessLayer::AmortizeType *amortizeType = new BusinessLayer::AmortizeType();
	void SetAmortizeTypeParams(QString, QString, int = 0);
	void FillEditElements(QString, QString);
	QWidget* parentForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};

#endif //CREATEAmTypeDLG_H