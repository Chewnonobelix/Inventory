#ifndef WIZARDPAGEJEUXFIGURINE_H
#define WIZARDPAGEJEUXFIGURINE_H

#include <QWizardPage>

namespace Ui {
class WizardPageJeuxFigurine;
}

class WizardPageJeuxFigurine : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit WizardPageJeuxFigurine(QWidget *parent = 0);
    ~WizardPageJeuxFigurine();
    
private:
    Ui::WizardPageJeuxFigurine *ui;
};

#endif // WIZARDPAGEJEUXFIGURINE_H
