#include "stdafx.h"
#include "GenerateOneAccDlg.h"
#include "MainForm.h"
#include "ExtraFunctions.h"
#include <QMessageBox>
#include <QProgressDialog>


GenerateOneAcc::GenerateOneAcc(BusinessLayer::OrmasBL *ormasBL, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	InitComboBox();
	vInt = new QIntValidator(0, 1000000000, this);
	chartOfAccEdit->setValidator(vInt);
	QObject::connect(generateBtn, &QPushButton::released, this, &GenerateOneAcc::Generate);
	QObject::connect(cancelBtn, &QPushButton::released, this, &GenerateOneAcc::Close);
	QObject::connect(chartOfAccEdit, &QLineEdit::textChanged, this, &GenerateOneAcc::OpenCOADlg);
	QObject::connect(this, SIGNAL(CloseCreatedForms()), ((MainForm*)((DataForm*)parent)->GetParent()), SLOT(CloseChildsByName()));
}

GenerateOneAcc::~GenerateOneAcc()
{
	delete account;
	delete status;
	delete caRelation;
	emit CloseCreatedForms();
}

void GenerateOneAcc::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			if (childName == QString("chartOfAccountForm"))
			{
				chartOfAccEdit->setText(QString::number(ID));
				BusinessLayer::ChartOfAccounts coAcc;
				if (coAcc.GetChartOfAccountsByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					accNamePh->setText(coAcc.GetName().c_str());
				}
			}
		}
	}
}

void GenerateOneAcc::Generate()
{
	BusinessLayer::AccountType acType;
	BusinessLayer::Currency currency;
	std::string number = "";
	std::string genAccRawNumber = "";

	if (!currencyCmb->currentText().isEmpty() && !currencyCmb->currentText().isEmpty() && 0 != chartOfAccEdit->text().toInt())
	{
		status->SetName("OPEN");
		std::string statusFilter = dialogBL->GenerateFilter<BusinessLayer::Status>(status);
		std::vector<BusinessLayer::Status> statusVector = dialogBL->GetAllDataForClass<BusinessLayer::Status>(errorMessage, statusFilter);
		if (0 == statusVector.size())
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr("Status is empty please contact with Administrator")),
				QString(tr("Ok")));
			errorMessage.clear();
			Close();
		}
		status->SetID(statusVector.at(0).GetID());

		BusinessLayer::ChartOfAccounts coAcc;
		if (!coAcc.GetChartOfAccountsByID(dialogBL->GetOrmasDal(), chartOfAccEdit->text().toInt(), errorMessage))
		{
			dialogBL->CancelTransaction(errorMessage);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			errorMessage.clear();
			return;
		}
		if (!acType.GetAccountTypeByID(dialogBL->GetOrmasDal(), coAcc.GetAccountTypeID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr("Account type is empty please contact with Administrator")),
				QString(tr("Ok")));
			errorMessage.clear();
			Close();
		}
		if (!currency.GetCurrencyByID(dialogBL->GetOrmasDal(), currencyCmb->currentData().toInt(), errorMessage))
		{
			dialogBL->CancelTransaction(errorMessage);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			errorMessage.clear();
			return;
		}

		number = std::to_string(coAcc.GetNumber());
		number.append(std::to_string(currency.GetCode()));
		number.append(std::to_string(acType.GetNumber()));
		genAccRawNumber = account->GenerateRawNumber(dialogBL->GetOrmasDal(), errorMessage);
		if (genAccRawNumber.empty())
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Cannot generate account number! Please contact with Administrator!")),
				QString(tr("Ok")));
			Close();
		}
		number.append(genAccRawNumber);
		account->Clear();
		account->SetNumber(number);
		account->SetStartBalance(0.0);
		account->SetCurrentBalance(0.0);
		account->SetCurrencyID(currencyCmb->currentData().toInt());
		account->SetStatusID(status->GetID());
		account->SetOpenedDate(dialogBL->GetOrmasDal().GetSystemDate());
		account->SetClosedDate("");
		account->SetDetails("");

		if (!account->CreateAccount(dialogBL->GetOrmasDal(), errorMessage))
		{
			caRelation->Clear();
			caRelation->SetAccountID(account->GetID());
			caRelation->SetCompanyID(companyCmb->currentData().toInt());
			if (!caRelation->CreateCompanyAccountRelation(dialogBL->GetOrmasDal(), errorMessage))
			{
				QMessageBox::information(NULL, QString(tr("Info")),
					QString(tr("Cannot create relation with generated account and company! Please contact with Administrator!")),
					QString(tr("Ok")));
				Close();
			}
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Cannot generate account! Please contact with Administrator!")),
				QString(tr("Ok")));
			Close();
		}
		number = "";
		genAccRawNumber = "";
	}
}

void GenerateOneAcc::Close()
{
	this->close();
}

void GenerateOneAcc::OpenCOADlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Chart of accounts"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);

	dForm->FillTable<BusinessLayer::ChartOfAccountsView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->generateOneAcc = this;
		dForm->setObjectName("chartOfAccountForm");
		dForm->QtConnect<BusinessLayer::ChartOfAccountsView>();
		QMdiSubWindow *coAccWindow = new QMdiSubWindow;
		coAccWindow->setWidget(dForm);
		coAccWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(coAccWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All statuses are shown");
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

void GenerateOneAcc::InitComboBox()
{
	std::vector<BusinessLayer::Currency> curVector = dialogBL->GetAllDataForClass<BusinessLayer::Currency>(errorMessage);
	if (!curVector.empty())
	{
		for (unsigned int i = 0; i < curVector.size(); i++)
		{
			currencyCmb->addItem(curVector[i].GetShortName().c_str(), QVariant(curVector[i].GetID()));
		}
	}

	std::vector<BusinessLayer::Company> comVector = dialogBL->GetAllDataForClass<BusinessLayer::Company>(errorMessage);
	if (!comVector.empty())
	{
		for (unsigned int i = 0; i < comVector.size(); i++)
		{
			currencyCmb->addItem(comVector[i].GetName().c_str(), QVariant(comVector[i].GetID()));
		}
	}
}