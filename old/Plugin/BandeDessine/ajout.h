#ifndef AJOUT_H
#define AJOUT_H

#include <QDialog>

namespace Ui {
class Ajout;
}

class Ajout : public QDialog
{
    Q_OBJECT
    
public:
    explicit Ajout(QWidget *parent = 0);
    ~Ajout();
    QStringList getDessinateur() const;
    QStringList getAuteur() const;
    QString getTitre() const;
    int getNumero() const;

private:
    Ui::Ajout *ui;
};

#endif // AJOUT_H
