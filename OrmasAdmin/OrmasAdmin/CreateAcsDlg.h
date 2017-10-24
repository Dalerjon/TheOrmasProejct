#ifndef CREATEACSDLG_H
#define CREATEACSDLG_H
#include "ui_CreateAcsDlg.h"
#include "OrmasBL.h"

class CreateAcsDlg : public QDialog, public Ui::CreateAccess
{
	Q_OBJECT
public:
	CreateAcsDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateAcsDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateAccess();
	void EditAccess();
	void DeleteAccess(){};
	void Close();
	void OpenRoleDlg();
	void OpenAcsItemDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Access *access = new BusinessLayer::Access();
	void SetAccessParams(int, int, int = 0);
	void FillEditElements(int, int);
	QIntValidator *vInt = nullptr;
};

#endif //CREATEACSDLG_H
