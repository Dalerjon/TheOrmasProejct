#ifndef REPORTFORM_H
#define REPORTFORM_H

#include "ui_ReportForm.h"
#include "OrmasBL.h"
#include <QStandardItem>
#include <QStringList>
#include <QDialog>


class ReportForm : public QWidget, public Ui::ReportForm
{
	Q_OBJECT
public:
	ReportForm(BusinessLayer::OrmasBL *ormasBL, QWidget *parent = 0);
	~ReportForm(){};
	void GetIDValue(QModelIndex index);
	void FillStockTable(std::string, std::string, int, std::string);

	private slots:
	void ViewWTBS();
signals:
	void SendID(int ID, QString childName);

	public slots:
	void CloseReportForm();
public:
	BusinessLayer::OrmasBL* reportFormBL;
	QWidget* parentForm;
	QDialog* parentDialog;
	BusinessLayer::User* loggedUser;
	std::string errorMessage = "";
};
#endif //ReportFORM_H