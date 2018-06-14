#include "stdafx.h"
#include "InfoForm.h"

InfoForm::InfoForm(BusinessLayer::OrmasBL *ormasBL)
{
	setupUi(this);
	oBL = ormasBL;
	CreateConnections();
}

void InfoForm::CreateConnections()
{
	QObject::connect(closeBtn, &QPushButton::released, this, &InfoForm::Close);
}

void InfoForm::Close()
{
	this->close();
}