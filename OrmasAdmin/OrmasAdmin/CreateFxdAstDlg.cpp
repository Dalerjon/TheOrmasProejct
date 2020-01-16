#include "stdafx.h"

#include "CreateFxdAstDlg.h"
#include "DataForm.h"

#include <map>

CreateFxdAstDlg::CreateFxdAstDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	//setModal(true);
	dialogBL = ormasBL;
	parentForm = parent;
	DataForm *dataFormParent = (DataForm *)this->parentForm;
	mainForm = (MainForm *)dataFormParent->GetParent();
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	faNameEdit->setMaxLength(200);
	factoryNumEdit->setMaxLength(30);
	developerEdit->setMaxLength(100);
	documentEdit->setMaxLength(200);
	objCharEdit->setMaxLength(400);
	conditionEdit->setMaxLength(100);
	consDateEdit->setDate(QDate::currentDate());

	locationEdit->setMaxLength(200);
	primaryCostEdit->setValidator(vDouble);
	primaryCostEdit->setMaxLength(20);
	amortizeEdit->setValidator(vDouble);
	amortizeEdit->setMaxLength(20);
	statusEdit->setValidator(vInt);
	barcodeEdit->setMaxLength(50);
	amValueEdit->setValidator(vDouble);
	primaryCostEdit->setMaxLength(20);
	
	invNumberEdit->setMaxLength(50);
	primaryEdit->setValidator(vDouble);
	primaryEdit->setMaxLength(20);
	stopEdit->setValidator(vDouble);
	stopEdit->setMaxLength(20);
	serviceLifeEdit->setValidator(vInt);

	
	specBtn->setVisible(false);
	specIDEdit->hide();
	detailsIDEdit->hide();

	accableIDEdit->setValidator(vInt);
	purEditID->setValidator(vInt);
	accID->setValidator(vInt);

	InitComboBox();
	
	//sourceGbx->hide();

	if (true == updateFlag)
	{
		accableBtn->hide();
		accountBtn->hide();
		purveyorBtn->hide();
		fAstTypeCmb->setAcceptDrops(false);
		specGrpBox->hide();
		amValueEdit->setReadOnly(true);
		amortizeEdit->setReadOnly(true);
		primaryEdit->setReadOnly(true);
		stopEdit->setReadOnly(true);
		serviceLifeEdit->setReadOnly(true);
		amGrpCmb->hide();
		amTypeCmb->hide();
		divisionCmb->hide();
		DataForm *parentDataForm = (DataForm*)parentForm;
		itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
		mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
		QObject::connect(okBtn, &QPushButton::released, this, &CreateFxdAstDlg::EditFixedAssets);
	}
	else
	{
		buyDateEdit->setDate(QDate::currentDate());
		startDateEdit->setDate(QDate::currentDate());
		GenerateInventoryNumber();
		BusinessLayer::Status *status = new BusinessLayer::Status();
		status->SetName("IN STOCK");
		std::string statusFilter = dialogBL->GenerateFilter<BusinessLayer::Status>(status);
		std::vector<BusinessLayer::Status> statusVector = dialogBL->GetAllDataForClass<BusinessLayer::Status>(errorMessage, statusFilter);
		delete status;
		if (statusVector.size() == 0)
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr("Status are empty please contact with Admin")),
				QString(tr("Ok")));
			errorMessage.clear();
			return;
		}
		statusEdit->setText(QString::number(statusVector.at(0).GetID()));
		QObject::connect(okBtn, &QPushButton::released, this, &CreateFxdAstDlg::CreateFixedAssets);
		QObject::connect(divisionCmb, &QComboBox::currentTextChanged, this, &CreateFxdAstDlg::GenerateInventoryNumber);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateFxdAstDlg::Close);
	QObject::connect(statusBtn, &QPushButton::released, this, &CreateFxdAstDlg::OpenStsDlg);
	QObject::connect(accableBtn, &QPushButton::released, this, &CreateFxdAstDlg::OpenActDlg);
	QObject::connect(purveyorBtn, &QPushButton::released, this, &CreateFxdAstDlg::OpenPurDlg);
	QObject::connect(accountBtn, &QPushButton::released, this, &CreateFxdAstDlg::OpenAccDlg);
	QObject::connect(primaryCostEdit, &QLineEdit::textChanged, this, &CreateFxdAstDlg::TextEditChanged);
	QObject::connect(amortizeEdit, &QLineEdit::textChanged, this, &CreateFxdAstDlg::TextEditChanged);
	QObject::connect(primaryEdit, &QLineEdit::textChanged, this, &CreateFxdAstDlg::TextEditChanged);
	QObject::connect(amValueEdit, &QLineEdit::textChanged, this, &CreateFxdAstDlg::CalculateMonthChanged);
	QObject::connect(primaryEdit, &QLineEdit::textChanged, this, &CreateFxdAstDlg::CalculateMonthChanged);
	QObject::connect(existSpecCxb, &QCheckBox::released, this, &CreateFxdAstDlg::HideSpecButton);
	QObject::connect(newFACxb, &QCheckBox::released, this, &CreateFxdAstDlg::HideSpecButton);
	QObject::connect(this, SIGNAL(CloseCreatedForms()), ((MainForm*)((DataForm*)parent)->GetParent()), SLOT(CloseChildsByName()));
	
}

