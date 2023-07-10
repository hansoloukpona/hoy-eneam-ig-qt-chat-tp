
#include "textusserver.h"
#include "message.h"
#include "user.h"

static const qint32 BroadcastInterval = 2000;


TextUsServer::TextUsServer(QWidget *parent) :
    QWidget(parent)
  {
  // Création et disposition des widgets de la fenêtre
      etatServeur = new QLabel;
      boutonQuitter = new QPushButton(tr("Quitter"));
      connect(boutonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
      QVBoxLayout *layout = new QVBoxLayout;
      layout->addWidget(etatServeur);
      layout->addWidget(boutonQuitter);
      setLayout(layout); //Ajouter un QLabel pour afficher le nombre de Client : nombreClient+1
      setWindowTitle(tr("EneamChat - Serveur"));
      nombreClient = 0; //initalisation du nombre de socket
      nombreUtilisateur = 0;//initialisation du nombre d'utilusateurs identifiés
      serveur = new QTcpServer(this);
      if (!serveur->listen(QHostAddress::Any, 50885)) // Démarrage du serveur sur toutes les IP disponibles et sur le port 50585
      {     // Si le serveur n'a pas été démarré correctement
          etatServeur->setText(tr("Le serveur n'a pas pu être démarré. Raison :<br />") + serveur->errorString());
      }
      else
      {    // Si le serveur a été démarré correctement
          etatServeur->setText(tr("Le serveur a été démarré sur le port <strong>")
                               + QString::number(serveur->serverPort()) +
                    tr("</strong>.<br />Des clients peuvent maintenant se connecter."));
          connect(serveur, SIGNAL(newConnection()), this, SLOT(nouvelleConnexion()));
      }
      broadcastSocket = new QUdpSocket(this); //initialisation du socket qui permet la connection automatique
      updateAddresses(); // Mise à jour des adresses de broadcast
      broadcastTimer = new QTimer(this);
      broadcastTimer->setInterval(BroadcastInterval);

      connect(broadcastTimer, &QTimer::timeout, this, &TextUsServer::sendBroadcastDatagram);

      startBroadcasting(); // Mise en marche du système de connection automatique
  }

  void TextUsServer::nouvelleConnexion()
  { // fonction exécuté lors d'une nouvelle connection

      QTcpSocket *socketDeConnexion = serveur->nextPendingConnection();
      connect(socketDeConnexion, SIGNAL(disconnected()), this, SLOT(deconnexionClient()));
      qint64 tailleContenuSocket = 0;
      tailles << tailleContenuSocket;
      listeOfSocket << socketDeConnexion; //enregistrement du socket
      nombreClient = listeOfSocket.size();
      connect(socketDeConnexion, SIGNAL(readyRead()), this, SLOT(verification()));
  }

  void TextUsServer::verification()
  {
      QTcpSocket *socketDeVerification = qobject_cast<QTcpSocket *>(sender());

      if (socketDeVerification == 0) // Si par hasard on n'a pas trouvé le client à l'origine du signal, on arrête la méthode
            return;
          for (qint64 i = 0; i < listeOfSocket.size(); i++)
          {
                if (listeOfSocket[i]->peerAddress().toIPv4Address() == socketDeVerification->peerAddress().toIPv4Address())
                {
                    donneesRecues(socketDeVerification, tailles[i]);
                        return;
                }
          }
   }


  void TextUsServer::donneesRecues(QTcpSocket *socketDePaquetRecu, qint64 &taillePaquetRecu)
  {

      QDataStream in(socketDePaquetRecu);
      in.setVersion(QDataStream::Qt_4_6);

       forever{
           if (taillePaquetRecu == 0)
               {
                  if (socketDePaquetRecu->bytesAvailable() < (int)sizeof(qint64))
                      break;
                  in >> taillePaquetRecu;
               }
           if (socketDePaquetRecu->bytesAvailable() < taillePaquetRecu)
                  break;
           qint16 typeIndic;
           in >> typeIndic;

           if (typeIndic == 2)
           {

               Message UnMessage;
               Message *ptrMsge = &UnMessage;
               in >> UnMessage;
               traitementMessage(ptrMsge);
               taillePaquetRecu = 0;
               break;
           }else if (typeIndic == 3) //3 identifie un utilisateur
           {
               //user UnNUser;
               user *ptrUnNUser = new user(QHostAddress("0.0.0.0"), "unknow");
               in >> *ptrUnNUser;
               traitementUtilisateur(socketDePaquetRecu, ptrUnNUser);
               taillePaquetRecu = 0;
               break;
           }

  }
}

void TextUsServer::traitementMessage(Message *ptrPaquetMessage)
{
    QByteArray paquetMessage;
    QDataStream out(&paquetMessage, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    QHostAddress quiRecoit(ptrPaquetMessage->senderIP().toIPv4Address());

            out << (qint64) 0;
            out << (quint16) 2; //2 identifie un message
            out << *ptrPaquetMessage;
            out.device()->seek(0);
            out << (qint64) (paquetMessage.size() - sizeof(qint64));
    for (int i = 0; i < listeOfSocket.size(); i++)
    {
        if (listeOfSocket[i]->peerAddress().toIPv4Address() == quiRecoit.toIPv4Address())
        {
            listeOfSocket[i]->write(paquetMessage);
            break;
        }
    }
}

void TextUsServer::traitementUtilisateur(QTcpSocket *socketdelUtilisateur, user *ptrInfoUtilisateur)
{    
    QByteArray paquetInfoU;
    QDataStream out(&paquetInfoU, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    QString a_verifier = ptrInfoUtilisateur->getUserName();
    const quint16 tailleInitiale = a_verifier.size();
    int iterator = 0;
    nameDefine(a_verifier, tailleInitiale, iterator);
    ptrInfoUtilisateur->setUserName(a_verifier);
    utilisateurs << ptrInfoUtilisateur;
    nombreUtilisateur = utilisateurs.size();
    for (int i = 0; i < listeOfSocket.size(); i++)
    {
        if (listeOfSocket[i]->peerAddress() == socketdelUtilisateur->peerAddress())
        {
            ptrInfoUtilisateur->setUserSocket(listeOfSocket[i]);
            break;
        }
    } //les 4 lignes suivantes n'ont pas encore été testés
     out << (quint64) 0;
     out << (quint16) 3;
     out << *ptrInfoUtilisateur;
     out.device()->seek(0);
     out << (quint64) (paquetInfoU.size() - sizeof(quint64));

    for (int i = 0; i < listeOfSocket.size(); i++)
    {
        listeOfSocket[i]->write(paquetInfoU);
    }
    listeDesParticipants(socketdelUtilisateur);
    //delete ptrInfoUtilisateur;
}

void TextUsServer::listeDesParticipants(QTcpSocket *socketdEnvoiDeListe)
{
    for (int i = 0; i < utilisateurs.size(); i++)
    {
        /*if (utilisateurs[i]->getUserIP().toIPv4Address() == socketdEnvoiDeListe->peerAddress().toIPv4Address())
        {
            continue;
        }*/
        QByteArray paquetDeListe;
        QDataStream out(&paquetDeListe, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_6);
         out << (qint64) 0;
         out << (quint16) 3; //1 indentifie une liste de contact
         out << *utilisateurs[i];
         out.device()->seek(0);
         out << (qint64) (paquetDeListe.size() - sizeof(qint64));
         socketdEnvoiDeListe->write(paquetDeListe);
    }
}



  void TextUsServer::envoyerATous(const QString &message)
  {
      // Cette fonctin à été modifiée et conservée dans un but éventuel d'administration du Chat
      // Préparation du paquet
      QByteArray paquet;
      QDataStream out(&paquet, QIODevice::WriteOnly);

      out << (qint16) 0; // On écrit 0 au début du paquet pour réserver la place pour écrire la taille
      out << message; // On ajoute le message à la suite
      out.device()->seek(0); // On se replace au début du paquet
      out << (qint16) (paquet.size() - sizeof(qint16)); /* On écrase
      le 0 qu'on avait réservé par la longueur du message
      Envoi du paquet préparé à tous les clients connectés au
      serveur */
      for (int i = 0; i < listeOfSocket.size(); i++)
      {
        listeOfSocket[i]->write(paquet);
      }
  }

  void TextUsServer::nameDefine(QString &nom_a_verifier, const quint16 &taille_ini_table, int &j)
  {
      //Cette fonction doit recevoir une taille fixe, donc on doit connaitre la taille_initialle
      // il faut donc déclarer une variable constante à laqulle attribuer la taille initiale du nom entré
      int extend = j;
      for(int i = 0; i < utilisateurs.count(); i++)
      {
          if (nom_a_verifier == utilisateurs[i]->getUserName())
          {
              extend++;
              nom_a_verifier.truncate(taille_ini_table);
              nom_a_verifier = nom_a_verifier + QString("+");
              /* si le nom entré par un utilusateur est déjé utilisé dans le Chat
               * cette fonction ajoute un + au nom et s'assure que le resultat n'est
               * pas déjé utilusé lui aussi...*/
              return nameDefine(nom_a_verifier, taille_ini_table, extend);
          }
      }
  }

  void TextUsServer::deconnexionClient()
    {
        // On détermine quel client se déconnecte
        QTcpSocket *socketDeDeconnexion = qobject_cast<QTcpSocket *>(sender());
        if (socketDeDeconnexion == 0) // Si par hasard on n'a pas trouvé le client à l'origine du signal, on arrête la méthode
              return;
        QHostAddress auRevoirIp(socketDeDeconnexion->peerAddress());
        QByteArray paquetDepart;
        QDataStream out(&paquetDepart, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_6);
        //envoi d'un paquet de déconnexion à tout les clients
        for (int k = 0; k < utilisateurs.size(); k++)
        {
            if (utilisateurs[k]->getUserIP().toIPv4Address() == auRevoirIp.toIPv4Address())
            {
                user *ptrGoodBye = utilisateurs.takeAt(k);

                out << (quint64) 0;
                out << (quint16) 1; //1 indentifie utilusateur qui se déconnecte
                out << *ptrGoodBye;
                out.device()->seek(0);
                out << (quint64) (paquetDepart.size() - sizeof(quint64));

                for (int j = 0; j < listeOfSocket.size(); j++)
                {
                    listeOfSocket[j]->write(paquetDepart);
                }

                delete ptrGoodBye;
            }
        }
        //suppression de l'utilisateur au niveau du serveur
        for (int l = 0; l < listeOfSocket.size(); l++)
        {
            if (listeOfSocket[l]->peerAddress() == auRevoirIp)
            {
                listeOfSocket.removeAt(l);
                tailles.removeAt(l);
            }
        }
        socketDeDeconnexion->deleteLater();
        nombreUtilisateur = utilisateurs.size();
        nombreClient = listeOfSocket.size();
    }

  TextUsServer::~TextUsServer()
  {
  }

  void TextUsServer::sendBroadcastDatagram()
  {
      /*cette fonction envoi en broadcast l'adresse du serveur pour que des clients
       *  le récupère et se connectent automatisuement*/
      QByteArray data;
      QDataStream out(&data, QIODevice::WriteOnly);
      out.setVersion(QDataStream::Qt_4_6);

      out << serveur->serverAddress();
      bool validBroadcastAddresses = true;
      for (const QHostAddress &address : qAsConst(broadcastAddresses)) {
          QNetworkDatagram datagram (data, address, 50885);
          if (broadcastSocket->writeDatagram(datagram) == -1)
              validBroadcastAddresses = false;
      }

      if (!validBroadcastAddresses)
          updateAddresses();
  }

  void TextUsServer::startBroadcasting()
  {
      broadcastTimer->start();
  }

  void TextUsServer::updateAddresses()
  {
      /*cette fonction met à jour la liste des adresse de broadcast du réseau
       * pour permettre au serveur d'envoi son Ip en broadcast*/
      broadcastAddresses.clear();
      const QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
      for (const QNetworkInterface &interfac : interfaces) {
          const QList<QNetworkAddressEntry> entries = interfac.addressEntries();
          for (const QNetworkAddressEntry &entry : entries) {
              QHostAddress broadcastAddress = entry.broadcast();
              if (broadcastAddress != QHostAddress::Null ) {
                  broadcastAddresses << broadcastAddress;
              }
          }
      }
  }
