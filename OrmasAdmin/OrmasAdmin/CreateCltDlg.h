#ifndef CREATECLTDLG_H
#define CREATECLTDLG_H

#include "ui_CreateCltDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include <QStandardItemModel>

class CreateCltDlg : public QDialog, public Ui::CreateClient
{
	Q_OBJECT
public:
	CreateCltDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateCltDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateClient();
	void EditClient();
	void DeleteClient(){};
	void Close();
	void OpenLcnDlg();
	void OpenRoleDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Client *client = new BusinessLayer::Client();
	void SetClientParams(QString, QString, QString, QString, QString, int, QString, QString, QString, QString, int, int = 0);
	void FillEditElements(QString, QString, QString, QString, QString, int, QString, QString, QString, QString, int);
	QIntValidator *vInt = nullptr;
	QWidget* parentForm;
	MainForm* mainForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};

#endif //CREATECLTDLG_H