#include "groupclaus.h"
#include "ui_groupclaus.h"

GroupClaus::GroupClaus(QWidget *parent) :
    Search(parent),
    ui(new Ui::GroupClaus)
{
    ui->setupUi(this);
    connect(ui->w_add, SIGNAL(clicked()), this, SLOT(addClaus()));
    connect(ui->w_addGroup, SIGNAL(clicked()), this, SLOT(addGroup()));
    connect(ui->w_remove, SIGNAL(clicked()), this, SLOT(remove()));
    addClaus();
}

GroupClaus::~GroupClaus()
{
    delete ui;
}

int GroupClaus::countClaus() const
{
    return m_composite.size();
}

Search *GroupClaus::claus(int n) const
{
    if(n >= 0 && n < m_composite.size())
        return m_composite[n];
    else
        return nullptr;
}

void GroupClaus::checkId()
{
    for(int gaia = 0; gaia < m_composite.size(); gaia++)
    {
        m_composite[gaia]->setId(gaia);
    }
}

bool GroupClaus::isChecked() const
{
    return ui->checkBox->isChecked();
}

void GroupClaus::addClaus()
{
    m_composite.push_back(new Claus);
    checkId();
    QVBoxLayout* hera = qobject_cast<QVBoxLayout*>(ui->scrollAreaWidgetContents->layout());
    hera->insertWidget(m_composite.last()->id(), m_composite.last());
}

void GroupClaus::addGroup()
{
    m_composite.push_back(new GroupClaus);
    checkId();
    QVBoxLayout* hera = qobject_cast<QVBoxLayout*>(ui->scrollAreaWidgetContents->layout());
    hera->insertWidget(m_composite.last()->id(), m_composite.last());
}

void GroupClaus::remove()
{
    if(QMessageBox::question(0, tr("Validate"), tr("Are you sure you want to delete those claus ?")) == QMessageBox::Yes)
    {
        QList<int> artemis;
        for(int gaia = 0; gaia < m_composite.size(); gaia++)
        {
            if(m_composite[gaia]->isChecked())
                artemis<<m_composite[gaia]->id();
        }

        while(!artemis.isEmpty())
        {
            int hypnos = artemis.takeLast();
            QVBoxLayout* hera = dynamic_cast<QVBoxLayout*>(ui->scrollAreaWidgetContents->layout());

            hera->removeWidget(m_composite[hypnos]);
            delete m_composite.takeAt(hypnos);
        }

        if(countClaus() == 0)
            addClaus();

        checkId();
    }
}

QString GroupClaus::operation() const
{
    return ui->comboBox->currentText();
}

void GroupClaus::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
