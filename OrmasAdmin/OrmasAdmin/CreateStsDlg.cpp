#include "stdafx.h"
#include <QMessageBox>
#include "CreateStsDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"

CreateStsDlg::CreateStsDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	codeEdit->setMaxLength(4);
	nameEdit->setMaxLength(10);
	dialogBL = ormasBL;
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateStsDlg::EditStatus);
	}
	else
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateStsDlg::CreateStatus);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateStsDlg::Close);
	QObject::connect(commentTextEdit, &QTextEdit::textChanged, this, &CreateStsDlg::TextEditChanged);
}

void CreateStsDlg::SetStatusParams(QString sCode, QString sName, QString sComment, int id)
{
	status->SetCode(sCode.toUtf8().constData());
	status->SetName(sName.toUtf8().constData());
	status->SetComment(sComment.toUtf8().constData());
	status->SetID(id);
}

void CreateStsDlg::FillEditElements(QString sCode, QString sName, QString sComment)
{
	codeEdit->setText(sCode);
	nameEdit->setText(sName);
	commentTextEdit->setText(sComment);
}

bool CreateStsDlg::FillDlgElements(QTableView* sTable)
{
	QModelIndex mIndex = sTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetStatusParams(sTable->model()->data(sTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			sTable->model()->data(sTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			sTable->model()->data(sTable->model()->index(mIndex.row(), 3)).toString().toUtf8().constData(),
			sTable->model()->data(sTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(sTable->model()->data(sTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			sTable->model()->data(sTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			sTable->model()->data(sTable->model()->index(mIndex.row(), 3)).toString().toUtf8().constData());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateStsDlg::CreateStatus()
{
	errorMessage.clear();
	if (!(codeEdit->text().isEmpty() || nameEdit->text().isEmpty()))
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetStatusParams(codeEdit->text(), nameEdit->text(), commentTextEdit->toPlainText());
		if (dialogBL->CreateStatus(status, errorMessage))
		{
			QList<QStandardItem*> statusItem;
			statusItem << new QStandardItem(QString::number(status->GetID())) << new QStandardItem(status->GetCode().c_str())
				<< new QStandardItem(status->GetName().c_str()) << new QStandardItem(status->GetComment().c_str());
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(statusItem);
			this->close();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please fill code and name!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateStsDlg::EditStatus()
{
	errorMessage.clear();
	if (!(codeEdit->text().isEmpty() || nameEdit->text().isEmpty()))
	{
		if (QString(status->GetCode().c_str()) != codeEdit->text() || QString(status->GetName().c_str()) != nameEdit->text()
			|| QString(status->GetComment().c_str()) != commentTextEdit->toPlainText())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetStatusParams(codeEdit->text(), nameEdit->text(), commentTextEdit->toPlainText(), GetIDFromTable(parentDataForm->tableView, errorMessage));
			if (dialogBL->UpdateStatus(status, errorMessage))
			{
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(codeEdit->text());
				itemModel->item(mIndex.row(), 2)->setText(nameEdit->text());
				itemModel->item(mIndex.row(), 3)->setText(commentTextEdit->toPlainText());
				emit itemModel->dataChanged(mIndex, mIndex);
				this->close();
			}
			else
			{
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
			}
		}
		else
		{
			this->close();
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please fill code and name!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateStsDlg::Close()
{
	this->close();
}
void CreateStsDlg::TextEditChanged()
{
	if (commentTextEdit->toPlainText().length()> 50) {
		commentTextEdit->setPlainText(commentTextEdit->toPlainText().left(commentTextEdit->toPlainText().length() - 1));
		commentTextEdit->moveCursor(QTextCursor::End);
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Warning: no more then ")) + QString::number(100) + QString(tr(" characters in this field")),
			QString(tr("Ok")));
	}
}
