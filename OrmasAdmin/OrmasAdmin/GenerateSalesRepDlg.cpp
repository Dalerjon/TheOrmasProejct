#include "stdafx.h"
#include "GenerateSalesRepDlg.h"
#include "MainForm.h"
#include "DocForm.h"


GenerateSalesRep::GenerateSalesRep(BusinessLayer::OrmasBL *ormasBL, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	parentForm = parent;
	mainForm = (MainForm *)this->parent();

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

	QObject::connect(okBtn, &QPushButton::released, this, &GenerateSalesRep::Generate);
	QObject::connect(cancelBtn, &QPushButton::released, this, &GenerateSalesRep::Close);
}

GenerateSalesRep::~GenerateSalesRep()
{
}

void GenerateSalesRep::Generate()
{
	BusinessLayer::Status status;
	if (!status.GetStatusByName(dialogBL->GetOrmasDal(), "EXECUTED", errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Please contact with administrator, you have same troubles with statuses!")),
			QString(tr("Ok")));
		return;
	}

	BusinessLayer::Employee employee;
	BusinessLayer::Role role;
	role.SetName("EXPEDITOR");
	std::string filterRole = role.GenerateFilter(dialogBL->GetOrmasDal());
	std::vector<BusinessLayer::Role> vecRole = dialogBL->GetAllDataForClass<BusinessLayer::Role>(errorMessage, filterRole);
	if (vecRole.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Please contact with administrator, you have same troubles with roles!")),
			QString(tr("Ok")));
		return;
	}

	employee.SetRoleID(vecRole.at(0).GetID());
	std::string filterEmployee = employee.GenerateFilter(dialogBL->GetOrmasDal());
	std::vector<BusinessLayer::EmployeeView> vecEmployee = dialogBL->GetAllDataForClass<BusinessLayer::EmployeeView>(errorMessage, filterEmployee);
	if (vecEmployee.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find any expeditor!")),
			QString(tr("Ok")));
		return;
	}
	else
	{
		DocForm *docForm = new DocForm(dialogBL, this);
		docForm->setAttribute(Qt::WA_DeleteOnClose);
		docForm->setWindowTitle(tr("Print products profitability report"));
		QMdiSubWindow *generateProfRepWindow = new QMdiSubWindow;
		generateProfRepWindow->setWidget(docForm);
		generateProfRepWindow->setAttribute(Qt::WA_DeleteOnClose);
		generateProfRepWindow->resize(docForm->size().width() + 18, docForm->size().height() + 30);
		mainForm->mdiArea->addSubWindow(generateProfRepWindow);

		//read template
		QFile file;
		file.setFileName(":/docs/sales.html");
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Cannot find sales report tamplate!")),
				QString(tr("Ok")));
			return;
		}
		QString reportText = file.readAll();

		BusinessLayer::Order order;
		BusinessLayer::OrderList orderList;
		std::string orderListFilter;
		std::map<int, double> productCount;
		std::map<int, double> productSum;
		std::vector<BusinessLayer::OrderListView> vecOrderList;
		BusinessLayer::Product product;
		BusinessLayer::NetCost nCost;
		double sum = 0;
		QString documentBody;
		QString tableBody;


		reportText.replace(QString("fromDatePh"), fromDateEdit->text(), Qt::CaseInsensitive);
		reportText.replace(QString("tillDatePh"), tillDateEdit->text(), Qt::CaseInsensitive);

		for each (BusinessLayer::EmployeeView expeditor in vecEmployee)
		{
			tableBody.clear();
			order.Clear();
			order.SetStatusID(status.GetID());
			order.SetEmployeeID(expeditor.GetID());
			std::string filter = order.GenerateFilterForPeriod(dialogBL->GetOrmasDal(), fromDateEdit->text().toUtf8().constData(), tillDateEdit->text().toUtf8().constData());
			std::vector<BusinessLayer::OrderView> vecOrder = dialogBL->GetAllDataForClass<BusinessLayer::OrderView>(errorMessage, filter);
			if (vecOrder.size() == 0)
			{
				continue;
			}
			else
			{
				//generating report
				if (vecOrder.size() > 0)
				{
					productCount.clear();
					productSum.clear();
					sum = 0;
					tableBody += "���������: ";
					tableBody += expeditor.GetSurname().c_str();
					tableBody += " ";
					tableBody += expeditor.GetName().c_str();
					tableBody += "  ";
					tableBody += "�������: ";
					tableBody += expeditor.GetPhone().c_str();
					tableBody += "<br/>";

					tableBody += "<table width='100 % ' border = 1px  cellpadding=5 style='border-spacing:0px; '>";
					tableBody += "<th><b>" + QString::fromUtf8("ID ��������")+"< / b>< / th>";
					tableBody += "<th><b>������������ ��������</b></th>";
					tableBody += "<th><b>����������</b></th>";
					tableBody += "<th><b>�����</b></th>";
					
					for each (auto item in vecOrder)
					{
						orderList.Clear();
						orderListFilter.clear();
						orderList.SetOrderID(item.GetID());
						orderListFilter = orderList.GenerateFilter(dialogBL->GetOrmasDal());
						vecOrderList.clear();
						vecOrderList = dialogBL->GetAllDataForClass<BusinessLayer::OrderListView>(errorMessage, orderListFilter);
						if (vecOrderList.size() > 0)
						{
							for each (auto listItem in vecOrderList)
							{
								if (productCount.find(listItem.GetProductID()) != productCount.end())
								{
									productCount.find(listItem.GetProductID())->second = productCount.find(listItem.GetProductID())->second + listItem.GetCount();
									productSum.find(listItem.GetProductID())->second = productSum.find(listItem.GetProductID())->second + listItem.GetSum();
								}
								else
								{
									productCount.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
									productSum.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
								}
							}
						}
					}

					if (productCount.size() != productSum.size())
					{
						QMessageBox::information(NULL, QString(tr("Info")),
							QString(tr("Calculation is failed. Please restart the report!")),
							QString(tr("Ok")));
						return;
					}
									
					for each (auto mapCountItem in productCount)
					{
						product.Clear();
						product.GetProductByID(dialogBL->GetOrmasDal(), mapCountItem.first, errorMessage);
						nCost.Clear();
						nCost.GetNetCostByProductID(dialogBL->GetOrmasDal(), mapCountItem.first, errorMessage);
						sum += productSum.find(mapCountItem.first)->second;
						tableBody += "<tr>";
						tableBody += "<td>" + QString::number(mapCountItem.first) + "</td>";
						tableBody += "<td>" + QString(product.GetName().c_str()) + "</td>";
						tableBody += "<td>" + QString::number(mapCountItem.second) + "</td>";
						tableBody += "<td>" + QString::number(productSum.find(mapCountItem.first)->second, 'f', 3) + "</td>";
						tableBody += "</tr>";
					}

					tableBody += "<tr>";
					tableBody += "<td></td>";
					tableBody += "<td></td>";
					tableBody += "<td>"+ QString::fromUtf8("��� �������") + "</td>";
					tableBody += "<td>" + QString::number(sum, 'f', 3) + "</td>";
					tableBody += "</tr>";
					tableBody += "</table>";
					tableBody += "<br/><br/>";

				}
				else
				{
					tableBody += "��� ������!";
				}
			}
			documentBody += tableBody;
		}
		reportText.replace(QString("DocumentBodyPh"), documentBody, Qt::CaseInsensitive);
		docForm->webEngineView->setHtml(reportText);
		docForm->SetContent(reportText);
		docForm->webEngineView->show();
		docForm->show();
	}
	Close();
}

void GenerateSalesRep::Close()
{
	this->parentWidget()->close();
}
