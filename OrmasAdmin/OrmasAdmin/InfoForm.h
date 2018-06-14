#ifndef INFOFORM_H
#define INFOFORM_H

#include "ui_InfoForm.h"
#include "OrmasBL.h"


class InfoForm : public QDialog, public Ui::AboutDlg
{
	Q_OBJECT
public:
	InfoForm(BusinessLayer::OrmasBL *ormasBL);
	~InfoForm(){};
	BusinessLayer::OrmasBL *oBL;
	private slots :
	void Close();
private:
	void CreateConnections();
};

#endif //INFOFORM_H