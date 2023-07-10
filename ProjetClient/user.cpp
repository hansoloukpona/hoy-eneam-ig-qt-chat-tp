#include "user.h"
#include "message.h"

user::user()
{
}

user::user(const QHostAddress &ip, const QString &name):userIP(ip),userName(name)
{
}

user::user(const user & copie):
userIP(copie.userIP), userName(copie.userName), historiqueMessages(copie.historiqueMessages)
{
}

void user::inituserSystem()
{
    qRegisterMetaType<user>("user");
    qMetaTypeId<user>();
}

QDataStream & operator << (QDataStream & out,const user & value)
{
    out << value.userIP
        << value.userName;
    return out;
}

QDataStream & operator >> (QDataStream & in, user & value)
{
    in >> value.userIP
       >> value.userName;
    return in;
}

void user::addMessages(const Message &messageRecu)
{
    historiqueMessages << messageRecu;
}

QString &user::getUserName()
{
    return userName;
}

void user::setUserName(const QString &newUserName)
{
    userName = newUserName;
}

QHostAddress &user::getUserIP()
{
    return userIP;
}

void user::setUserIP(const QHostAddress &newUserIP)
{
    userIP = newUserIP;
}

 QList<Message> &user::getHistoriqueMessages()
{
    return historiqueMessages;
}

void user::setHistoriqueMessages(const QList<Message> &newHistoriqueMessages)
{
    historiqueMessages = newHistoriqueMessages;
}

user::~user()
{

}
