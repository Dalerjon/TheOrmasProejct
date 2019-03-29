#ifndef SEARCHDLG_H
#define SEARCHDLG_H

#include "ui_SearchDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class SearchInTableDlg : public QDialog, public Ui::SearchInTable
{
	Q_OBJECT
public:
	SearchInTableDlg(QWidget *parent = 0);
	~SearchInTableDlg(){};
	BusinessLayer::OrmasBL *oBL;
	private slots :
	void Close();
	void Search();
signals:
	void StartSearch(QString);
private:
	void CreateConnections();
	QWidget* parentForm;
};

#endif //SearchFORM_H