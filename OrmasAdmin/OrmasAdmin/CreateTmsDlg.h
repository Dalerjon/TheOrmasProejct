#ifndef CREATETMSDLG_H
#define CREATETMSDLG_H
#include "ui_CreateTmsDlg.h"
#include "OrmasBL.h"

class CreateTmsDlg : public QDialog, public Ui::CreateTimesheet
{
	Q_OBJECT
public:
	CreateTmsDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateTmsDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateTimesheet();
	void EditTimesheet();
	void DeleteTimesheet(){};
	void Close();
	void OpenSlrDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Timesheet *timesheet = new BusinessLayer::Timesheet();
	void SetTimesheetParams(int, double, QString, int = 0);
	void FillEditElements(int, double, QString);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
};

#endif //CREATETMSDLG_H