#include "usersetting.h"
#include "ui_usersetting.h"

UserSetting::UserSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserSetting)
{
    ui->setupUi(this);

    connect(ui->w_add, SIGNAL(pressed()), this, SLOT(add()));
    connect(ui->w_remove, SIGNAL(pressed()), this, SLOT(remove()));
    connect(ui->w_password, SIGNAL(pressed()), this, SLOT(editPassword()));

    connect(ui->w_connect, SIGNAL(pressed()), this, SLOT(connection()));
    connect(ui->w_disconnect, SIGNAL(pressed()), this, SLOT(disconnection()));

    connect(ui->w_type, SIGNAL(currentIndexChanged(int)), this, SLOT(typeChange(int)));
    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(showUserChange(QListWidgetItem*)));
}

UserSetting::~UserSetting()
{
    delete ui;
}

QString UserSetting::currentUser() const
{
    if(ui->listWidget->count() != 0)
        return ui->listWidget->currentItem()->text();
    else
        return QString();
}

QString UserSetting::currentType() const
{
    return ui->w_type->currentText();
}

void UserSetting::remove(QString user)
{
    ui->listWidget->removeItemWidget(ui->listWidget->findItems(user, Qt::MatchExactly)[0]);
}

void UserSetting::set(QStringList users, User::UserType type, UserSPointer user)
{

    if(user->username() != "Guest")
        m_current = user->username();

    ui->listWidget->clear();
    ui->listWidget->addItems(users);

    if(user && users.contains(m_current))
        ui->listWidget->setCurrentItem(ui->listWidget->findItems(m_current, Qt::MatchExactly)[0]);
    else
        ui->listWidget->setCurrentRow(0);

    if(type != User::Admin)
    {
        ui->w_type->setEnabled(false);
    }
    else
    {
        ui->w_type->setEnabled(true);
    }


    if(currentUser() == user->username())
    {
        ui->w_password->setEnabled(true);
    }

    if(currentUser().isEmpty())
        ui->w_disconnect->setEnabled(false);

}

void UserSetting::remove()
{
    emit s_remove();
}

void UserSetting::add()
{
    emit s_add();
}

void UserSetting::editPassword()
{
    emit s_changePassword(currentUser());
}

void UserSetting::showUser(UserSPointer u)
{
    switch(u->type())
    {
    case User::Admin:
        ui->w_type->setCurrentIndex(0);
        break;

    case User::Simple:
        ui->w_type->setCurrentIndex(1);
        break;

    case User::Viewer:
        break;
    }
}

void UserSetting::connection()
{
    emit s_connect();
}

void UserSetting::disconnection()
{
    emit s_disconnect();
    ui->w_type->setEnabled(false);
}

void UserSetting::typeChange(int type)
{
   switch(type)
   {
   case 0:
       emit s_typeChange(User::Admin);
       break;
   case 1:
       emit s_typeChange(User::Simple);
       break;
   }
}

void UserSetting::showUserChange(QListWidgetItem *)
{
    emit s_show();
}
