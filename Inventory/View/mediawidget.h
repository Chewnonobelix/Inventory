#ifndef MEDIAWIDGET_H
#define MEDIAWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QDateEdit>
#include <QTimeEdit>
#include <QDateTimeEdit>
#include <QLineEdit>
#include <QDebug>
#include "attribute.h"
#include "view_global.h"

namespace Ui {
class MediaWidget;
}

class VIEWSHARED_EXPORT MediaWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MediaWidget(QWidget *parent = 0);
    ~MediaWidget();
    QString title() const;
    QString value() const;
    void set(const Attribute&, QString);

private:
    Ui::MediaWidget *ui;
    QWidget* m_widget;
    Attribute::AttributeType m_type;
};

#endif // MEDIAWIDGET_H
