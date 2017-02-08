#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include <QMessageBox>
#include <QInputDialog>
#include <QFile>
#include <QDomDocument>
#include <QDomElement>
#include "abstractcontroller.h"
#include "usersetting.h"
#include "user.h"

class UserController final: public AbstractController
{
    Q_OBJECT

private:
    UserSettingPointer m_view;
    static QMap<QString, UserSPointer> m_users;
    static UserSPointer m_currentUser;
    static QMap<QString, UserSPointer> load();
    static int save();

public:
    UserController();
    ~UserController();

    int exec();
    static QMap<QString, UserSPointer> users();
    static UserSPointer user(QString);
    static void setUsers(QMap<QString, UserSPointer>);
    static bool addUser(UserSPointer);
    static bool removeUser(QString);
    static bool newUser(QString);
    static bool connectUser();
    static UserSPointer currentUser();
    static int userCount();


public slots:
    void addUser();
    void removeUser();
    void changePassword(QString);
    void connection();
    void disconnection();
    void typeChange(User::UserType);
    void showUser();

signals:
    void s_userChange();

};

#endif // USERCONTROLLER_H
