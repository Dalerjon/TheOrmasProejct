#ifndef CREATEDIVDLG_H
#define CREATEDIVDLG_H
#include "ui_CreateDivDlg.h"
#include "OrmasBL.h"
#include <QStandardItemModel>

class CreateDivDlg : public QDialog, public Ui::CreateDivision
{
	Q_OBJECT
public:
	CreateDivDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateDivDlg(){};
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateDivision();
	void EditDivision();
	void DeleteDivision(){};
	void Close();
private:
	BusinessLayer::Division *division = new BusinessLayer::Division();
	void SetDivisionParams(QString, QString, int = 0);
	void FillEditElements(QString, QString);
	QWidget* parentForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};

#endif //CREATEDIVDLG_H