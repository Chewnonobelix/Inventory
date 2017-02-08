#ifndef WIZARDPAGELIVRE_H
#define WIZARDPAGELIVRE_H

#include <QWizardPage>
#include <QInputDialog>
#include <QListWidget>
#include <QDebug>
#include <QMessageBox>
namespace Ui {
class WizardPageLivre;
}

class WizardPageLivre : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit WizardPageLivre(QWidget *parent = 0);
    ~WizardPageLivre();
    
private:
    Ui::WizardPageLivre *ui;

public slots:
    void change(QString);
    void ajouter();
    void supprimer();
};

#endif // WIZARDPAGELIVRE_H
