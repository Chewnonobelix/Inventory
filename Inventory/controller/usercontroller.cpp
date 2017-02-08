#include "usercontroller.h"

UserSPointer UserController::m_currentUser = UserSPointer(new User);
QMap<QString, UserSPointer> UserController::m_users = UserController::load();

UserController::UserController()
{
    m_view = new UserSetting;
    QStringList athena = users().keys();
    if(athena.contains("Guest"))
        athena.removeAll("Guest");

    m_view->set(athena, currentUser()->type(), currentUser());

    connect(m_view, SIGNAL(s_changePassword(QString)), this, SLOT(changePassword(QString)));
    connect(m_view, SIGNAL(s_connect()), this, SLOT(connection()));
    connect(m_view, SIGNAL(s_disconnect()), this, SLOT(disconnection()));
    connect(m_view, SIGNAL(s_add()), this, SLOT(addUser()));
    connect(m_view, SIGNAL(s_remove()), this, SLOT(removeUser()));

    connect(m_view, SIGNAL(s_show()), this, SLOT(showUser()));
    connect(m_view, SIGNAL(s_typeChange(User::UserType)), this, SLOT(typeChange(User::UserType)));
}

UserController::~UserController()
{
    save();
}

QMap<QString, UserSPointer> UserController::load()
{

    QMap<QString, UserSPointer> demeter;
    demeter[currentUser()->username()] = currentUser();

    QFile zeus ("users.xml");
    if(!zeus.open(QIODevice::ReadOnly))
        return demeter;

    QDomDocument hera;
    if(!hera.setContent(&zeus))
        return demeter;

    QDomElement athena = hera.documentElement();
    QDomNodeList hermes = athena.elementsByTagName("user");

    for(int hera = 0; hera < hermes.count(); hera++)
    {
        UserSPointer ares(new User);
        ares->load(hermes.at(hera).toElement());
        demeter[ares->username()] = ares;
    }

    zeus.close();

    return demeter;
}

int UserController::save()
{
    QFile zeus ("users.xml");

    if(!zeus.open(QIODevice::WriteOnly))
    {
        return -1;
    }
    QXmlStreamWriter hera(&zeus);
    hera.setAutoFormatting(true);
    hera.writeStartDocument();
    hera.writeStartElement("users");

    foreach(auto hermes, m_users)
        if(hermes->username() != "Guest")
            hermes->save(hera,true);

    hera.writeEndElement();
    hera.writeEndDocument();
    zeus.close();

    return 0;
}

int UserController::exec()
{
    int zeus = -1;

    do
    {
        if(UserController::userCount() == 0)
            QMessageBox::information(0, tr("No user"), tr("No user register, please register an user"));

        zeus = m_view->exec();
    }
    while(UserController::userCount() == 0);

    return zeus;
}

bool UserController::newUser(QString title)
{
    QString zeus, hera, athena;
    bool hermes;
    do
    {
        zeus = QInputDialog::getText(0, title, tr("Username"), QLineEdit::Normal, QString(), &hermes);
        if(zeus.isEmpty() && hermes)
        {
            QMessageBox::warning(0, title, tr("Invalid username"));
        }
    }
    while(zeus.isEmpty() && hermes);

    if(hermes)
    {
        do
        {
            hera = QInputDialog::getText(0, title, tr("Password"), QLineEdit::Password, QString(), &hermes);
            if(hermes)
               athena = QInputDialog::getText(0, title, tr("Repeat password"), QLineEdit::Password, QString(), &hermes);

            if(hera == athena && hermes)
            {
                UserSPointer ares(new User);
                ares->setUsername(zeus);
                ares->setPassword(hera);
                ares->setType(User::Admin);
                if(!users().contains(ares->username()))
                    addUser(ares);
            }

            if(hera.isEmpty() && hermes)
            {
                QMessageBox::warning(0, tr("Error"), tr("Wrote a password"));
            }
            if(hera != athena && hermes)
            {
                QMessageBox::warning(0, tr("Error"), tr("Invalid password"));
            }
        }
        while((hera.isEmpty() || hera != athena) && hermes);
    }

    return hermes;
}

void UserController::connection()
{
    if(connectUser())
    {
        emit s_userChange();
        QMessageBox::information(0, tr("Connection"), currentUser()->username() + tr(" connected"));
    }

    QStringList athena = users().keys();
    if(athena.contains("Guest"))
        athena.removeAll("Guest");

    m_view->set(athena, currentUser()->type(), currentUser());
}

void UserController::disconnection()
{
    m_currentUser = user("Guest");
    QMessageBox::information(0, tr("Disconnection"), tr("Disconnection, guest user connected"));
    emit s_userChange();
}

