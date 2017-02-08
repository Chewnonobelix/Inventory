#include "wizardsupplement.h"
#include "ui_wizardsupplement.h"

WizardSupplement::WizardSupplement(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::WizardSupplement)
{
    ui->setupUi(this);
}

WizardSupplement::~WizardSupplement()
{
    delete ui;
}

void WizardSupplement::accept ()
{
    Supplement hades;
    try
    {
        hades.setType (Supplement::typeFromString (ui->w_type->currentText ()));
    }
    catch(QString athena)
    {
        QMessageBox::information (0, "Erreur", athena);
    }

    try
    {
        hades.setSupport (Supplement::supportFromString (ui->w_support->currentText ()));
    }
    catch(QString athena)
    {
        QMessageBox::information (0, "Erreur", athena);
    }
    try
    {
        hades.setLangue (Supplement::langueFromString (ui->w_langue->currentText ()));
    }
    catch(QString athena)
    {
        QMessageBox::information (0, "Erreur", athena);
    }

    hades.setNom (ui->w_nom->text ());
    emit s_nouveau (hades);

    QWizard::accept ();
}
