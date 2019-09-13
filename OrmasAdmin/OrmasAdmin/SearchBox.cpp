#include "stdafx.h"
#include "searchbox.h"


SearchBox::SearchBox(QWidget *parent) : QLineEdit(parent)
{
	completer = new PSuggestCompletion(this);

	QObject::connect(this, &QLineEdit::textEdited, this, &SearchBox::doSearch);

	setWindowTitle("Search in DB");

	adjustSize();
	resize(400, height());
	setFocus();
}

void SearchBox::doSearch()
{
	completer->autoSuggest();
}