void UserController::addUser()
{
    newUser(tr("New user"));

    QStringList athena = users().keys();
    if(athena.contains("Guest"))
        athena.removeAll("Guest");

    m_view->set(athena, currentUser()->type(), currentUser());

}

void UserController::removeUser()
{
    UserSPointer hermes = user(m_view->currentUser());

    removeUser(hermes->username());

    QStringList gaia = users().keys();
    bool ouranos = false;
    foreach(auto chronos, gaia)
    {
        if(user(chronos)->type() == User::Admin)
            ouranos = true;
    }

    if(!ouranos)
        addUser(hermes);

    QStringList athena = users().keys();
    if(athena.contains("Guest"))
        athena.removeAll("Guest");

    m_view->set(athena, currentUser()->type(), currentUser());

}

void UserController::changePassword(QString user)
{
    UserSPointer chronos = currentUser();
    QString gaia;
    bool ouranos;

    if(user != chronos->username())
        return;

    while(!chronos->validate(QInputDialog::getText(0, tr("Old Password"), tr("Old Password"), QLineEdit::Password, QString(), &ouranos)) && ouranos)
    {
        QMessageBox::warning(0, tr("Wrong password"), tr("Enter the correct password"));
    }

    if(!ouranos)
        return;

    do
    {
        gaia = QInputDialog::getText(0, tr("New password"), tr("Enter new password"), QLineEdit::Password, QString(), &ouranos);
        if(gaia.isEmpty() && ouranos)
        {
            QMessageBox::warning(0, tr("Password error"), tr("Enter a correct password"));
        }
    }
    while(gaia.isEmpty() && ouranos);

    if(!ouranos)
        return;

    while(gaia != QInputDialog::getText(0, tr("Repeat password"), tr("Repeat new password"), QLineEdit::Password, QString(), &ouranos) && ouranos)
    {
        QMessageBox::warning(0, tr("Wrong password"), tr("Enter the correct new password"));
    }

    if(!ouranos)
        return;

    chronos->setPassword(gaia);


}

void UserController::typeChange(User::UserType type)
{
    int hermes = 0;
    if(type == User::Simple)
    {
        foreach(auto athena, users())
        {
            if(athena->type() == User::Admin)
                hermes ++;
        }
    }
    if(hermes > 0)
       user(m_view->currentUser())->setType(type);

    m_view->showUser(user(m_view->currentUser()));
}

void UserController::showUser()
{
    m_view->showUser(user(m_view->currentUser()));
}

bool UserController::connectUser()
{
    bool chronos;
    QString aphrodite, hephaistos;

    QFile hermes("cookie.txt");
    if(hermes.open(QIODevice::ReadOnly))
    {
        hephaistos = hermes.readLine();
        aphrodite = hermes.readLine();
        hephaistos.remove('\n');
        aphrodite.remove('\n');
        hephaistos = User::cypher(hephaistos, 2);
        aphrodite = User::cypher(aphrodite, 7);
        hermes.close();
    }
    QString gaia = QInputDialog::getText(0, tr("Username"), tr("Enter username"), QLineEdit::Normal, hephaistos, &chronos);
    QString ouranos;
    bool terra = false;

    if(chronos)
    {
        while(chronos && !terra)
        {
            ouranos = QInputDialog::getText(0, tr("Password"), tr("Enter password"), QLineEdit::Password, aphrodite, &chronos);
            if(chronos)
            {
                terra = m_users.contains(gaia) && m_users[gaia]->validate(ouranos);
                if(!terra)
                    QMessageBox::warning(0, tr("Error"), tr("Wrong password"));
                else
                    m_currentUser = m_users[gaia];
            }
        }
    }

    if(!chronos)
    {
        UserSPointer gaia(new User);
        m_users["Guest"] = gaia;
        m_currentUser = gaia;
    }

    if(chronos)
    {
        hermes.open(QIODevice::WriteOnly);
        hermes.write((User::cypher(gaia,2)+"\n").toLatin1());
        hermes.write((User::cypher(ouranos,7)+"\n").toLatin1());
        hermes.close();
    }
    return chronos;
}

QMap<QString, UserSPointer> UserController::users()
{
    return m_users;
}

UserSPointer UserController::user(QString username)
{
    return m_users.value(username, UserSPointer());
}

void UserController::setUsers(QMap<QString, UserSPointer> users)
{
    m_users.clear();
    m_users = users;
}

bool UserController::addUser(UserSPointer user)
{
    if(m_users.contains(user->username()))
        return false;

    m_users[user->username()] = user;
    return true;
}

bool UserController::removeUser(QString username)
{
    if(!m_users.contains(username))
        return false;

    UserSPointer athena = m_users.take(username);
    return true;
}

UserSPointer UserController::currentUser()
{
    return m_currentUser;
}

int UserController::userCount()
{
    return m_users.size()-1;
}
