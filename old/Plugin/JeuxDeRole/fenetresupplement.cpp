#include "fenetresupplement.h"
#include "ui_fenetresupplement.h"

FenetreSupplement::FenetreSupplement(Supplement& s, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreSupplement)
{
    ui->setupUi(this);

    ui->w_langue->setText (Supplement::langueToString (s.langue ()));
    ui->w_nom->setText (s.nom ());
    ui->w_support->setText (Supplement::supportToString (s.support ()));
    ui->w_type->setText (Supplement::typeToString (s.type ()));

    connect(ui->buttonBox, SIGNAL(clicked(QAbstractButton*)), this, SLOT(fermer(QAbstractButton*)));
}

FenetreSupplement::~FenetreSupplement()
{
    delete ui;
}

void FenetreSupplement::fermer (QAbstractButton *)
{
    close();
}
