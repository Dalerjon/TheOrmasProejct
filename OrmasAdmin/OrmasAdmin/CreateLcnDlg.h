#ifndef CREATELCNDLG_H
#define CREATELCNDLG_H
#include "ui_CreateLcnDlg.h"
#include "OrmasBL.h"

class CreateLcnDlg :public QDialog, public Ui::CreateLocation
{
	Q_OBJECT
public:
	CreateLcnDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateLcnDlg(){};
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
private slots:
	void CreateLocation();
	void EditLocation();
	void DeleteLocation(){};
	void Close();
private:
	BusinessLayer::Location *location = new BusinessLayer::Location();
	void SetLocationParams(QString, QString, QString, QString, int = 0);
	void FillEditElements(QString, QString, QString, QString);
	QWidget* parentForm;
};
#endif //CREATELCNDLG_H