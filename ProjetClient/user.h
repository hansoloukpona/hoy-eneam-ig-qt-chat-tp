#ifndef USER_H
#define USER_H

#include <QObject>
#include <QtNetwork>

/*Déclaration de la classe user (utilisateur) qui va permettre d'envoyer et de recevoir
 * des paquets informations à propos des utilisateurs et permettre une
 * bonne reception des paquets messages*/
class Message;
class user
{
    public:
        user(); //Constructeur
        user(const QHostAddress &ip, const QString &name);
        /*Ce constructeur intialise un utilisateur à partir d'une adresse Ip et d'un
         * nom qui deviennent sien*/
        user(const user &copie); //Constructeur de Copie
        ~user(); //Destructeur
        static void inituserSystem();
        /*Cette fonction permet d'initialiser des processus
         * pour utiluser correctement certains élements de
         * la classe user*/
        QString &getUserName() ; //Permet de récupérer le nom de l'utilisateur
        void setUserName(const QString &newUserName); // Permet de modifier le nom de l'utilisateur

        QHostAddress &getUserIP() ; //Permet de récupérer l'adresse Ip de l'utilisateur
        void setUserIP(const QHostAddress &newUserIP); //Permet de modifier l'adresse Ip de l'utilisateur

        QList<Message> &getHistoriqueMessages() ;
        /*Permet de récupérer l'historique d'une conversation */
        void setHistoriqueMessages(const QList<Message> &newHistoriqueMessages);
        /*Permet éventuellement de modifier un historique des conversations*/
        void addMessages(const Message &messageRecu);
        /*Permet d'enrégistrer les messages dont l'utilisateur est le destinataire et de conserver un
         * historique des échanges le temps d'une connexion*/
    private:
        QHostAddress userIP; //Adresse Ip de l'utilisateur
        QString userName; //Nom de l'utilisateur
        QList<Message> historiqueMessages; //Historique d'une conversation
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
