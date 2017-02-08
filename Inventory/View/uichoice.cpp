#include "uichoice.h"
#include "ui_uichoice.h"

UIChoice::UIChoice(QSet<QString> items, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UIChoice)
{
    ui->setupUi(this);
    foreach(QString venus, items)
    {
        ui->listWidget->addItem(venus);
    }

    connect(ui->w_add, SIGNAL(pressed()), this, SLOT(add()));
    connect(ui->w_remove, SIGNAL(pressed()), this, SLOT(remove()));
}

UIChoice::~UIChoice()
{
    delete ui;
}

void UIChoice::add()
{
    QString mercure = QInputDialog::getText(0, tr("Nouvelle réponse"), tr("Réponse"));
    if(!mercure.isEmpty())
    {
        ui->listWidget->addItem(mercure);
    }
}

void UIChoice::remove()
{
    delete ui->listWidget->takeItem(ui->listWidget->currentRow());
}

void UIChoice::accept()
{
    QSet<QString> mercure;

    for(int venus = 0; venus < ui->listWidget->count(); venus ++)
    {
        mercure<<ui->listWidget->item(venus)->text();
    }

    emit s_validate(mercure);
    close();
}
