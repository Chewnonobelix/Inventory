#ifndef WIZARDPAGESERIE_H
#define WIZARDPAGESERIE_H

#include <QWizardPage>
#include "serie_global.h"
namespace Ui {
class WizardPageSerie;
}

class SERIESHARED_EXPORT WizardPageSerie : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit WizardPageSerie(QWidget *parent = 0);
    ~WizardPageSerie();
    int getNbSaison() const;
private:
    Ui::WizardPageSerie *ui;
};

#endif // WIZARDPAGESERIE_H
