#ifndef REWORKRAWDLG_H
#define REWORKRAWDLG_H
#include "ui_ReworkRawDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class ReworkRawDlg : public QDialog, public Ui::ReworkRaw
{
	Q_OBJECT
public:
	ReworkRawDlg(BusinessLayer::OrmasBL *ormasBL, QWidget *parent = 0);
	~ReworkRawDlg();
	BusinessLayer::OrmasBL *dialogBL;
	std::string errorMessage;
	private slots:
	void Rework();
	void Close();
	void OpenProdDlg();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Product product;
	BusinessLayer::Specification spec;
	QDoubleValidator *vDouble = nullptr;
	QWidget* parentForm;
	MainForm* mainForm;
};
#endif //ReworkRawDLG_H