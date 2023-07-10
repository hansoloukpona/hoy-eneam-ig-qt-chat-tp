#include "user.h"
#include "message.h"

user::user()
{
    tailleMessage = 0;
}

user::user(const QHostAddress &ip, const QString &name):userName(name),userIP(ip)
{
    tailleMessage = 0;
}

user::user(const user & copie):
    userSocket(copie.userSocket), userName(copie.userName),
    userIP(copie.userIP), historiqueMessages(copie.historiqueMessages)
{
}

void user::inituserSystem()
{
    qRegisterMetaType<user>("user");
    qMetaTypeId<user>();
}

QDataStream & operator << (QDataStream & out, const user & value)
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

QTcpSocket *user::getUserSocket()
{
    return userSocket;
}

void user::setUserSocket(QTcpSocket *newUserSocket)
{
    userSocket = newUserSocket;
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
