#ifndef WIZARDPAGEBD_H
#define WIZARDPAGEBD_H

#include <QWizardPage>
#include "bandedessine_global.h"

namespace Ui {
class WizardPageBD;
}

class BANDEDESSINESHARED_EXPORT WizardPageBD : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit WizardPageBD(QWidget *parent = 0);
    ~WizardPageBD();
    
private:
    Ui::WizardPageBD *ui;
};

#endif // WIZARDPAGEBD_H
