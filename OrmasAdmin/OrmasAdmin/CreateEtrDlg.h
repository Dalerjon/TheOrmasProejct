#ifndef CREATEETRDLG_H
#define CREATEETRDLG_H
#include "ui_CreateEtrDlg.h"
#include "OrmasBL.h"

class CreateEtrDlg : public QDialog, public Ui::CreateEntry
{
	Q_OBJECT
public:
	CreateEtrDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateEtrDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateEntry();
	void EditEntry();
	void DeleteEntry(){};
	void Close();
	void OpenDAccDlg();
	void OpenCAccDlg();
	void TextChanged();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Entry *entry = new BusinessLayer::Entry();
	void SetEntryParams(QString, int, double, int, int = 0);
	void FillEditElements(QString, int, double, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
};

#endif //CREATEETRDLG_H