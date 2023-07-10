#ifndef USER_H
#define USER_H

#include <QObject>
#include <QtNetwork>


class Message;
class user
{

    public:
        user();
        user(const QHostAddress &ip, const QString &name);
        user(const user &copie);
        ~user();
        static void inituserSystem();

        qint64 tailleMessage;

        QString &getUserName() ;
        void setUserName(const QString &newUserName);

        QHostAddress &getUserIP() ;
        void setUserIP(const QHostAddress &newUserIP);

        QTcpSocket *getUserSocket() ; //Permet de récupérer un pointeur sur le socket d'arrivée de l'utilusateur
        void setUserSocket(QTcpSocket *newUserSocket);

        QList<Message> &getHistoriqueMessages() ;
        void setHistoriqueMessages(const QList<Message> &newHistoriqueMessages);

    private:
        QTcpSocket *userSocket;
        QString userName;
        QHostAddress userIP;
        QList<Message> historiqueMessages;
        /*Déclaration de la redéfinition des Opérateurs de flux
         * qui sont des fonctions amies pour l'envoi et la reception d'infos
         * sur les utilisateurs*/
        friend QDataStream & operator << (QDataStream &, const user &);
        friend QDataStream & operator >> (QDataStream &, user &);

 };
//Paramètrage lié à la redéfiniton des opérateurs de flux
Q_DECLARE_METATYPE(user)
QDataStream & operator << (QDataStream & out, const user & value);
QDataStream & operator >> (QDataStream & in, user & value);

#endif // USER_H
