#ifndef SEARCHBOX_H
#define SEARCHBOX_H

#include <QLineEdit>
#include "ProductSuggest.h"

class SearchBox : public QLineEdit
{
	Q_OBJECT
public:
	explicit SearchBox(QWidget *parent = nullptr);

	protected slots:
	void doSearch();

private:
	PSuggestCompletion *completer = nullptr;
};


#endif // SEARCHBOX_H