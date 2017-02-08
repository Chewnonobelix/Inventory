#include "user.h"

User::User()
{
    m_username = "Guest";
    m_type = Viewer;
}

User::User(const User& u): m_username(u.username()), m_password(u.password()),
    m_type(u.type())
{}

User::~User() {}

QString User::cypher(QString string, char key)
{
    for(int hades = 0; hades < string.size(); hades ++)
    {
        string[hades] = string[hades].toLatin1() ^ key;
    }

    return string;
}

void User::load(QDomElement element)
{
    QDomElement zeus = element.elementsByTagName("username").at(0).toElement();
    setUsername(cypher(zeus.text(), 57));
    zeus = element.elementsByTagName("password").at(0).toElement();
    setPassword(cypher(zeus.text(), 42));
    zeus = element.elementsByTagName("type").at(0).toElement();
    setType((UserType)(cypher(zeus.text(), 95).toInt()));
}

void User::save(QXmlStreamWriter& stream, bool password, bool type) const
{
    stream.writeStartElement("user");
        stream.writeTextElement("username", cypher(username(), 57));
        if(password)
            stream.writeTextElement("password", cypher(this->password(), 42));

        if(type)
            stream.writeTextElement("type", cypher(QString::number(this->type()), 95));

    stream.writeEndElement();
}

QString User::username() const
{
    return m_username;
}

QString User::password() const
{
    return m_password;
}

User::UserType User::type() const
{
    return m_type;
}

void User::setUsername(QString un)
{
    m_username = un;
}

void User::setPassword(QString pwd)
{
    m_password = pwd;
}

void User::setType(User::UserType t)
{
    m_type = t;
}

bool User::validate(QString pwd) const
{
    return pwd == password();
}

User& User::operator= (const User& u)
{
    setUsername(u.username());
    setPassword(u.password());
    setType(u.type());

    return *this;
}

bool operator==(const User& u1, const User& u2)
{
    return (u1.type() == u2.type()) && (u1.username() == u2.username()) && (u1.password() == u2.password());
}

bool operator <(const User& u1, const User& u2)
{
    return (u1.type() < u2.type()) && u1.username() < u2.username();
}
