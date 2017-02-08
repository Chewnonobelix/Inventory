#ifndef AJOUTLIVRE_H
#define AJOUTLIVRE_H

#include <QDialog>

namespace Ui {
class AjoutLivre;
}

class AjoutLivre : public QDialog
{
    Q_OBJECT

public:
    explicit AjoutLivre(QWidget *parent = 0);
    ~AjoutLivre();
    void incorrectName();
    void incorrectLangue();
    void incorrectSupport();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::AjoutLivre *ui;

signals:
    void s_valide(QList<QString>);

public slots:
    void accept();
};

#endif // AJOUTLIVRE_H
