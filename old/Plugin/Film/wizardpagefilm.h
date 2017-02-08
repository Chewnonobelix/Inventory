#ifndef WIZARDPAGEFILM_H
#define WIZARDPAGEFILM_H

#include <QWizardPage>
#include <QListWidgetItem>
#include <QInputDialog>
#include <QDebug>

namespace Ui {
class WizardPageFilm;
}

class WizardPageFilm : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit WizardPageFilm(QWidget *parent = 0);
    ~WizardPageFilm();
    
private:
    Ui::WizardPageFilm *ui;

public slots:
    void ajouter();
    void supprimer();
    void supprimeEnable(QListWidgetItem*);
};

#endif // WIZARDPAGEFILM_H
