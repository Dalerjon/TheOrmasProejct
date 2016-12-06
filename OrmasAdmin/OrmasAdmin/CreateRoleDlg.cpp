#include "stdafx.h"
#include <QMessageBox>
#include "CreateRoleDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"

CreateRoleDlg::CreateRoleDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	nameEdit->setMaxLength(20);
	dialogBL = ormasBL;
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateRoleDlg::EditRole);
	}
	else
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateRoleDlg::CreateRole);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateRoleDlg::Close);
	QObject::connect(commentTextEdit, &QTextEdit::textChanged, this, &CreateRoleDlg::TextEditChanged);
}

void CreateRoleDlg::SetRoleParams(QString rName, QString rComment, int id)
{
	role->SetName(rName.toUtf8().constData());
	role->SetComment(rComment.toUtf8().constData());
	role->SetID(id);
}

void CreateRoleDlg::FillEditElements(QString rName, QString rComment)
{
	nameEdit->setText(rName);
	commentTextEdit->setText(rComment);
}

bool CreateRoleDlg::FillDlgElements(QTableView* rTable)
{
	QModelIndex mIndex = rTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetRoleParams(rTable->model()->data(rTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			rTable->model()->data(rTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			rTable->model()->data(rTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(rTable->model()->data(rTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			rTable->model()->data(rTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateRoleDlg::CreateRole()
{
	errorMessage.clear();
	if (!(nameEdit->text().isEmpty()))
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetRoleParams(nameEdit->text(), commentTextEdit->toPlainText());
		if (dialogBL->CreateRole(role, errorMessage))
		{
			QList<QStandardItem*> roleItem;
			roleItem << new QStandardItem(QString::number(role->GetID())) << new QStandardItem(role->GetName().c_str())
				<< new QStandardItem(role->GetComment().c_str());
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(roleItem);
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
			QString(tr("Please fill the name!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateRoleDlg::EditRole()
{
	errorMessage.clear();
	if (!(nameEdit->text().isEmpty()))
	{
		if (QString(role->GetName().c_str()) != nameEdit->text() || QString(role->GetComment().c_str()) != commentTextEdit->toPlainText())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetRoleParams(nameEdit->text(), commentTextEdit->toPlainText(), GetIDFromTable(parentDataForm->tableView, errorMessage));
			if (dialogBL->UpdateRole(role, errorMessage))
			{
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(nameEdit->text());
				itemModel->item(mIndex.row(), 2)->setText(commentTextEdit->toPlainText());
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
			QString(tr("Please fill the name!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateRoleDlg::Close()
{
	this->close();
}

void CreateRoleDlg::TextEditChanged()
{
	if (commentTextEdit->toPlainText().length()> 50) {
		commentTextEdit->setPlainText(commentTextEdit->toPlainText().left(commentTextEdit->toPlainText().length() - 1));
		commentTextEdit->moveCursor(QTextCursor::End);
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Warning: no more then ")) + QString::number(100) + QString(tr(" characters in this field")),
			QString(tr("Ok")));
	}
}