CreateFxdAstDlg::~CreateFxdAstDlg()
{
	delete vDouble;
	delete vInt;
	emit CloseCreatedForms();

}

void CreateFxdAstDlg::SetFixedAssetsSpecificationParams(QString faName, QString factoryNumber, QString fDeveloper, QString fDocument, QString objChar,
	QString fConditionint, QString conDate, int id)
{
	fixedAssetsSpecification->SetName(faName.toUtf8().constData());
	fixedAssetsSpecification->SetFactoryNumber(factoryNumber.toUtf8().constData());
	fixedAssetsSpecification->SetDeveloper(fDeveloper.toUtf8().constData());
	fixedAssetsSpecification->SetDocument(fDocument.toUtf8().constData());
	fixedAssetsSpecification->SetObjectCharacters(objChar.toUtf8().constData());
	fixedAssetsSpecification->SetCondition(fConditionint.toUtf8().constData());
	fixedAssetsSpecification->SetDateOfConstruction(conDate.toUtf8().constData());
	fixedAssetsSpecification->SetID(id);
}

void CreateFxdAstDlg::SetFixedAssetsDetailsParams(int amGroupID, int amTypeID, int depID, QString fLocation, int primID, int amID,
	QString fBarcode, double amotValue, int id)
{
	fixedAssetsDetails->SetAmortizeGroupID(amGroupID);
	fixedAssetsDetails->SetAmortizeTypeID(amTypeID);
	fixedAssetsDetails->SetDepartmentID(depID);
	fixedAssetsDetails->SetFixedAssetsLocation(fLocation.toUtf8().constData());
	fixedAssetsDetails->SetPrimaryCostAccountID(primID);
	fixedAssetsDetails->SetAmortizeAccountID(amID);
	fixedAssetsDetails->SetBarcodeNumber(fBarcode.toUtf8().constData());
	fixedAssetsDetails->SetAmortizeValue(amotValue);
	fixedAssetsDetails->SetID(id);
}

void CreateFxdAstDlg::SetFixedAssetsParams(int specID, QString invNumber, double primCost, double stopCost, int servLife, QString isAmor,
	QString buyDate, QString sartOfOperDate, QString endOfOperDate, int statID, int fxID, int id)
{
	fixedAssets->SetSpecificationID(specID);
	fixedAssets->SetInventoryNumber(invNumber.toUtf8().constData());
	fixedAssets->SetPrimaryCost(primCost);
	fixedAssets->SetStopCost(stopCost);
	fixedAssets->SetServiceLife(servLife);
	fixedAssets->SetIsAmortize(isAmor == "true" ? true : false);
	fixedAssets->SetBuyDate(buyDate.toUtf8().constData());
	fixedAssets->SetStartOfOperationDate(sartOfOperDate.toUtf8().constData());
	fixedAssets->SetEndOfOperationDate(endOfOperDate.toUtf8().constData());
	fixedAssets->SetStatusID(statID);
	fixedAssets->SetFixedAssetsDetailsID(fxID);
	fixedAssetsDetails->SetID(id);
}

void CreateFxdAstDlg::SetPostingFixedAssetsParams(int userID, int subaccID, int accID, int fxID, int invID, int id)
{
	postingFixedAssets->SetUserID(userID);
	postingFixedAssets->SetSubaccountID(subaccID);
	postingFixedAssets->SetAccountID(accID);
	postingFixedAssets->SetFixedAssetsID(fxID);
	postingFixedAssets->SetInventoryID(invID);
	fixedAssetsDetails->SetID(id);
}

