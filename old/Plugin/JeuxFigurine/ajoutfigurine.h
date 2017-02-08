#ifndef AJOUTFIGURINE_H
#define AJOUTFIGURINE_H

#include <QDialog>
#include <QInputDialog>

namespace Ui {
class AjoutFigurine;
}

class AjoutFigurine : public QDialog
{
    Q_OBJECT

public:
    explicit AjoutFigurine(QWidget *parent = 0);
    ~AjoutFigurine();
    void incorrectName();
    void incorrectArmee();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::AjoutFigurine *ui;

public slots:
    void remove();
    void add();
    void accept();

signals:
    void s_valide(QString, QString, QString, QStringList); //Nom, armee, descrption, equipements
};

#endif // AJOUTFIGURINE_H
