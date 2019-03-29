#include "stdafx.h"
#include "SearchDlg.h"
#include "DataForm.h"

SearchInTableDlg::SearchInTableDlg(QWidget *parent)
{
	setupUi(this);
	parentForm = parent;
	CreateConnections();
}

void SearchInTableDlg::CreateConnections()
{
	QObject::connect(cancelBtn, &QPushButton::released, this, &SearchInTableDlg::Close);
	QObject::connect(searchBtn, &QPushButton::released, this, &SearchInTableDlg::Search);
	QObject::connect(this, SIGNAL(StartSearch(QString)), (DataForm*)parentForm, SLOT(Search(QString)));
}

void SearchInTableDlg::Close()
{
	this->parentWidget()->close();
}

void SearchInTableDlg::Search()
{
	emit StartSearch(searchEdit->text());
	Close();
}