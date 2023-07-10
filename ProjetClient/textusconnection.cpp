#include "textusconnection.h"
#include "ui_textusconnection.h"
#include "user.h"
#include "message.h"
#include <QMessageBox>

TextUsConnection::TextUsConnection():
    ui(new Ui::TextUsConnection)
{
    broadcastSocket = new QUdpSocket(this);
    broadcastSocket->bind(QHostAddress::Any, 50885, QUdpSocket::ShareAddress
                          | QUdpSocket::ReuseAddressHint);
    connect(broadcastSocket, &QUdpSocket::readyRead, this, &TextUsConnection::readBroadcastDatagram);
    ui->setupUi(this);
    ui->connectionStacked->setCurrentIndex(0);
    ptrMe = new user();
    ptrDestinataire = new user();
    connexionSocket = new QTcpSocket(this);
    connect(connexionSocket, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    connect(connexionSocket, SIGNAL(connected()), this, SLOT(connecte()));
    connect(connexionSocket, SIGNAL(disconnected()), this, SLOT(deconnecte()));
    connect(connexionSocket, SIGNAL(error(QAbstractSocket::SocketError)),
    this, SLOT(erreurSocket(QAbstractSocket::SocketError)));
    modele = new QStringListModel(listedeContacts);/*initialisation de la liste des contacts*/
    controleur = 0; //permet de contrôleur la taille des paqutes
    nombreDeContacts = 0; //permet de controler le nombre de contact
    ui->userListView->setModel(modele);
}

void TextUsConnection::on_connexionButton_clicked()
{
    //connexion automatique excluant l'adresse ip locale par défaut
    ui->connexionButton->setEnabled(false);
    connexionSocket->abort();
    ptrMe->setUserName(ui->connectUserNameEdit->text());
    QHostAddress local = QHostAddress("127.0.0.1");
      for (const QHostAddress &addresses : ipAddresses) //parcours des adresse Ip reçu en broadcast
      {
          if ( addresses.toIPv4Address() != local.toIPv4Address())
          {
              connexionSocket->connectToHost(addresses, 50885);
              if (connexionSocket->waitForConnected())
              {
                  return;
              }
          }
      }
      QMessageBox msgBox; // Message en cas d'indisponibilité de connexion
      msgBox.setText("Réessayez de vous connecter.");
      msgBox.exec();
    ui->connexionButton->setEnabled(true);
}

void TextUsConnection::connecte()
{
    //fonction exécuté dès la connexion au serveur
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    QHostAddress monAdresseIP(connexionSocket->localAddress().toIPv4Address());
    ptrMe->setUserIP(monAdresseIP);
    out << (quint64) 0;
    out << (quint16) 3;
    out << *ptrMe; //envoie des informations de l'utilisateur
    out.device()->seek(0);
    out << (quint64) (paquet.size() - sizeof(quint64));
    connexionSocket->write(paquet);
    ui->notifications->append("Nouveaux Messages :"); // initialisation et chargement d'interface
    ui->connectionStacked->setCurrentIndex(1);

    // On envoie le paquet
}

void TextUsConnection::deconnecte()
{   //à exécuter lors de la deconnexion
    QMessageBox::information(this, "EneamChat-Au Revoir", tr("<em>Vous êtes bien déconnectés. Revenez nous Vite !</em>"));
}

void TextUsConnection::erreurSocket(QAbstractSocket::SocketError erreur)
{
    //fonction de gestion d'erreurs
    switch(erreur) // On affiche un message différent selon l'erreur qu'on nous indique
    {
        case QAbstractSocket::HostNotFoundError:
            QMessageBox::information(this, "EneamChat-Erreur", tr("<em>ERREUR : le serveur n'a pas pu être trouvé."
                                                           " Vérifiez l'IP et le"
                                                                " port.</em>"));
            break;
        case QAbstractSocket::ConnectionRefusedError:
            QMessageBox::information(this, "EneamChat-Erreur", tr("<em>ERREUR : le serveur a refusé la connexion."
                       " Vérifiez si le programme \"serveur\" a bien été lancé. Vérifiez aussi l'IP "
                                                                "et le port.</em>"));
            break;
        case QAbstractSocket::RemoteHostClosedError:
            QMessageBox::information(this, "EneamChat-Erreur", tr("<em>ERREUR : le serveur a coupé la "
                                                                "connexion.</em>"));
            break;
        default:
            QMessageBox::information(this, "EneamChat-Erreur", tr("<em>ERREUR : ") + connexionSocket->errorString() + tr("</em>"));
    }
    ui->connexionButton->setEnabled(true);
}

void TextUsConnection::donneesRecues()
{

     QDataStream in(connexionSocket);
    in.setVersion(QDataStream::Qt_4_6);
    forever{
        if (controleur == 0)
        {
            if (connexionSocket->bytesAvailable() < (int)sizeof(qint64))
                break;
            in >> controleur;
        }
        if (connexionSocket->bytesAvailable() < controleur)
           break;
        quint16 indicateurDeType;
        in >> indicateurDeType;
        if (indicateurDeType == 2) //reception d'un message à retransmettre
        {
            Message UnMessage;
            Message *ptrUnMsge = &UnMessage;

            in >> UnMessage;
                receptionMessage(ptrUnMsge);
        }

        if (indicateurDeType == 3) //reception d'un nouvel utilisateur à enregistrer
        {
            user NUser;
            user *ptrNUser = &NUser;
            in >> NUser;

            receptionUtilisateur(ptrNUser);
        }

        if (indicateurDeType == 1) //reception d'un utilisateur qui se déconnecte
        {
            user NUser;
            user *ptrNUser = &NUser;
            in >> NUser;
            suppressionUtilisateur(ptrNUser);
        }
        controleur = 0;
    }
}

void TextUsConnection::on_sendButton_clicked()
{
    if (ui->messageWriteZone->text().isEmpty())
        return;

    //Rajouter une condition pour ne pas activer le bouton envoyer tant que le contenu du message est vide
    QString script = ui->messageWriteZone->text();
    //Mise en forme du text
    script.replace(QRegularExpression("<<([^<{2}]*)>>"), "<i>\\1</i>");
    script.replace(QRegularExpression("{{([^{{2}]*)}}"), "<strong>\\1</strong>");
    script.replace(QRegularExpression("##([^<]*)##"), "<sub>\\1</sub>");
    script.replace(QRegularExpression("¿1([^<]*)?"), "<font face='time new roman'>\\1</font>");
    script.replace(QRegularExpression("¿2([^<]*)?"), "<font face='symbol'>\\1</font>");
    script.replace(QRegularExpression("¿3([^<]*)?"), "<font face='arial'>\\1</font>");
    script.replace(QRegularExpression("¿r([^<]*)?"), "<font color='red'>\\1</font>");
    script.replace(QRegularExpression("¿y([^<]*)?"), "<font color='yellow'>\\1</font>");
    script.replace(QRegularExpression("¿g([^<]*)?"), "<font color='green'>\\1</font>");

    QHostAddress quiRecoit(ptrDestinataire->getUserIP().toIPv4Address());
    QDateTime dateHeure = QDateTime::currentDateTime() ; //heure d'envoie
    QString messageAEnvoyer = tr("<strong>") + ptrMe->getUserName() + tr("</strong> : ") + script + "<br/>" + dateHeure.toString("dd MMMM yyyy hh:mm:ss");
    Message paquetMessage(quiRecoit, ptrMe->getUserName(), ptrDestinataire->getUserName(), messageAEnvoyer);
    //initialisation du contenu à lire du paquet messahe
    ptrDestinataire->addMessages(paquetMessage);
    ui->discussionZone->append(messageAEnvoyer);
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    out << (quint64) 0;
    out << (quint16) 2;
    out << paquetMessage;//envoie du paquet message
    out.device()->seek(0);
    out << (quint64) (paquet.size() - sizeof(quint64));
    connexionSocket->write(paquet); // On envoie le paquet
    ui->messageWriteZone->clear(); // On vide la zone d'écriture du message
    ui->messageWriteZone->setFocus(); // Et on remet le curseur à l'intérieur
}

void TextUsConnection::on_messageWriteZone_returnPressed()
{
    on_sendButton_clicked(); //raccourçi
}

void TextUsConnection::afficherDiscussion()
{
    //initialisation et chargement de l'interface de discussion
    ui->receverName->setText(ptrDestinataire->getUserName());
    ui->connectionStacked->setCurrentIndex(2);
    showMessages(ptrDestinataire->getHistoriqueMessages());
}

void TextUsConnection::showMessages(QList<Message> &liste)
{
    //affichage de l'historique des échange pour un contact
    if (liste.size() != 0)
    {
        for (int i = 0; i < liste.size(); i++)
        {
            ui->discussionZone->append(liste[i].content());
        }
    }
}

void TextUsConnection::receptionMessage(Message *ptrNouveauMessage)
{
    //proccessus de redirection et de classement des messages selon le destinateur
  QByteArray paquet;
  QDataStream in(&paquet, QIODevice::WriteOnly);
  for (int i = 0; i < utilisateurs.count(); i++)
  {
      if (utilisateurs[i].getUserName() == ptrNouveauMessage->sender())
      {
          utilisateurs[i].addMessages(*ptrNouveauMessage);
          if (ui->connectionStacked->currentIndex() == 2 && ptrDestinataire->getUserName() == utilisateurs[i].getUserName())
          {
              ui->discussionZone->append(ptrNouveauMessage->content());
          }else
          {
              ui->notifications->append("nouveau message de " + utilisateurs[i].getUserName() + "<br/>");
          }
          break;
      } 
  }

}

void TextUsConnection::receptionUtilisateur(user *ptrnouvelUtilisateur)
{
    //poccessus de gestion des nouveaux contact et mise à jour de la liste des contacts
      nombreDeContacts++;
      if (ptrMe->getUserIP() == ptrnouvelUtilisateur->getUserIP() && nombreDeContacts == 1)
      {
          ptrMe->setUserName(ptrnouvelUtilisateur->getUserName());
          ui->myName->setText(ptrMe->getUserName());         
      }else
      {
          if (ptrnouvelUtilisateur->getUserName() == ptrMe->getUserName())
          {

          }else
          {
              listedeContacts << ptrnouvelUtilisateur->getUserName();
              modele->setStringList(listedeContacts);
              utilisateurs << *ptrnouvelUtilisateur;
          }

      }
}

void TextUsConnection::suppressionUtilisateur(user *ptrancienutilisateur)
{
    //fonction pour supprimer un contact déconnecté
    for (int i = 0; i < utilisateurs.size(); i++)
    {
        if (utilisateurs[i].getUserIP().toIPv4Address() == ptrancienutilisateur->getUserIP().toIPv4Address())
        {
            if (ptrDestinataire->getUserIP().toIPv4Address() == utilisateurs[i].getUserIP().toIPv4Address()  && ui->connectionStacked->currentIndex()==2)
            {
                ui->discussionZone->append("<br/><font color='red'> Cet utililusateur n'est plus joignable actuellement </font>");// afficher que le destinataire n'est plus disponible
                ui->sendButton->setEnabled(false);//désactiver le bouton d'envoi
            }

            QString nom = utilisateurs[i].getUserName();
            for (int j = 0; j < listedeContacts.size(); j++) // à tester
            {
                if (listedeContacts[j] == nom)
                {
                    ui->notifications->append(nom + " s'est déconnecté.");
                    listedeContacts.at(j);
                    utilisateurs.removeAt(i);
                    modele->setStringList(listedeContacts);
                    nombreDeContacts = utilisateurs.size();
                    break;
                }
            }
            break;
        }
    }
}

TextUsConnection::~TextUsConnection()
{
}

void TextUsConnection::on_goBackButton_clicked()
{
    //gestion du retour vers la liste des contacts
    ui->connectionStacked->setCurrentIndex(1);
    ui->receverName->setText("");
    ui->discussionZone->clear();
    ui->messageWriteZone->clear();
    ui->sendButton->setEnabled(true);//désactiver le bouton d'envoie
}

void TextUsConnection::on_homeReturnButton_clicked()
{
    //dispositions de déconnexion du client
    connexionSocket->abort();
    ui->connectionStacked->setCurrentIndex(0);
    utilisateurs.clear();
    listedeContacts.clear();
    nombreDeContacts = 0;
    ui->notifications->clear();
    ui->connexionButton->setEnabled(true);
}

void TextUsConnection::readBroadcastDatagram()
{
    //fonction de lecture des adresses Ip
    ipAddresses.clear();

    while (broadcastSocket->hasPendingDatagrams())
    {
        QNetworkDatagram datagram;
        QByteArray data;
        QDataStream in(data);
        in.setVersion(QDataStream::Qt_4_6);
        QHostAddress newIp;
        datagram = broadcastSocket->receiveDatagram();
        data = datagram.data();
        in >> newIp;

        ipAddresses << datagram.senderAddress() ; //reception des adresses ip en broadcast

    }
}

void TextUsConnection::on_userListView_doubleClicked(const QModelIndex &index)
{
    //Selection des utilisateurs pour discuter
    QVariant elementSelectionne = modele->data(index, Qt::DisplayRole);
    for (int i = 0; i < utilisateurs.size(); i++)
    {
        QString nom = utilisateurs[i].getUserName();
        if (elementSelectionne.toString() == nom)
        {
            ptrDestinataire = &utilisateurs[i];
            afficherDiscussion();
            return;
        }
    }
}

