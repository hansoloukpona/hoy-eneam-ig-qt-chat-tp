#ifndef TEXTUSCONNECTION_H
#define TEXTUSCONNECTION_H

#include <QtWidgets>
#include <QtNetwork>
#include <QWidget>
//#include <QDialog>
#include <QObject>
#include <QByteArray>
//#include <QList>
//#include <QObject>
#include <QTimer>
#include <QTcpSocket>


class user; //Rappel de l'existence d'une classe user dans le but de s'en servir
class Message; //Rappel de l'existence d'une classe Messages dans le but de s'en servir

namespace Ui {
class TextUsConnection;
//La Classe dispose d'une inteface graphique dévellopée à partir du Qt Designer
}

/* Déclaration de la classe TextUsConnection qui permet de gérer et coordonner
 * la connexion d'un utilisateur, l'envoi et la réception des
 * paquets messages et des informations sur les utilisaturs et la déconnexion*/
class TextUsConnection : public QWidget
{
    Q_OBJECT

    public:
        explicit TextUsConnection(); //Constructeur Unique
        ~TextUsConnection(); //Destructeur
        void receptionUtilisateur(user *ptrnouvelutilisateur);
        /*Cette fonction s'occupe d'enregistrer et disposer à l'usage
         * les informations reçu lors de la connexion d'un nouvel
         * utilisateur*/
        void suppressionUtilisateur(user *ptrancienutilisateur);
        /*Cette fonction s'occupe de rendre indisponible à l'usage
         *  et de supprimer les informations reçu lors de la
         *  déconnexion d'un nouvel utilisateur*/
        void receptionMessage(Message *ptrNouveauMessage);
        /*Cette fonction s'occupe d'enregistrer et disposer à l'usage
         * les informations reçu lors de la reception d'un nouveau
         * paquet Message*/
        void showMessages(QList<Message> &liste);
        //Cette fonction s'occupe d'afficher un historique de conversation
        qint64 controleur; /*Il permet d'assurer dans la fonction "donneesRecues"
                             la bonne reception de l'entièreté des données
                             envoyées par le serveur*/
        void startBroadcasting();
        /*Cette fonction permet de chercher les adresses de tout les serveurs en
         * ligne sur le réseau... Il revient pour l'instant à celui qui se sert de l'application
         * de s'assurer qu'il n'y ai qu'un seul serveur en ligne pour que tout le
         *  monde soit connecté au même serveur*/

    private slots:
        void donneesRecues();
        /*Ce slot permet de recevoir des données du serveur et de déterminer
         * l'usage que doit en faire le système*/
        void on_connexionButton_clicked();
        /*Ce slot permet de lancer une connexion automatique au serveur
         * disponible en appuyant sur le bouton de connexion de
         * l'interface d'acceuil*/
        void connecte();
        /*Ce slot s'occupe d'envoyer les informations d'un utilisateur dès
         * sa connexion au serveur*/
        void deconnecte();
        /*Ce slot s'occupe de rendre éffective la déconnexion d'un utilisateur
         * en rendant inaccessible puis en supprimant ses informations*/
        void on_sendButton_clicked();
        /*Ce slot permet de déclencher l'envoi d'un paquet */
        void on_messageWriteZone_returnPressed();
        /*Ce slot constitue un raccourci qui permet de déclencher l'envoi
         * d'un paquet en appuyant sur la touche entrée du clavier*/
        void on_goBackButton_clicked();
        /*Ce slot permet de sortir de l'interface de disccussion pour aller
         * vers la liste de contact*/
        //void initDiscussion();
        void afficherDiscussion();
        /*Ce slot permet de charger l'interface de discussion pour converser
         * avec destinataire*/
        void on_homeReturnButton_clicked();
        /*Ce slot permet de sortir de l'interface de liste de contact pour
         *  aller vers la liste de contact*/
        void erreurSocket(QAbstractSocket::SocketError erreur);
        /*Ce slot permet de gérer les erreurs liées à la connexion au serveur*/
        void readBroadcastDatagram();
        /*Ce slot permet de récupérer les adresses de tout les serveurs en
         * ligne sur le réseau...*/
        void on_userListView_doubleClicked(const QModelIndex &index);
        /*Permet de sélectionner un utilisateur avec qui on veut échanger
         * des messages*/
    protected:
        Ui::TextUsConnection *ui;
        //Attribut de l'interface graphique conçu par Qt Designer
        QTcpSocket *connexionSocket;
        //Socket permettant la connexion l'échange de message et la déconnexion
        user *ptrMe;
        /*Ce pointeur représente en permanence l'utilisateur qui est connecté
         * à travers le client*/
        user *ptrDestinataire;
        /*Ce pointeur représente l'utilisateur avec qui on converse actuellement
         * à travers le client*/
        QList<user> utilisateurs;
        /*Cet attribut est une liste des utilisateurs qui sont connectés au
         * niveau du serveur*/
        quint64 nombreDeContacts;
        //Cet attribut permet de connaitre le nombre de contact connectés
        QList<QHostAddress> ipAddresses;
        /*Cet attribut acceuil une liste régulièrement mise à jour des serveurs
         *  disponibles sur un réseau*/
        QTimer broadcastTimer; /*Temps de repos entre l'actualisation de la
                                 liste des serveurs*/
        //int serverPort;
        QUdpSocket *broadcastSocket;
        /*Socket permettant de collecter une liste des serveurs disposés à
         * la connexion */

        QStringList listedeContacts;
        //Liste des nom des contacts
        QStringListModel *modele;
        //modèle de liste permettant l'affichage de la liste des nom d'utilusateurs

};
#endif // PEERMANAGER_H
