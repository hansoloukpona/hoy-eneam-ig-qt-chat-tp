#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QtNetwork>

/*Déclaration de la classe Message qui va permettre d'envoyer et de recevoir
 * des paquets message et des informations auxiliaires desinés à permettre un
 * bon transfert des paquets messages*/
class Message
{
    public:
        Message(); //Constructeur
        Message(const Message & copie); //Constructeur de Copie
        Message(const QHostAddress &senderIP, const QString &sender, const QString &recever, const QString &message);
        /*Ce constructeur initialise un paquet message avec
         * l'adresse ip du destinateur, son nom, celui du
         * destinataire et le contenu du message */
        ~Message(); //Destructeur
        static void initMessageSystem();
        /*Cette fonction permet d'initialiser des processus
         * pour utiluser correctement certains élements de
         * la classe Message*/
        QString &sender() ; //Permet de récuperer le nom du destinateur
        void setSender(const QString &newSender); //Permet de modifier le nom du destinateur

        QString &recever() ; //Permet de récuperer le nom du destinataire
        void setRecever(const QString &newRecever); //Permet de modifier le nom du destinataire

        QString &content() ; //Permet de récuperer le contenu du messsage
        void setContent(const QString &newContent); // Permet de modifier le contenu du message

        const QHostAddress &senderIP() const; // Permet de récupérer l'adresse Ip du destinateur
        void setSenderIP(const QHostAddress &newSenderIP); //Permet de modifier l'adresse Ip du destinateur

    private:
        QHostAddress m_senderIP; //Adresse Ip du destinateur
        QString m_sender; //Nom du destinateur
        QString m_recever; //Nom du destinataire
        QString m_content; //Contenu du message
        /*Déclaration de la redéfinition des Opérateurs de flux
         * qui sont des fonctions amies pour l'envoi et l reception de paquets message*/
        friend QDataStream & operator << (QDataStream &, const Message &);
        friend QDataStream & operator >> (QDataStream &, Message &);

};
//Paramètrage lié à la redéfiniton des opérateurs de flux
Q_DECLARE_METATYPE(Message)
QDataStream & operator << (QDataStream & out, const Message & value);
QDataStream & operator >> (QDataStream & in, Message & value);

#endif // MESSAGE_H
