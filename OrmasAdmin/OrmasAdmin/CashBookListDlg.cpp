#include "stdafx.h"
#include "CashBookListDlg.h"
#include "DocForm.h"

CashBookListDlg::CashBookListDlg(BusinessLayer::OrmasBL *ormasBL, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	parentForm = parent;
	mainForm = (MainForm *)this->parent();

	QDate currentDate = QDate::currentDate();
	forDateEdit->setDate(QDate::fromString(QDate::currentDate().toString(), "dd.MM.yyyy"));
	QObject::connect(okBtn, &QPushButton::released, this, &CashBookListDlg::Generate);
	QObject::connect(cancelBtn, &QPushButton::released, this, &CashBookListDlg::Close);
}

CashBookListDlg::~CashBookListDlg()
{

}


void CashBookListDlg::Generate()
{
	std::string errorMessage = "";
	BusinessLayer::Payment payment;
	BusinessLayer::Withdrawal withdrowal;
	payment.SetDate(forDateEdit->text().toUtf8().constData());
	std::string pmtFilter = payment.GenerateFilter(dialogBL->GetOrmasDal());
	std::vector<BusinessLayer::PaymentView> vecPmtRep = dialogBL->GetAllDataForClass<BusinessLayer::PaymentView>(errorMessage, pmtFilter);
	
	withdrowal.SetDate(forDateEdit->text().toUtf8().constData());
	std::string wthFilter = withdrowal.GenerateFilter(dialogBL->GetOrmasDal());
	std::vector<BusinessLayer::WithdrawalView> vecWthRep = dialogBL->GetAllDataForClass<BusinessLayer::WithdrawalView>(errorMessage, wthFilter);

	DocForm *docForm = new DocForm(dialogBL, this);
	docForm->setAttribute(Qt::WA_DeleteOnClose);
	docForm->setWindowTitle(tr("Print cash book list"));
	QMdiSubWindow *printRepWindow = new QMdiSubWindow;
	printRepWindow->setWidget(docForm);
	printRepWindow->setAttribute(Qt::WA_DeleteOnClose);
	printRepWindow->resize(docForm->size().width() + 18, docForm->size().height() + 30);
	((MainForm*)parentForm)->mdiArea->addSubWindow(printRepWindow);

	QFile file;
	file.setFileName(":/docs/cash_list.html");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find report tamplate!")),
			QString(tr("Ok")));
		return;
	}
	QString reportText = file.readAll();
	QString tableBody;
	if (vecPmtRep.size() == 0 && vecWthRep.size() == 0)
	{
		reportText.replace(QString("DatePh"), forDateEdit->text(), Qt::CaseInsensitive);
		reportText.replace(QString("CashSumPh"), QString::number(0), Qt::CaseInsensitive);
		reportText.replace(QString("TableBodyPh"), QString(""), Qt::CaseInsensitive);
		reportText.replace(QString("TodayInSumPh"), QString::number(0), Qt::CaseInsensitive);
		reportText.replace(QString("TodayOutSumPh"), QString::number(0), Qt::CaseInsensitive);
		reportText.replace(QString("TodayPastSumPh"), QString::number(0), Qt::CaseInsensitive);
		reportText.replace(QString("CachierNamePh"), QString(""), Qt::CaseInsensitive);
		reportText.replace(QString("AccounantNamePh"), QString(""), Qt::CaseInsensitive);
	}
	else
	{
		BusinessLayer::Role role;
		BusinessLayer::Employee accountant;
		BusinessLayer::Employee cashier;
		BusinessLayer::User user;
		BusinessLayer::Subaccount subAcc;
		BusinessLayer::Balance balance;

		if (!role.GetRoleIDByName(dialogBL->GetOrmasDal(), "CHIEF ACCOUNTANT", errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr("Connot find 'CHIEF ACCOUNTANT' role!")),
				QString(tr("Ok")));
			return;
		}
		
		accountant.SetRoleID(role.GetID());
		std::string empFilter = accountant.GenerateFilter(dialogBL->GetOrmasDal());
		std::vector<BusinessLayer::EmployeeView> vecEmpRep = dialogBL->GetAllDataForClass<BusinessLayer::EmployeeView>(errorMessage, empFilter);
		if (vecEmpRep.size() == 0)
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr("Connot find 'CHIEF ACCOUNTANT' employee!")),
				QString(tr("Ok")));
			return;
		}
		else
		{
			accountant.SetName(vecEmpRep.at(0).GetName());
			accountant.SetSurname(vecEmpRep.at(0).GetSurname());
		}

		role.Clear();
		if (!role.GetRoleIDByName(dialogBL->GetOrmasDal(), "CASHIER", errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr("Connot find 'CASHIER' role!")),
				QString(tr("Ok")));
			return;
		}

		cashier.SetRoleID(role.GetID());
		std::string casFilter = cashier.GenerateFilter(dialogBL->GetOrmasDal());
		std::vector<BusinessLayer::EmployeeView> vecCasRep = dialogBL->GetAllDataForClass<BusinessLayer::EmployeeView>(errorMessage, casFilter);
		if (vecCasRep.size() == 0)
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr("Connot find 'CASHIER' employee!")),
				QString(tr("Ok")));
			return;
		}
		else
		{
			cashier.SetName(vecCasRep.at(0).GetName());
			cashier.SetSurname(vecCasRep.at(0).GetSurname());
		}

		if (vecPmtRep.size() > 0)
		{
			for each (auto item in vecPmtRep)
			{
				payment.Clear();
				subAcc.Clear();
				balance.Clear();
				if (!payment.GetPaymentByID(dialogBL->GetOrmasDal(), item.GetID(), errorMessage))
				{
					QMessageBox::information(NULL, QString(tr("Info")),
						QString(tr("Payment is wrong!")),
						QString(tr("Ok")));
					return;
				}
				if (!balance.GetBalanceByUserID(dialogBL->GetOrmasDal(), item.GetUserID(), errorMessage))
				{
					QMessageBox::information(NULL, QString(tr("Info")),
						QString(tr("Can't find balance for this user!")),
						QString(tr("Ok")));
					return;
				}
				if (!subAcc.GetSubaccountByID(dialogBL->GetOrmasDal(), balance.GetSubaccountID(), errorMessage))
				{
					QMessageBox::information(NULL, QString(tr("Info")),
						QString(tr("Can't find subaccount for this user!")),
						QString(tr("Ok")));
					return;
				}
				tableBody += "<tr>";
				tableBody += "<td>" + QString::number(item.GetID()) + "</td>";
				tableBody += "<td>" + QString("Принято от ") + QString(item.GetUserSurname().c_str()) + " " + QString(item.GetUsername().c_str()) + "</td>";
				tableBody += "<td>" + QString(subAcc.GetNumber().c_str()) + "</td>";
				tableBody += "<td>" + QString::number(item.GetValue()) + "</td>";
				tableBody += "<td>" + QString("-") + "</td>";
				tableBody += "</tr>";
				InSum += item.GetValue();
			}
		}
		if (vecWthRep.size() > 0)
		{
			for each (auto item in vecWthRep)
			{
				withdrowal.Clear();
				subAcc.Clear();
				balance.Clear();
				user.Clear();
				if (!withdrowal.GetWithdrawalByID(dialogBL->GetOrmasDal(), item.GetID(), errorMessage))
				{
					QMessageBox::information(NULL, QString(tr("Info")),
						QString(tr("Withdrawal is wrong!")),
						QString(tr("Ok")));
					return;
				}
				if (!user.GetUserByID(dialogBL->GetOrmasDal(), item.GetUserID(), errorMessage))
				{
					QMessageBox::information(NULL, QString(tr("Info")),
						QString(tr("Can't find this user!")),
						QString(tr("Ok")));
					return;
				}
				if (!balance.GetBalanceByUserID(dialogBL->GetOrmasDal(), item.GetUserID(), errorMessage))
				{
					QMessageBox::information(NULL, QString(tr("Info")),
						QString(tr("Can't find balance for this user!")),
						QString(tr("Ok")));
					return;
				}
				if (!subAcc.GetSubaccountByID(dialogBL->GetOrmasDal(), balance.GetSubaccountID(), errorMessage))
				{
					QMessageBox::information(NULL, QString(tr("Info")),
						QString(tr("Can't find subaccount for this user!")),
						QString(tr("Ok")));
					return;
				}
				tableBody += "<tr>";
				tableBody += "<td>" + QString::number(item.GetID()) + "</td>";
				tableBody += "<td>" + QString("Принято от ") + QString(user.GetSurname().c_str()) + " " + QString(user.GetName().c_str()) + "</td>";
				tableBody += "<td>" + QString(subAcc.GetNumber().c_str()) + "</td>";
				tableBody += "<td>" + QString("-") + "</td>";
				tableBody += "<td>" + QString::number(item.GetValue()) + "</td>";
				tableBody += "</tr>";
				OutSum += item.GetValue();
			}
		}

		BusinessLayer::Account acc;
		if (!acc.GetAccountByNumber(dialogBL->GetOrmasDal(), "10110", errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Can't find account!")),
				QString(tr("Ok")));
			return;
		}

		reportText.replace(QString("DatePh"), forDateEdit->text(), Qt::CaseInsensitive);
		reportText.replace(QString("CashSumPh"), QString::number(acc.GetCurrentBalance() + InSum - OutSum), Qt::CaseInsensitive);
		reportText.replace(QString("TableBodyPh"), tableBody, Qt::CaseInsensitive);
		reportText.replace(QString("TodayInSumPh"), QString::number(InSum), Qt::CaseInsensitive);
		reportText.replace(QString("TodayOutSumPh"), QString::number(OutSum), Qt::CaseInsensitive);
		reportText.replace(QString("TodayPastSumPh"), QString::number(acc.GetCurrentBalance()), Qt::CaseInsensitive);
		reportText.replace(QString("CachierNamePh"), QString(cashier.GetSurname().c_str()) + " " + QString(cashier.GetName().c_str()), Qt::CaseInsensitive);
		reportText.replace(QString("AccounantNamePh"), QString(accountant.GetSurname().c_str()) + " " + QString(accountant.GetName().c_str()), Qt::CaseInsensitive);
	}

	docForm->webEngineView->setHtml(reportText);
	docForm->SetContent(reportText);
	docForm->webEngineView->show();
	docForm->show();
	Close();
}

void CashBookListDlg::Close()
{
	this->parentWidget()->close();
}

