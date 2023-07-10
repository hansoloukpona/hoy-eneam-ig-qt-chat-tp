#ifndef TEXTUSSERVER_H
#define TEXTUSSERVER_H

#include <QtWidgets>
#include <QtNetwork>

class Message;
class user;
class TextUsServer : public QWidget
{
    Q_OBJECT

    public:
        TextUsServer(QWidget *parent = nullptr);
        TextUsServer(const TextUsServer & copie);
        ~TextUsServer();
        void startBroadcasting();
        void envoyerATous(const QString &message);
        void traitementMessage(Message *ptrPaquetMessage);
        void traitementUtilisateur(QTcpSocket *socketdelUtilisateur, user *ptrInfoUtilisateur);
        void donneesRecues(QTcpSocket * socketDePaquetRecu, qint64 & taillePaquetRecu);
        void listeDesParticipants(QTcpSocket *socketdEnvoiDeListe);
        void nameDefine(QString &nom_a_verifier, const quint16 &table_init_taille, int &j);
    private slots:
        void sendBroadcastDatagram();
        void nouvelleConnexion();
        void deconnexionClient();
        void verification();
    private:
        void updateAddresses();
        QTcpServer *serveur;
        QLabel *etatServeur;
        QPushButton *boutonQuitter;
        qint64 nombreClient;
        qint64 nombreUtilisateur;
        QList<QTcpSocket *> listeOfSocket;
        QList<user *> utilisateurs;
        QList<qint64> tailles;
        QUdpSocket *broadcastSocket;
        QList<QHostAddress> broadcastAddresses;
        QTimer *broadcastTimer;
};
#endif // TEXTUSSERVER_H
