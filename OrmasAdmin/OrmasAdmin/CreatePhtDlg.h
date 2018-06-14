#ifndef CREATEPHTDLG_H
#define CREATEPHTDLG_H
#include "ui_CreatePhtDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreatePhtDlg : public QDialog, public Ui::CreatePhoto
{
	Q_OBJECT
public:
	CreatePhtDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreatePhtDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreatePhoto();
	void EditPhoto();
	void DeletePhoto(){};
	void Close();
	void OpenUserDlg();
	void OpenPrdDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Photo *photo = new BusinessLayer::Photo();
	void SetPhotoParams(int, int, QString, int = 0);
	void FillEditElements(int, int, QString);
	QIntValidator *vInt = nullptr;
	QWidget* parentForm;
	MainForm* mainForm;
};
#endif //CREATECURDLG_H