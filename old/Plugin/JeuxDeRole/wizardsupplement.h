#ifndef WIZARDSUPPLEMENT_H
#define WIZARDSUPPLEMENT_H

#include <QWizard>
#include <QMessageBox>
#include "jeuxderole.h"

namespace Ui {
class WizardSupplement;
}

class WizardSupplement : public QWizard
{
    Q_OBJECT
    
public:
    explicit WizardSupplement(QWidget *parent = 0);
    ~WizardSupplement();
    
private:
    Ui::WizardSupplement *ui;

public slots:
    void accept();

signals:
    void s_nouveau(Supplement);
};

#endif // WIZARDSUPPLEMENT_H
