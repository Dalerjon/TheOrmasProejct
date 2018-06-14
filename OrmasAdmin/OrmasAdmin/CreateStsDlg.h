#ifndef CREATESTSDLG_H
#define CREATESTSDLG_H
#include "ui_CreateStsDlg.h"
#include "OrmasBL.h"

class CreateStsDlg :public QDialog, public Ui::CreateStatus
{
	Q_OBJECT
public:
	CreateStsDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateStsDlg(){};
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
private slots:
	void CreateStatus();
	void EditStatus();
	void DeleteStatus(){};
	void Close();
	void TextEditChanged();
private:
	BusinessLayer::Status *status = new BusinessLayer::Status();
	void SetStatusParams(QString, QString, QString, int = 0);
	void FillEditElements(QString, QString, QString);
	QWidget* parentForm;
};
#endif //CREATESTSDLG_H