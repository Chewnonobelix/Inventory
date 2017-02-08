#ifndef USERSETTING_H
#define USERSETTING_H

#include <QDialog>
#include <QInputDialog>
#include <QDebug>
#include <QListWidget>
#include <QPointer>
#include "user.h"
#include "view_global.h"

namespace Ui {
class UserSetting;
}


class VIEWSHARED_EXPORT UserSetting : public QDialog
{
    Q_OBJECT

public:
    explicit UserSetting(QWidget *parent = 0);
    ~UserSetting();
    QString currentUser() const;
    QString currentType() const;
    void remove(QString);
    void set(QStringList, User::UserType, UserSPointer);
    void changePassword(UserSPointer);
    void showUser(UserSPointer);

private:
    Ui::UserSetting *ui;
    QString m_current;

public slots:
    void remove();
    void add();
    void editPassword();
    void connection();
    void disconnection();
    void typeChange(int);
    void showUserChange(QListWidgetItem*);


signals:
    void s_changePassword(QString);
    void s_add();
    void s_remove();
    void s_show();
    void s_connect();
    void s_disconnect();
    void s_typeChange(User::UserType);
};

typedef QPointer<UserSetting> UserSettingPointer;
#endif // USERSETTING_H
