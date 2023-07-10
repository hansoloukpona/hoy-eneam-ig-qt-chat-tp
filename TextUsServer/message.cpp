#include "message.h"

Message::Message()
{

}

Message::Message(const Message &copie)
{
    m_senderIP = copie.m_senderIP;       //taille du message
    m_sender = copie.m_sender;  //Ip du destinateur
    m_recever = copie.m_recever; //Ip du destinataire
    m_content = copie.m_content;      //contenu du message
}

Message::Message(const QHostAddress &senderIP, const QString &sender, const QString &recever, const QString &message):
    m_senderIP(senderIP), m_sender(sender),m_recever(recever), m_content(message)
{
}

void Message::initMessageSystem()
{
    qRegisterMetaType<Message>("Message");
    qMetaTypeId<Message>();
}

 QString &Message::sender()
{
    return m_sender;
}

void Message::setSender(const QString &newSender)
{
    m_sender = newSender;
}

QString &Message::recever()
{
    return m_recever;
}

void Message::setRecever(const QString &newRecever)
{
    m_recever = newRecever;
}

QString &Message::content()
{
    return m_content;
}

void Message::setContent(const QString &newContent)
{
    m_content = newContent;
}

QHostAddress Message::senderIP() const
{
    return m_senderIP;
}

void Message::setSenderIP(QHostAddress newSenderIP)
{
    m_senderIP = newSenderIP;
}

QDataStream & operator << (QDataStream & out, const Message & value)
{
    out << value.m_senderIP
           << value.m_sender
           << value.m_recever
           << value.m_content;
    return out;
}

QDataStream & operator >> (QDataStream & in, Message & value)
{
    in >> value.m_senderIP
           >> value.m_sender
           >> value.m_recever
           >> value.m_content;
    return in;
}


Message::~Message()
{

}
