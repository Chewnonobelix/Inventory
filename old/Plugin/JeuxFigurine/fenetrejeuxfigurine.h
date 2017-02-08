#ifndef FENETREJEUXFIGURINE_H
#define FENETREJEUXFIGURINE_H

#include <QDialog>
#include "jeuxfigurine.h"
#include <QListWidgetItem>
#include <QTreeWidgetItem>
#include <QInputDialog>
#include <QList>

namespace Ui {
class FenetreJeuxFigurine;
}

class FenetreJeuxFigurine : public QDialog
{
    Q_OBJECT
private:
    Ui::FenetreJeuxFigurine *ui;
    JeuxFigurine* m_model;

    QSet<Livre> m_tempLivre;
    QMultiMap<QString, Figurines> m_tempFigurines;
    QStringList m_tempDivers;

    QSet<QString> m_tempSupLivre;
    QSet<QString> m_tempSupDivers;

    void setModelFigurine();

public:
    explicit FenetreJeuxFigurine(JeuxFigurine*, QWidget *parent = 0);
    ~FenetreJeuxFigurine();
    void accept();
    void setModel(JeuxFigurine* = nullptr);
    void addLivre(Livre);
    void addFig(Figurines);

public slots:
    void descriptionLivre(QListWidgetItem*);
    void descriptionFigurines(QTreeWidgetItem *);
    void descriptionDivers(QListWidgetItem*);
    void addDivers();
    void addLivre();
    void supLivre();
    void addFig();

signals:
    void s_addLivre();
    void s_addFig();
    void s_accept(QSet<QString>, QSet<QString>, QMultiMap<QString, QStringList>); //remove Livre, divers, fig
};

#endif // FENETREJEUXFIGURINE_H
