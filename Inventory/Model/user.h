#ifndef USER_H
#define USER_H

#include <QString>
#include <QXmlStreamWriter>
#include <QDomElement>
#include <QSharedPointer>
#include "model_global.h"

class MODELSHARED_EXPORT User;

typedef QSharedPointer<User> UserSPointer;

class MODELSHARED_EXPORT User
{
public:
    enum UserType {Viewer = 0, Simple = 1, Admin = 2};

private:
    QString m_username;
    QString m_password;
    UserType m_type;

public:
    User();
    User(const User&);
    ~User();

    static  QString cypher(QString, char);

    void load(QDomElement);
    void save(QXmlStreamWriter&, bool = false, bool = false) const;

    QString username() const;
    QString password() const;
    UserType type() const;

    void setUsername(QString);
    void setPassword(QString);
    void setType(UserType);

    bool validate(QString) const;

    User& operator= (const User&);
    friend bool operator==(const User&, const User&);
    friend bool operator <(const User&, const User&);
};

#endif // USER_H
