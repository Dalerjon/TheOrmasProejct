#include "stdafx.h"
#include "GenerateAccRepDlg.h"
#include "MainForm.h"
#include "DocForm.h"
#include "DataForm.h"


GenerateAccCardRep::GenerateAccCardRep(BusinessLayer::OrmasBL *ormasBL, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	parentForm = parent;
	mainForm = (MainForm *)this->parent();
	vInt = new QIntValidator(0, 1000000000, this);
	accIDEdit->setValidator(vInt);

	QDate currentDate = QDate::currentDate();
	int day = currentDate.day();
	int month = currentDate.month();
	int year = currentDate.year();

	std::string startDate;
	std::string endDate;
	std::string reportingMonth;
	QDate pastMonthDate;
	int coundOfDays; //  = pastMonthDate.daysInMonth();

	if (day < 15 && month == 1)
	{
		startDate = "01.";
		startDate += std::to_string(12);
		startDate += ".";
		startDate += std::to_string(year - 1);
		pastMonthDate = (QDate::fromString(startDate.c_str(), "dd.MM.yyyy"));
		coundOfDays = pastMonthDate.daysInMonth();
		endDate = std::to_string(coundOfDays);
		endDate += ".";
		endDate += std::to_string(12);
		endDate += ".";
		endDate += std::to_string(year - 1);
		//previous month
		prevFromMonth = "01.";
		prevFromMonth += std::to_string(11);
		prevFromMonth += ".";
		prevFromMonth += std::to_string(year - 1);
		pastMonthDate = (QDate::fromString(prevFromMonth.c_str(), "dd.MM.yyyy"));
		coundOfDays = pastMonthDate.daysInMonth();
		prevTillMonth = std::to_string(coundOfDays);
		prevTillMonth += ".";
		prevTillMonth += std::to_string(11);
		prevTillMonth += ".";
		prevTillMonth += std::to_string(year - 1);
	}
	if (day > 15 && month == 1)
	{
		startDate = "01.";
		startDate += std::to_string(1);
		startDate += ".";
		startDate += std::to_string(year);
		pastMonthDate = (QDate::fromString(startDate.c_str(), "dd.MM.yyyy"));
		coundOfDays = pastMonthDate.daysInMonth();
		endDate = std::to_string(coundOfDays);
		endDate += ".";
		endDate += std::to_string(1);
		endDate += ".";
		endDate += std::to_string(year);
		//previous month
		prevFromMonth = "01.";
		prevFromMonth += std::to_string(12);
		prevFromMonth += ".";
		prevFromMonth += std::to_string(year - 1);
		pastMonthDate = (QDate::fromString(prevFromMonth.c_str(), "dd.MM.yyyy"));
		coundOfDays = pastMonthDate.daysInMonth();
		prevTillMonth = std::to_string(coundOfDays);
		prevTillMonth += ".";
		prevTillMonth += std::to_string(12);
		prevTillMonth += ".";
		prevTillMonth += std::to_string(year - 1);
	}
	if (day > 15 && month > 1)
	{
		startDate = "01.";
		startDate += std::to_string(month);
		startDate += ".";
		startDate += std::to_string(year);
		pastMonthDate = (QDate::fromString(startDate.c_str(), "dd.MM.yyyy"));
		coundOfDays = pastMonthDate.daysInMonth();
		endDate = std::to_string(coundOfDays);
		endDate += ".";
		endDate += std::to_string(month);
		endDate += ".";
		endDate += std::to_string(year);
		//previous month
		prevFromMonth = "01.";
		prevFromMonth += std::to_string(month - 1);
		prevFromMonth += ".";
		prevFromMonth += std::to_string(year);
		pastMonthDate = (QDate::fromString(prevFromMonth.c_str(), "dd.MM.yyyy"));
		coundOfDays = pastMonthDate.daysInMonth();
		prevTillMonth = std::to_string(coundOfDays);
		prevTillMonth += ".";
		prevTillMonth += std::to_string(month - 1);
		prevTillMonth += ".";
		prevTillMonth += std::to_string(year);
	}
	if (day < 15 && month > 1)
	{
		startDate = "01.";
		startDate += std::to_string(month - 1);
		startDate += ".";
		startDate += std::to_string(year);
		pastMonthDate = (QDate::fromString(startDate.c_str(), "dd.MM.yyyy"));
		coundOfDays = pastMonthDate.daysInMonth();
		endDate = std::to_string(coundOfDays);
		endDate += ".";
		endDate += std::to_string(month - 1);
		endDate += ".";
		endDate += std::to_string(year);
		//previous month
		if (month == 2)
		{
			prevFromMonth = "01.";
			prevFromMonth += std::to_string(12);
			prevFromMonth += ".";
			prevFromMonth += std::to_string(year - 1);
			pastMonthDate = (QDate::fromString(prevFromMonth.c_str(), "dd.MM.yyyy"));
			coundOfDays = pastMonthDate.daysInMonth();
			prevTillMonth = std::to_string(coundOfDays);
			prevTillMonth += ".";
			prevTillMonth += std::to_string(12);
			prevTillMonth += ".";
			prevTillMonth += std::to_string(year - 1);
		}
		if (month > 2)
		{
			prevFromMonth = "01.";
			prevFromMonth += std::to_string(month - 2);
			prevFromMonth += ".";
			prevFromMonth += std::to_string(year);
			pastMonthDate = (QDate::fromString(prevFromMonth.c_str(), "dd.MM.yyyy"));
			coundOfDays = pastMonthDate.daysInMonth();
			prevTillMonth = std::to_string(coundOfDays);
			prevTillMonth += ".";
			prevTillMonth += std::to_string(month - 2);
			prevTillMonth += ".";
			prevTillMonth += std::to_string(year);
		}
	}
	fromDateEdit->setDate(QDate::fromString(startDate.c_str(), "dd.MM.yyyy"));
	tillDateEdit->setDate(QDate::fromString(endDate.c_str(), "dd.MM.yyyy"));

	QObject::connect(accBtn, &QPushButton::released, this, &GenerateAccCardRep::OpenAccDlg);
	QObject::connect(sAccBtn, &QPushButton::released, this, &GenerateAccCardRep::OpenSAccDlg);
	QObject::connect(accNumberEdit, &QLineEdit::textChanged, this, &GenerateAccCardRep::AccTextChanged);
	QObject::connect(okBtn, &QPushButton::released, this, &GenerateAccCardRep::Generate);
	QObject::connect(this, SIGNAL(CloseCreatedForms()), ((MainForm*)((DataForm*)parent)->GetParent()), SLOT(CloseChildsByName()));
	QObject::connect(cancelBtn, &QPushButton::released, this, &GenerateAccCardRep::Close);
}

