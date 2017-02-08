#ifndef WIZARDPAGEJDR_H
#define WIZARDPAGEJDR_H

#include <QWizardPage>

namespace Ui {
class WizardPageJDR;
}

class WizardPageJDR : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit WizardPageJDR(QWidget *parent = 0);
    ~WizardPageJDR();

    QString getLangue() const;
    Qt::CheckState getAchat() const;
private:
    Ui::WizardPageJDR *ui;
};

#endif // WIZARDPAGEJDR_H
