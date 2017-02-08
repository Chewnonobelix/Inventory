#include "researchview.h"
#include "ui_researchview.h"

ResearchView::ResearchView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResearchView)
{
    ui->setupUi(this);
    m_first = new GroupClaus;
    ui->verticalLayout->insertWidget(0, m_first);
    ui->buttonBox->button(QDialogButtonBox::Help)->setToolTip(tr("Recherche help test"));
    ui->buttonBox->button(QDialogButtonBox::Help)->setEnabled(false);
    connect(ui->buttonBox, SIGNAL(clicked(QAbstractButton*)), this, SLOT(clicked(QAbstractButton*)));
}

ResearchView::~ResearchView()
{
    delete ui;
}

const GroupClaus *ResearchView::claus() const
{
    return m_first;
}

void ResearchView::clicked(QAbstractButton * b)
{
    if(ui->buttonBox->buttonRole(b) == QDialogButtonBox::ApplyRole)
        emit s_search();
}

void ResearchView::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