GenerateAccCardRep::~GenerateAccCardRep()
{
	delete vInt;
	emit CloseCreatedForms();
}

void GenerateAccCardRep::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			this->hide();
			this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
			this->show();
			this->raise();
			this->activateWindow();
			QApplication::setActiveWindow(this);

			if (childName == QString("accountForm"))
			{
				accIDEdit->setText(QString::number(ID));
				BusinessLayer::Account account;
				if (account.GetAccountByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					accNumberEdit->setReadOnly(true);
					accNumberEdit->setText(account.GetNumber().c_str());
				}
			}
			if (childName == QString("subaccountForm"))
			{
				accIDEdit->setText(QString::number(ID));
				BusinessLayer::Subaccount subaccount;
				if (subaccount.GetSubaccountByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					accNumberEdit->setReadOnly(true);
					accNumberEdit->setText(subaccount.GetNumber().c_str());
				}
			}
		}
	}
}

void GenerateAccCardRep::Generate()
{
	if (accIDEdit->text().isEmpty() || 0 == accIDEdit->text().toInt())
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Please select account at first!")),
			QString(tr("Ok")));
		return;
	}

	BusinessLayer::Account acc;
	BusinessLayer::Subaccount subacc;
	BusinessLayer::Entry entry;
	bool isSubaccount = false;
	std::vector<BusinessLayer::EntryView> vecEntryDeb;
	std::string filterDebit;
	if (acc.GetAccountByID(dialogBL->GetOrmasDal(), accIDEdit->text().toInt(), errorMessage))
	{
		filterDebit.clear();
		entry.Clear();
		vecEntryDeb.clear();
		entry.SetDebitingAccountID(accIDEdit->text().toInt());
		filterDebit = entry.GenerateFilterForPeriod(dialogBL->GetOrmasDal(), fromDateEdit->text().toUtf8().constData(), tillDateEdit->text().toUtf8().constData());
		vecEntryDeb = dialogBL->GetAllDataForClass<BusinessLayer::EntryView>(errorMessage, filterDebit);
	}
	else if (subacc.GetSubaccountByID(dialogBL->GetOrmasDal(), accIDEdit->text().toInt(), errorMessage))
	{
		filterDebit.clear();
		entry.Clear();
		vecEntryDeb.clear();
		entry.SetDebitingAccountID(subacc.GetParentAccountID());
		filterDebit = entry.GenerateFilterForPeriod(dialogBL->GetOrmasDal(), fromDateEdit->text().toUtf8().constData(), tillDateEdit->text().toUtf8().constData());
		vecEntryDeb = dialogBL->GetAllDataForClass<BusinessLayer::EntryView>(errorMessage, filterDebit);
		isSubaccount = true;
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warrning")),
			QString(tr("Cannot find account")),
			QString(tr("Ok")));
		return;
	}
	if (vecEntryDeb.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find any entry for this period!")),
			QString(tr("Ok")));
		return;
	}
	else
	{
		DocForm *docForm = new DocForm(dialogBL, this);
		docForm->setAttribute(Qt::WA_DeleteOnClose);
		docForm->setWindowTitle(tr("Print products account card report"));
		QMdiSubWindow *generateAccRepWindow = new QMdiSubWindow;
		generateAccRepWindow->setWidget(docForm);
		generateAccRepWindow->setAttribute(Qt::WA_DeleteOnClose);
		generateAccRepWindow->resize(docForm->size().width() + 18, docForm->size().height() + 30);
		mainForm->mdiArea->addSubWindow(generateAccRepWindow);

		//read template
		QFile file;
		file.setFileName(":/docs/account_card.html");
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Cannot find account card report tamplate!")),
				QString(tr("Ok")));
			return;
		}
		QString reportText = file.readAll();
		QString tableBody;
		double fromDebSum = 0;
		double fromCredSum = 0;
		double curDebSum = 0;
		double curCredSum = 0;
		double tillDebSumPh = 0;
		double tillCredSumPh = 0;
		reportText.replace(QString("fromDatePh"), fromDateEdit->text(), Qt::CaseInsensitive);
		reportText.replace(QString("tillDatePh"), tillDateEdit->text(), Qt::CaseInsensitive);
		//generating report
		if (vecEntryDeb.size() > 0)
		{
			if (isSubaccount == false)
			{
				for each (auto item in vecEntryDeb)
				{
					/*tableBody += "<tr>";
					tableBody += "<td style='border: 1px solid black; text - align: center; padding:0px;'>";
					tableBody += "<td>" + QString(product.GetName().c_str()) + "</td>";
					tableBody += "<td>" + QString::number(mapCountItem.second) + "</td>";
					tableBody += "<td>" + QString::number(nCost.GetValue()*mapCountItem.second) + "</td>";
					tableBody += "<td>" + QString::number(productSum.find(mapCountItem.first)->second) + "</td>";
					tableBody += "<td>" + QString::number(productSum.find(mapCountItem.first)->second - nCost.GetValue()*mapCountItem.second) + "</td>";
					tableBody += "</tr>";*/
				}
			}
			else
			{
				for each (auto item in vecEntryDeb)
				{
					/*tableBody += "<tr>";
					tableBody += "<td>" + QString::number(mapCountItem.first) + "</td>";
					tableBody += "<td>" + QString(product.GetName().c_str()) + "</td>";
					tableBody += "<td>" + QString::number(mapCountItem.second) + "</td>";
					tableBody += "<td>" + QString::number(nCost.GetValue()*mapCountItem.second) + "</td>";
					tableBody += "<td>" + QString::number(productSum.find(mapCountItem.first)->second) + "</td>";
					tableBody += "<td>" + QString::number(productSum.find(mapCountItem.first)->second - nCost.GetValue()*mapCountItem.second) + "</td>";
					tableBody += "</tr>";*/
				}
			}
		

			reportText.replace(QString("TableBodyPh"), tableBody, Qt::CaseInsensitive);

		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Report is empty! Cannot print it")),
				QString(tr("Ok")));
			return;
		}
	}
}

