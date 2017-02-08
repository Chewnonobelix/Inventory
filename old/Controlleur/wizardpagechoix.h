#ifndef WIZARDPAGECHOIX_H
#define WIZARDPAGECHOIX_H

#include <QWizardPage>

namespace Ui {
class WizardPageChoix;
}

class WizardPageChoix : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit WizardPageChoix(QStringList, QWidget *parent = 0);
    ~WizardPageChoix();
    QString getCurrent() const;

private:
    Ui::WizardPageChoix *ui;

public slots:
    void change(QString);

signals:
    void s_change(QString);
};

#endif // WIZARDPAGECHOIX_H
