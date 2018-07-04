#ifndef DOCFORM_H
#define DOCFORM_H

#include "ui_DocForm.h"
#include "OrmasBL.h"

class DocForm : public QWidget, public Ui::DocumentForm
{
	Q_OBJECT
public:
	DocForm(BusinessLayer::OrmasBL *ormasBL, QWidget *parent = 0);
	~DocForm();
	BusinessLayer::OrmasBL *dialogBL;
	std::string errorMessage = "";
	void SetContent(QString cont);
	private slots:
	void Save();
	void Close();
private:
	QString content;
};
#endif