#ifndef CREATEPOSDLG_H
#define CREATEPOSDLG_H
#include "ui_CreatePosDlg.h"
#include "OrmasBL.h"

class CreatePosDlg : public QDialog, public Ui::CreatePosition
{
	Q_OBJECT
public:
	CreatePosDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreatePosDlg(){};
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreatePosition();
	void EditPosition();
	void DeletePosition(){};
	void Close();
private:
	BusinessLayer::Position *position = new BusinessLayer::Position();
	void SetPositionParams(QString, int = 0);
	void FillEditElements(QString);
	QWidget* parentForm;

};

#endif //CREATEPOSDLG_H