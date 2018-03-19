#ifndef CREATERELDLG_H
#define CREATERELDLG_H
#include "ui_CreateRelDlg.h"
#include "OrmasBL.h"

class CreateRelDlg : public QDialog, public Ui::CreateRelation
{
	Q_OBJECT
public:
	CreateRelDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateRelDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateRelation();
	void EditRelation();
	void DeleteRelation(){};
	void Close();
	void OpenUser1Dlg();
	void OpenUser2Dlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Relation *relation = new BusinessLayer::Relation();
	void SetRelationParams(int, int, int, int = 0);
	void FillEditElements(int, int, int);
	QIntValidator *vInt = nullptr;
	void InitComboBox();
};

#endif //CREATERELDLG_H