void CreateFxdAstDlg::SetFixedAssetsUnionParams(BusinessLayer::FixedAssets* fa, BusinessLayer::FixedAssetsSpecification* fas, BusinessLayer::FixedAssetsDetails* fad, BusinessLayer::PostingFixedAssets* pfa)
{
	fixedAssetsUnion->SetFixedAssets(fa);
	fixedAssetsUnion->SetFixedAssetsSpecification(fas);
	fixedAssetsUnion->SetFixedAssetsDetails(fad);
	fixedAssetsUnion->SetPostingFixedAssets(pfa);
}

void CreateFxdAstDlg::FillEditElements(int specID, QString invNumber, double primCost, double stopCost, int servLife, QString isAmor,
	QString buyDate, QString sartOfOperDate, QString endOfOperDate, int statID, int fxDetID)
{
	specIDEdit->setText(QString::number(specID));
	BusinessLayer::FixedAssetsSpecification spec;
	if (spec.GetFixedAssetsSpecificationByID(dialogBL->GetOrmasDal(), specID, errorMessage))
	{
		faNameEdit->setText(spec.GetName().c_str());
		factoryNumEdit->setText(spec.GetFactoryNumber().c_str());
		developerEdit->setText(spec.GetDeveloper().c_str());
		documentEdit->setText(spec.GetDocument().c_str());
		objCharEdit->setText(spec.GetObjectCharacters().c_str());
		conditionEdit->setText(spec.GetCondition().c_str());
		consDateEdit->setDate(QDate::fromString(spec.GetDateOfConstruction().c_str(), "dd.MM.yyyy"));
	}
	detailsIDEdit->setText(QString::number(fxDetID));
	BusinessLayer::FixedAssetsDetails det;
	if (det.GetFixedAssetsDetailsByID(dialogBL->GetOrmasDal(), fxDetID, errorMessage))
	{
		amGrpCmb->setCurrentIndex(amGrpCmb->findData(QVariant(det.GetAmortizeGroupID())));
		amTypeCmb->setCurrentIndex(amTypeCmb->findData(QVariant(det.GetAmortizeTypeID())));
		divisionCmb->setCurrentIndex(divisionCmb->findData(QVariant(det.GetDepartmentID())));
		locationEdit->setText(det.GetFixedAssetsLocation().c_str());
		BusinessLayer::Subaccount priSub;
		BusinessLayer::Subaccount amorSub;
		if (priSub.GetSubaccountByID(dialogBL->GetOrmasDal(), det.GetPrimaryCostAccountID(), errorMessage))
		{
			primaryCostEdit->setText(QString::number(priSub.GetCurrentBalance(),'f', 3));
			fAstTypeCmb->setCurrentIndex(fAstTypeCmb->findData(QVariant(priSub.GetParentAccountID())));
		}
		if (amorSub.GetSubaccountByID(dialogBL->GetOrmasDal(), det.GetAmortizeAccountID(), errorMessage))
		{
			primaryCostEdit->setText(QString::number(amorSub.GetCurrentBalance(), 'f', 3));
		}
		barcodeEdit->setText(det.GetBarcodeNumber().c_str());
		amValueEdit->setText(QString::number(det.GetAmortizeValue(), 'f', 3));
	}

	invNumberEdit->setText(invNumber);
	primaryEdit->setText(QString::number(primCost, 'f', 3));
	stopCostLb->setText(QString::number(stopCost, 'f', 3));
	serviceLifeEdit->setText(QString::number(servLife));
	isAmChx->setChecked(servLife);
	buyDateEdit->setDate(QDate::fromString(buyDate, "dd.MM.yyyy"));
	startDateEdit->setDate(QDate::fromString(sartOfOperDate, "dd.MM.yyyy"));
	endDateEdit->setDate(QDate::fromString(endOfOperDate, "dd.MM.yyyy"));
	statusEdit->setText(QString::number(statID));
}

void CreateFxdAstDlg::SetID(int ID, QString childName)
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

			if (childName == QString("statusForm"))
			{
				statusEdit->setText(QString::number(ID));
			}
			if (childName == QString("purveyorForm"))
			{
				purEditID->setText(QString::number(ID));
				BusinessLayer::User user;
				if (user.GetUserByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					surnameLb->setText(user.GetSurname().c_str());
				}
			}
			if (childName == QString("accountableForm"))
			{
				accableIDEdit->setText(QString::number(ID));
				BusinessLayer::Accountable accountable;
				if (accountable.GetAccountableByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					BusinessLayer::User user;
					if (user.GetUserByID(dialogBL->GetOrmasDal(), accountable.GetEmployeeID(), errorMessage))
					{
						surnameLb->setText(user.GetSurname().c_str());
					}
				}
			}
			if (childName == QString("accountForm"))
			{
				accID->setText(QString::number(ID));
				BusinessLayer::Account account;
				if (account.GetAccountByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					BusinessLayer::ChartOfAccounts coA;
					if (coA.GetChartOfAccountsByNumber(dialogBL->GetOrmasDal(), account.GetNumber(), errorMessage))
					{
						surnameLb->setText(coA.GetName().c_str());
					}
				}
			}
		}
	}
}