void GenerateAccCardRep::Close()
{
	this->parentWidget()->close();
}

void GenerateAccCardRep::OpenAccDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Accounts"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::Account>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->parentDialog = this;
		dForm->setObjectName("accountForm");
		dForm->QtConnect<BusinessLayer::Account>();
		QMdiSubWindow *dAccountWindow = new QMdiSubWindow;
		dAccountWindow->setWidget(dForm);
		dAccountWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(dAccountWindow);
		dAccountWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		dForm->setWindowFlags(dForm->windowFlags() | Qt::WindowStaysOnTopHint);
		QString message = tr("All accounts are shown");
		mainForm->statusBar()->showMessage(message);
	}
	else
	{
		delete dForm;
		QString message = tr("End with error!");
		mainForm->statusBar()->showMessage(message);
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr(errorMessage.c_str())),
			QString(tr("Ok")));
		errorMessage = "";
	}
}

void GenerateAccCardRep::OpenSAccDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Subccounts"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::SubaccountView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->parentDialog = this;
		dForm->setObjectName("subaccountForm");
		dForm->QtConnect<BusinessLayer::SubaccountView>();
		QMdiSubWindow *dSAccountWindow = new QMdiSubWindow;
		dSAccountWindow->setWidget(dForm);
		dSAccountWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(dSAccountWindow);
		dSAccountWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		dForm->setWindowFlags(dForm->windowFlags() | Qt::WindowStaysOnTopHint);
		QString message = tr("All subaccounts are shown");
		mainForm->statusBar()->showMessage(message);
	}
	else
	{
		delete dForm;
		QString message = tr("End with error!");
		mainForm->statusBar()->showMessage(message);
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr(errorMessage.c_str())),
			QString(tr("Ok")));
		errorMessage = "";
	}
}



