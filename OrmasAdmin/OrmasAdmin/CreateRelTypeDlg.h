#ifndef CREATERELTYPEDLG_H
#define CREATERELTYPEDLG_H
#include "ui_CreateRelTypeDlg.h"
#include "OrmasBL.h"

class CreateRelTypeDlg : public QDialog, public Ui::CreateRelationType
{
	Q_OBJECT
public:
	CreateRelTypeDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateRelTypeDlg(){};
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateRelationType();
	void EditRelationType();
	void DeleteRelationType(){};
	void Close();
	void TextEditChanged();
private:
	BusinessLayer::RelationType *relationType = new BusinessLayer::RelationType();
	void SetRelationTypeParams(QString, QString, int = 0);
	void FillEditElements(QString, QString);
};

#endif //CREATERELTYPEDLG_H