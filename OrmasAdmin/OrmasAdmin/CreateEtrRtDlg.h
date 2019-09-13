#ifndef CREATEETRRTDLG_H
#define CREATEETRRTDLG_H
#include "ui_CreateEtrRtDlg.h"
#include "OrmasBL.h"
#include <QStandardItemModel>

class CreateEtrRtDlg : public QDialog, public Ui::CreateEntryRouting
{
	Q_OBJECT
public:
	CreateEtrRtDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateEtrRtDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateEntryRouting();
	void EditEntryRouting();
	void DeleteEntryRouting(){};
	void Close();
private:
	BusinessLayer::EntryRouting *entryRouting = new BusinessLayer::EntryRouting();
	void SetEntryRoutingParams(QString, int, int, int = 0);
	void FillEditElements(QString, int, int);
	void InitComboBox();
	QWidget* parentForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};

#endif //CREATEETRRTDLG_H