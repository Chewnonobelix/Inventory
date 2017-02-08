#ifndef FENETREJDR_H
#define FENETREJDR_H

#include <QDialog>
#include "jeuxderole.h"
#include "wizardsupplement.h"
#include "fenetresupplement.h"
#include <QMap>

namespace Ui {
class FenetreJDR;
}

class FenetreJDR : public QDialog
{
    Q_OBJECT
    
public:
    explicit FenetreJDR(JeuxDeRole* = 0, QWidget *parent = 0);
    ~FenetreJDR();
    void setModel(JeuxDeRole* = 0);
    void setModif(bool = false);
private:
    Ui::FenetreJDR *ui;
    JeuxDeRole* m_model;
    QSet<Supplement> m_supplementTemp;

public slots:
    void accept();
    void ajouter();
    void supprimer();
    void nouveauSupplement(Supplement);
    void affichageSupplement(int, int);

signals:
    void s_accept(bool, Qt::CheckState, QSet<Supplement>);
};

#endif // FENETREJDR_H
