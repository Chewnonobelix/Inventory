#ifndef UiChoice_H
#define UiChoice_H

#include <QDialog>
#include <QInputDialog>
#include <QDebug>

namespace Ui {
class UIChoice;
}

class UIChoice : public QDialog
{
    Q_OBJECT

public:
    explicit UIChoice(QSet<QString>, QWidget *parent = 0);
    ~UIChoice();

private:
    Ui::UIChoice *ui;

public slots:
    void add();
    void remove();
    void accept();

signals:
    void s_validate(QSet<QString>);
};

#endif // UiChoice_H