void GenerateAccCardRep::AccTextChanged()
{
	if (accNumberEdit->text().length() == 5 || accNumberEdit->text().length() == 6)
	{
		BusinessLayer::Account account;
		if (account.GetAccountByNumber(dialogBL->GetOrmasDal(), accNumberEdit->text().toUtf8().constData(), errorMessage))
		{
			accIDEdit->setText(QString::number(account.GetID()));
			if (account.GetName(dialogBL->GetOrmasDal()).c_str() != nullptr)
				accNamePh->setText(account.GetName(dialogBL->GetOrmasDal()).c_str());
		}
		else
		{
			accNamePh->setText(tr("Incorrect account number!"));
			accIDEdit->setText("");
		}
	}
	else if (accNumberEdit->text().length() == 15)
	{
		BusinessLayer::Subaccount subaccount;
		if (subaccount.GetSubaccountByNumber(dialogBL->GetOrmasDal(), accNumberEdit->text().toUtf8().constData(), errorMessage))
		{
			accIDEdit->setText(QString::number(subaccount.GetID()));
			if (subaccount.GetName(dialogBL->GetOrmasDal()).c_str() != nullptr)
				accNamePh->setText(subaccount.GetName(dialogBL->GetOrmasDal()).c_str());
		}
		else
		{
			accNamePh->setText(tr("Incorrect account number!"));
			accIDEdit->setText("");
		}
	}
	else
	{
		accNamePh->setText("");
		accIDEdit->setText("");
	}
}