bool CreateFxdAstDlg::FillDlgElements(QTableView* cTable)
{
	QModelIndex mIndex = cTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetFixedAssetsParams(cTable->model()->data(cTable->model()->index(mIndex.row(), 13)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 3)).toDouble(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 4)).toDouble(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 8)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 9)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 10)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 11)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 12)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 14)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 15)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(cTable->model()->data(cTable->model()->index(mIndex.row(), 13)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 3)).toDouble(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 4)).toDouble(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 8)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 9)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 10)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 11)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 12)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 14)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 15)).toInt());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateFxdAstDlg::CreateFixedAssets()
{
	errorMessage.clear();
	if (0 == primaryCostEdit->text().toInt())
		primaryCostEdit->setText(primaryEdit->text());
	if (!faNameEdit->text().isEmpty() && !invNumberEdit->text().isEmpty() && !locationEdit->text().isEmpty() && 0 != amValueEdit->text().toDouble() && 0 != primaryEdit->text().toDouble()
		&& 0 != statusEdit->text().toInt() && !amGrpCmb->currentText().isEmpty() && !amTypeCmb->currentText().isEmpty()
		&& !divisionCmb->currentText().isEmpty() && 0 != serviceLifeEdit->text().toInt())
	{
		if (newFACxb->isChecked())
		{
			if (0 == accableIDEdit->text().toInt() && 0 == purEditID->text().toInt() && 0 == accID->text().toInt())
			{
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr("Please recheck all fields, accountable ID, purveyor ID or account ID!")),
					QString(tr("Ok")));
				return;
			}
		}
		dialogBL->StartTransaction(errorMessage);
		SetFixedAssetsSpecificationParams(faNameEdit->text(), factoryNumEdit->text(), developerEdit->text(), documentEdit->text(),
			objCharEdit->text(), conditionEdit->text(), consDateEdit->text());
		
		SetFixedAssetsDetailsParams(amGrpCmb->currentData().toInt(), amTypeCmb->currentData().toInt(), divisionCmb->currentData().toInt(),
			locationEdit->text(), 0, 0, barcodeEdit->text(),
			amValueEdit->text().toDouble());
		
		DataForm *parentDataForm = (DataForm*)parentForm;
		SetFixedAssetsParams(fixedAssetsSpecification->GetID(), invNumberEdit->text(), primaryEdit->text().toDouble(), stopEdit->text().toDouble(), 
			serviceLifeEdit->text().toInt(), isAmChx->isChecked() ? "true" : "false", buyDateEdit->text(), 
			startDateEdit->text(), "", statusEdit->text().toInt(), fixedAssetsDetails->GetID());
		fixedAssetsUnion->isNewFixedAssets = newFACxb->isChecked();
		fixedAssetsUnion->amortizeValue = amortizeEdit->text().toDouble();
		fixedAssetsUnion->primaryValue = primaryCostEdit->text().toDouble();
		fixedAssetsUnion->fixedAssetsAccountID = fAstTypeCmb->currentData().toInt();
		fixedAssetsUnion->purveyorID = purEditID->text().toInt();
		fixedAssetsUnion->accountableID = accableIDEdit->text().toInt();
		fixedAssetsUnion->accountID = accID->text().toInt();
		SetFixedAssetsUnionParams(fixedAssets, fixedAssetsSpecification, fixedAssetsDetails, postingFixedAssets);
		if (dialogBL->CreateFixedAssetsUnion(fixedAssetsUnion, errorMessage))
		{
			if (parentDataForm != nullptr)
			{
				if (!parentDataForm->IsClosed())
				{
					BusinessLayer::Status *status = new BusinessLayer::Status;
					if (!status->GetStatusByID(dialogBL->GetOrmasDal(), fixedAssets->GetStatusID(), errorMessage))
					{
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage.clear();
						delete status;
						return;
					}
					BusinessLayer::Subaccount priSub;
					BusinessLayer::Subaccount amorSub;
					if (!priSub.GetSubaccountByID(dialogBL->GetOrmasDal(), fixedAssetsDetails->GetPrimaryCostAccountID(), errorMessage))
					{
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage.clear();
						delete status;
						return;
					}
					if (!amorSub.GetSubaccountByID(dialogBL->GetOrmasDal(), fixedAssetsDetails->GetAmortizeAccountID(), errorMessage))
					{
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage.clear();
						delete status;
						return;
					}
					BusinessLayer::Division division;
					if (!division.GetDivisionByID(dialogBL->GetOrmasDal(), fixedAssetsDetails->GetDepartmentID(), errorMessage))
					{
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage.clear();
						delete status;
						return;
					}
					QList<QStandardItem*> fixedAssetsItem;
					fixedAssetsItem << new QStandardItem(QString::number(fixedAssets->GetID()))
						<< new QStandardItem(fixedAssetsSpecification->GetName().c_str())
						<< new QStandardItem(fixedAssets->GetInventoryNumber().c_str())
						<< new QStandardItem(QString::number(fixedAssets->GetPrimaryCost(), 'f', 3))
						<< new QStandardItem(QString::number(fixedAssets->GetStopCost(), 'f', 3))
						<< new QStandardItem(QString::number(priSub.GetCurrentBalance(), 'f', 3))
						<< new QStandardItem(QString::number(amorSub.GetCurrentBalance(), 'f', 3))
						<< new QStandardItem(division.GetName().c_str())
						<< new QStandardItem(status->GetName().c_str())
						<< new QStandardItem(QString::number(fixedAssets->GetServiceLife()))
						<< new QStandardItem(fixedAssets->GetIsAmortize())
						<< new QStandardItem(fixedAssets->GetBuyDate().c_str())
						<< new QStandardItem(fixedAssets->GetStartOfOperationDate().c_str())
						<< new QStandardItem(fixedAssets->GetEndOfOperationDate().c_str())
						<< new QStandardItem(QString::number(fixedAssets->GetSpecificationID()))
						<< new QStandardItem(QString::number(fixedAssets->GetStatusID()))
						<< new QStandardItem(QString::number(fixedAssets->GetFixedAssetsDetailsID()));

					QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
					itemModel->appendRow(fixedAssetsItem);

					delete status;
				}
			}
			dialogBL->CommitTransaction(errorMessage);

			Close();
		}
		else
		{
			dialogBL->CancelTransaction(errorMessage);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please recheck all fields!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateFxdAstDlg::EditFixedAssets()
{
	errorMessage.clear();
	if (!faNameEdit->text().isEmpty() && !locationEdit->text().isEmpty() && !invNumberEdit->text().isEmpty() && 0 != amValueEdit->text().toDouble() && 0 != primaryEdit->text().toDouble()
		&& 0 != statusEdit->text().toInt() && !amGrpCmb->currentText().isEmpty() && !amTypeCmb->currentText().isEmpty()
		&& !divisionCmb->currentText().isEmpty() && 0 != serviceLifeEdit->text().toInt())
	{
		if (fixedAssetsDetails->GetDepartmentID() != divisionCmb->currentData().toInt()
			&& invNumberEdit->text() != QString(fixedAssets->GetInventoryNumber().c_str()) && primaryEdit->text().toDouble() != fixedAssets->GetPrimaryCost()
			&& stopEdit->text().toDouble() != fixedAssets->GetStopCost() && stopEdit->text().toInt() != fixedAssets->GetServiceLife()
			&& invNumberEdit->text() != QString(fixedAssets->GetInventoryNumber().c_str()) && primaryEdit->text().toDouble() != fixedAssets->GetPrimaryCost()
			&& fixedAssets->GetIsAmortize() != isAmChx->isChecked() ? "true" : "false" && buyDateEdit->text() != QString(fixedAssets->GetBuyDate().c_str())
			&& startDateEdit->text() != QString(fixedAssets->GetStartOfOperationDate().c_str()) && endDateEdit->text() != QString(fixedAssets->GetEndOfOperationDate().c_str())
			&& statusEdit->text().toInt() != fixedAssets->GetServiceLife())
		{
			dialogBL->StartTransaction(errorMessage);
			SetFixedAssetsSpecificationParams(faNameEdit->text(), factoryNumEdit->text(), developerEdit->text(), documentEdit->text(),
				objCharEdit->text(), conditionEdit->text(), consDateEdit->text());

			fixedAssetsDetails->fixedAssetsAccountID = fAstTypeCmb->currentData().toInt();
			SetFixedAssetsDetailsParams(amGrpCmb->currentData().toInt(), amTypeCmb->currentData().toInt(), divisionCmb->currentData().toInt(),
				locationEdit->text(), 0, 0, barcodeEdit->text(),
				amValueEdit->text().toDouble());

			DataForm *parentDataForm = (DataForm*)parentForm;
			SetFixedAssetsParams(fixedAssetsSpecification->GetID(), invNumberEdit->text(), primaryEdit->text().toDouble(), stopEdit->text().toDouble(),
				serviceLifeEdit->text().toInt(), isAmChx->isChecked() ? "true" : "false", buyDateEdit->text(),
				startDateEdit->text(), "", statusEdit->text().toInt(), fixedAssetsDetails->GetID());

			SetFixedAssetsUnionParams(fixedAssets, fixedAssetsSpecification, fixedAssetsDetails, postingFixedAssets);
			if (dialogBL->UpdateFixedAssetsUnion(fixedAssetsUnion, errorMessage))
			{
				if (parentDataForm != nullptr)
				{
					if (!parentDataForm->IsClosed())
					{
						BusinessLayer::Status *status = new BusinessLayer::Status;
						if (!status->GetStatusByID(dialogBL->GetOrmasDal(), fixedAssets->GetStatusID(), errorMessage))
						{
							dialogBL->CancelTransaction(errorMessage);
							QMessageBox::information(NULL, QString(tr("Warning")),
								QString(tr(errorMessage.c_str())),
								QString(tr("Ok")));
							errorMessage.clear();
							delete status;
							return;
						}
						BusinessLayer::Subaccount priSub;
						BusinessLayer::Subaccount amorSub;
						if (!priSub.GetSubaccountByID(dialogBL->GetOrmasDal(), fixedAssetsDetails->GetPrimaryCostAccountID(), errorMessage))
						{
							dialogBL->CancelTransaction(errorMessage);
							QMessageBox::information(NULL, QString(tr("Warning")),
								QString(tr(errorMessage.c_str())),
								QString(tr("Ok")));
							errorMessage.clear();
							delete status;
							return;
						}
						if (!amorSub.GetSubaccountByID(dialogBL->GetOrmasDal(), fixedAssetsDetails->GetAmortizeAccountID(), errorMessage))
						{
							dialogBL->CancelTransaction(errorMessage);
							QMessageBox::information(NULL, QString(tr("Warning")),
								QString(tr(errorMessage.c_str())),
								QString(tr("Ok")));
							errorMessage.clear();
							delete status;
							return;
						}
						BusinessLayer::Division division;
						if (!division.GetDivisionByID(dialogBL->GetOrmasDal(), fixedAssetsDetails->GetDepartmentID(), errorMessage))
						{
							dialogBL->CancelTransaction(errorMessage);
							QMessageBox::information(NULL, QString(tr("Warning")),
								QString(tr(errorMessage.c_str())),
								QString(tr("Ok")));
							errorMessage.clear();
							delete status;
							return;
						}
						//updating FixedAssets data
						itemModel->item(mIndex.row(), 1)->setText(fixedAssetsSpecification->GetName().c_str());
						itemModel->item(mIndex.row(), 2)->setText(fixedAssets->GetInventoryNumber().c_str());
						itemModel->item(mIndex.row(), 3)->setText(QString::number(fixedAssets->GetPrimaryCost(), 'f', 3));
						itemModel->item(mIndex.row(), 4)->setText(QString::number(fixedAssets->GetStopCost(), 'f', 3));
						itemModel->item(mIndex.row(), 5)->setText(QString::number(priSub.GetCurrentBalance(), 'f', 3));
						itemModel->item(mIndex.row(), 6)->setText(QString::number(amorSub.GetCurrentBalance(), 'f', 3));
						itemModel->item(mIndex.row(), 7)->setText(division.GetName().c_str());
						itemModel->item(mIndex.row(), 8)->setText(status->GetName().c_str());
						itemModel->item(mIndex.row(), 9)->setText(QString::number(fixedAssets->GetServiceLife()));
						itemModel->item(mIndex.row(), 10)->setText(fixedAssets->GetIsAmortize()?"true":"false");
						itemModel->item(mIndex.row(), 11)->setText(fixedAssets->GetBuyDate().c_str());
						itemModel->item(mIndex.row(), 12)->setText(fixedAssets->GetStartOfOperationDate().c_str());
						itemModel->item(mIndex.row(), 13)->setText(fixedAssets->GetEndOfOperationDate().c_str());
						itemModel->item(mIndex.row(), 14)->setText(QString::number(fixedAssets->GetSpecificationID()));
						itemModel->item(mIndex.row(), 15)->setText(QString::number(fixedAssets->GetStatusID()));
						itemModel->item(mIndex.row(), 16)->setText(QString::number(fixedAssets->GetFixedAssetsDetailsID()));

						emit itemModel->dataChanged(mIndex, mIndex);
						delete status;
					}
				}
				dialogBL->CommitTransaction(errorMessage);


				Close();
			}
			else
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
			}
		}
		else
		{
			Close();
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please recheck all fields, all of them must be filled!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateFxdAstDlg::Close()
{
	dialogBL->CancelTransaction(errorMessage);
	this->parentWidget()->close();
}

void CreateFxdAstDlg::OpenStsDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Status"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);

	dForm->FillTable<BusinessLayer::Status>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->parentDialog = this;
		dForm->setObjectName("statusForm");
		dForm->QtConnect<BusinessLayer::Status>();
		QMdiSubWindow *statusWindow = new QMdiSubWindow;
		statusWindow->setWidget(dForm);
		statusWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(statusWindow);
		statusWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		dForm->setWindowFlags(dForm->windowFlags() | Qt::WindowStaysOnTopHint);
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

void CreateFxdAstDlg::OpenAccDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Account"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);

	dForm->FillTable<BusinessLayer::Account>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->parentDialog = this;
		dForm->setObjectName("accountForm");
		dForm->QtConnect<BusinessLayer::Account>();
		QMdiSubWindow *accWindow = new QMdiSubWindow;
		accWindow->setWidget(dForm);
		accWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(accWindow);
		accWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
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

void CreateFxdAstDlg::OpenPurDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Purveyors"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);

	BusinessLayer::Role *role = new BusinessLayer::Role();
	role->SetName("PURVEYOR");
	std::string roleFilter = dialogBL->GenerateFilter<BusinessLayer::Role>(role);
	std::vector<BusinessLayer::Role> roleVector = dialogBL->GetAllDataForClass<BusinessLayer::Role>(errorMessage, roleFilter);

	if (roleVector.size() == 0)
	{
		delete role;
		QString message = tr("Sorry could not define the role for this purveyor!");
		mainForm->statusBar()->showMessage(message);
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(message),
			QString(tr("Ok")));
		errorMessage = "";
		return;
	}

	dForm->FillTable<BusinessLayer::PurveyorView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->parentDialog = this;
		dForm->setObjectName("purveyorForm");
		dForm->QtConnect<BusinessLayer::PurveyorView>();
		QMdiSubWindow *purveyorWindow = new QMdiSubWindow;
		purveyorWindow->setWidget(dForm);
		purveyorWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(purveyorWindow);
		purveyorWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->HileSomeRow();
		dForm->show();
		dForm->raise();
		dForm->setWindowFlags(dForm->windowFlags() | Qt::WindowStaysOnTopHint);
		QString message = tr("All purveyors are shown");
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

void CreateFxdAstDlg::OpenActDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Accountable"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);

	dForm->FillTable<BusinessLayer::AccountableView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->parentDialog = this;
		dForm->setObjectName("accountableForm");
		dForm->QtConnect<BusinessLayer::AccountableView>();
		QMdiSubWindow *accblWindow = new QMdiSubWindow;
		accblWindow->setWidget(dForm);
		accblWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(accblWindow);
		accblWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		dForm->setWindowFlags(dForm->windowFlags() | Qt::WindowStaysOnTopHint);
		QString message = tr("All accountable are shown");
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

void CreateFxdAstDlg::InitComboBox()
{
	std::vector<BusinessLayer::Division> curDivision = dialogBL->GetAllDataForClass<BusinessLayer::Division>(errorMessage);
	if (!curDivision.empty())
	{
		for (unsigned int i = 0; i < curDivision.size(); i++)
		{
			divisionCmb->addItem(curDivision[i].GetName().c_str(), QVariant(curDivision[i].GetID()));
		}
	}
	std::vector<BusinessLayer::AmortizeType> curAmType = dialogBL->GetAllDataForClass<BusinessLayer::AmortizeType>(errorMessage);
	if (!curAmType.empty())
	{
		for (unsigned int i = 0; i < curAmType.size(); i++)
		{
			amTypeCmb->addItem(curAmType[i].GetName().c_str(), QVariant(curAmType[i].GetID()));
		}
	}
	std::vector<BusinessLayer::AmortizeGroup> curAmGroup = dialogBL->GetAllDataForClass<BusinessLayer::AmortizeGroup>(errorMessage);
	if (!curAmGroup.empty())
	{
		for (unsigned int i = 0; i < curAmGroup.size(); i++)
		{
			amGrpCmb->addItem(QString::number(curAmGroup[i].GetGroupNumber()), QVariant(curAmGroup[i].GetID()));
		}
	}
	std::vector<BusinessLayer::Account> accGroup = dialogBL->GetAllDataForClass<BusinessLayer::Account>(errorMessage);
	if (!accGroup.empty())
	{
		BusinessLayer::ChartOfAccounts coAcc;
		for (unsigned int i = 0; i < accGroup.size(); i++)
		{
			if (accGroup[i].GetNumber().substr(0, 3).compare("110")==0)
			{
				if (accGroup[i].GetNumber().substr(0, 5).compare("11000") != 0)
				{
					coAcc.Clear();
					if (coAcc.GetChartOfAccountsByNumber(dialogBL->GetOrmasDal(), accGroup[i].GetNumber(), errorMessage))
					{
						fAstTypeCmb->addItem(coAcc.GetName().c_str(), QVariant(accGroup[i].GetID()));
					}
				}
			}
		}
	}
}

void CreateFxdAstDlg::HideSpecButton()
{
	if (existSpecCxb->isChecked())
	{
		specBtn->setVisible(true);
		specIDEdit->show();
	}
	else
	{
		specIDEdit->hide();
		specBtn->setVisible(false);
		specIDEdit->setText("");
	}
	if (newFACxb->isChecked())
	{
		sourceGbx->show();
	}
	else
	{
		sourceGbx->hide();
		surnameLb->setText("");
		accountName->setText("");
		accableIDEdit->setText("");
		purEditID->setText("");
		accID->setText("");
	}
}

void CreateFxdAstDlg::CalculateMonthChanged()
{
	double amValue = amValueEdit->text().toDouble();
	double primeValue = primaryEdit->text().toDouble();
	double monthCount = std::round(100 / amValue * 12);
	serviceLifeEdit->setText(QString::number(monthCount));
	std::vector<BusinessLayer::AmortizeGroup> curAmGroup = dialogBL->GetAllDataForClass<BusinessLayer::AmortizeGroup>(errorMessage);
	if (!curAmGroup.empty())
	{
		for (unsigned int i = 0; i < curAmGroup.size(); i++)
		{
			if (curAmGroup[i].GetFromMonth() <= monthCount || curAmGroup[i].GetToMonth() >= monthCount)
				amGrpCmb->setCurrentIndex(i);
		}
	}
	primaryCostEdit->setText(primaryEdit->text());
}

void CreateFxdAstDlg::TextEditChanged()
{
	if (primaryEdit->text().contains(","))
	{
		primaryEdit->setText(primaryEdit->text().replace(",", "."));
	}
	if (primaryEdit->text().contains(".."))
	{
		primaryEdit->setText(primaryEdit->text().replace("..", "."));
	}
	if (stopEdit->text().contains(","))
	{
		stopEdit->setText(stopEdit->text().replace(",", "."));
	}
	if (stopEdit->text().contains(".."))
	{
		stopEdit->setText(stopEdit->text().replace("..", "."));
	}
	if (amValueEdit->text().contains(","))
	{
		amValueEdit->setText(amValueEdit->text().replace(",", "."));
	}
	if (amValueEdit->text().contains(".."))
	{
		amValueEdit->setText(amValueEdit->text().replace("..", "."));
	}
	if (primaryCostEdit->text().contains(","))
	{
		primaryCostEdit->setText(primaryCostEdit->text().replace(",", "."));
	}
	if (primaryCostEdit->text().contains(".."))
	{
		primaryCostEdit->setText(primaryCostEdit->text().replace("..", "."));
	}
	if (amortizeEdit->text().contains(","))
	{
		amortizeEdit->setText(amortizeEdit->text().replace(",", "."));
	}
	if (amortizeEdit->text().contains(".."))
	{
		amortizeEdit->setText(amortizeEdit->text().replace("..", "."));
	}
}

void CreateFxdAstDlg::GenerateInventoryNumber()
{
	std::string invNumber = "";
	invNumber = fixedAssetsUnion->GenerateInventoryNumber(dialogBL->GetOrmasDal(), divisionCmb->currentData().toInt());
	invNumberEdit->setText(invNumber.c_str());
}
