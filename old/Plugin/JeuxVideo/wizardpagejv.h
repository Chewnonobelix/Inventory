#ifndef WIZARDPAGEJV_H
#define WIZARDPAGEJV_H

#include <QWizardPage>
#include "jeuxvideo_global.h"

namespace Ui {
class WizardPageJV;
}

class JEUXVIDEOSHARED_EXPORT WizardPageJV : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit WizardPageJV(QWidget *parent = 0);
    ~WizardPageJV();
    
private:
    Ui::WizardPageJV *ui;

private slots:
    void supportChange(QString);
};

#endif // WIZARDPAGEJV_H
