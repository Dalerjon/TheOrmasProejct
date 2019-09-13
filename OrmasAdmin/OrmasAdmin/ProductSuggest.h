#ifndef PRODUCTSUGGEST_H
#define PRODUCTSUGGEST_H

#include <QtWidgets>
#include <QtCore>
//#include "MainForm.h"
#include "DataForm.h"

class PSuggestCompletion : public QObject
{
	Q_OBJECT

public:
	explicit PSuggestCompletion(QLineEdit *parent = nullptr);
	~PSuggestCompletion();
	bool eventFilter(QObject *obj, QEvent *ev) override;
	void showCompletion(QMap<QString,int> &choices);

	public slots:
	void doneCompletion();
	void autoSuggest();
signals:
	void ProductIsChosen(int);

private:
	QLineEdit *editor = nullptr;
	QTreeWidget *popup = nullptr;
	QDialog *dialogParent;
	DataForm *dataFormParent;
	QTimer timer;
};
#endif // PRODUCTSUGGEST_H