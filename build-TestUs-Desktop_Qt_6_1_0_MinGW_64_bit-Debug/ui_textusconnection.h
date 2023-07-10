/********************************************************************************
** Form generated from reading UI file 'textusconnection.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTUSCONNECTION_H
#define UI_TEXTUSCONNECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextUsConnection
{
public:
    QStackedWidget *connectionStacked;
    QWidget *connection;
    QWidget *connectFormWidget;
    QLabel *connectFormIndication;
    QLineEdit *connectUserNameEdit;
    QLabel *connectlUserNameLabel;
    QPushButton *connexionButton;
    QLabel *label_3;
    QWidget *Home;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayoutHome;
    QLabel *appNameLabelHome;
    QVBoxLayout *verticalLayoutHome_2;
    QHBoxLayout *horizontalLayoutHome;
    QPushButton *homeReturnButton;
    QLabel *myName;
    QHBoxLayout *horizontalLayout;
    QListView *userListView;
    QTextEdit *notifications;
    QWidget *Discussion;
    QWidget *widget;
    QLabel *appNameLabel_2;
    QLabel *receverName;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *messageWriteZone;
    QPushButton *sendButton;
    QPushButton *goBackButton;
    QTextEdit *discussionZone;

    void setupUi(QWidget *TextUsConnection)
    {
        if (TextUsConnection->objectName().isEmpty())
            TextUsConnection->setObjectName(QString::fromUtf8("TextUsConnection"));
        TextUsConnection->resize(500, 460);
        TextUsConnection->setMinimumSize(QSize(500, 460));
        TextUsConnection->setMaximumSize(QSize(500, 460));
        TextUsConnection->setStyleSheet(QString::fromUtf8(""));
        connectionStacked = new QStackedWidget(TextUsConnection);
        connectionStacked->setObjectName(QString::fromUtf8("connectionStacked"));
        connectionStacked->setEnabled(true);
        connectionStacked->setGeometry(QRect(0, 0, 480, 450));
        connectionStacked->setMinimumSize(QSize(480, 450));
        connectionStacked->setStyleSheet(QString::fromUtf8(""));
        connection = new QWidget();
        connection->setObjectName(QString::fromUtf8("connection"));
        connectFormWidget = new QWidget(connection);
        connectFormWidget->setObjectName(QString::fromUtf8("connectFormWidget"));
        connectFormWidget->setGeometry(QRect(80, 150, 330, 260));
        connectFormWidget->setMinimumSize(QSize(330, 260));
        connectFormWidget->setStyleSheet(QString::fromUtf8("border-radius:8pt;\n"
"background-color: rgb(0, 0, 0);\n"
"\n"
""));
        connectFormIndication = new QLabel(connectFormWidget);
        connectFormIndication->setObjectName(QString::fromUtf8("connectFormIndication"));
        connectFormIndication->setGeometry(QRect(60, 60, 210, 30));
        connectFormIndication->setMinimumSize(QSize(210, 30));
        connectFormIndication->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Century Gothic\";"));
        connectUserNameEdit = new QLineEdit(connectFormWidget);
        connectUserNameEdit->setObjectName(QString::fromUtf8("connectUserNameEdit"));
        connectUserNameEdit->setGeometry(QRect(20, 140, 200, 20));
        connectUserNameEdit->setMinimumSize(QSize(200, 20));
        connectUserNameEdit->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-top:none;\n"
"border-right:none;\n"
"border-bottom:3pt;\n"
" \n"
"border-bottom-color: rgb(177, 171, 175);\n"
"color: rgb(67, 67, 67);\n"
"font: 12pt \"Comic Sans MS\";\n"
"placeholder:\"Nom d'utilisateur\";"));
        connectUserNameEdit->setClearButtonEnabled(true);
        connectlUserNameLabel = new QLabel(connectFormWidget);
        connectlUserNameLabel->setObjectName(QString::fromUtf8("connectlUserNameLabel"));
        connectlUserNameLabel->setGeometry(QRect(20, 110, 190, 15));
        connectlUserNameLabel->setMinimumSize(QSize(190, 15));
        connectlUserNameLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 13pt \"Comic Sans MS\";"));
        connexionButton = new QPushButton(connectFormWidget);
        connexionButton->setObjectName(QString::fromUtf8("connexionButton"));
        connexionButton->setGeometry(QRect(60, 200, 210, 30));
        connexionButton->setMinimumSize(QSize(210, 30));
        connexionButton->setAutoFillBackground(false);
        connexionButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"font: 14pt \"Century Gothic\";\n"
"border-radius:8pt;\n"
"color: rgb(255, 255, 255);"));
        connexionButton->setCheckable(true);
        connexionButton->setChecked(false);
        connexionButton->setAutoRepeat(false);
        connexionButton->setAutoExclusive(false);
        connexionButton->setAutoDefault(false);
        connexionButton->setFlat(false);
        label_3 = new QLabel(connection);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 50, 330, 40));
        label_3->setMinimumSize(QSize(330, 40));
        label_3->setAutoFillBackground(false);
        label_3->setStyleSheet(QString::fromUtf8("font: 75 20pt \"Comic Sans MS\";\n"
"color:rgb(0, 0, 0);"));
        connectionStacked->addWidget(connection);
        Home = new QWidget();
        Home->setObjectName(QString::fromUtf8("Home"));
        verticalLayoutWidget_2 = new QWidget(Home);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 20, 431, 413));
        verticalLayoutHome = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayoutHome->setObjectName(QString::fromUtf8("verticalLayoutHome"));
        verticalLayoutHome->setContentsMargins(9, 9, 9, 9);
        appNameLabelHome = new QLabel(verticalLayoutWidget_2);
        appNameLabelHome->setObjectName(QString::fromUtf8("appNameLabelHome"));
        appNameLabelHome->setMinimumSize(QSize(412, 20));
        appNameLabelHome->setMaximumSize(QSize(16777215, 20));
        appNameLabelHome->setStyleSheet(QString::fromUtf8("font: 75 18pt \"Comic Sans MS\";"));

        verticalLayoutHome->addWidget(appNameLabelHome);

        verticalLayoutHome_2 = new QVBoxLayout();
        verticalLayoutHome_2->setObjectName(QString::fromUtf8("verticalLayoutHome_2"));
        horizontalLayoutHome = new QHBoxLayout();
        horizontalLayoutHome->setObjectName(QString::fromUtf8("horizontalLayoutHome"));
        horizontalLayoutHome->setContentsMargins(3, 3, 3, 3);
        homeReturnButton = new QPushButton(verticalLayoutWidget_2);
        homeReturnButton->setObjectName(QString::fromUtf8("homeReturnButton"));
        homeReturnButton->setMinimumSize(QSize(115, 23));
        homeReturnButton->setMaximumSize(QSize(115, 16777215));

        horizontalLayoutHome->addWidget(homeReturnButton);

        myName = new QLabel(verticalLayoutWidget_2);
        myName->setObjectName(QString::fromUtf8("myName"));
        myName->setMaximumSize(QSize(16777215, 20));
        myName->setAutoFillBackground(false);

        horizontalLayoutHome->addWidget(myName);


        verticalLayoutHome_2->addLayout(horizontalLayoutHome);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        userListView = new QListView(verticalLayoutWidget_2);
        userListView->setObjectName(QString::fromUtf8("userListView"));
        userListView->setMinimumSize(QSize(260, 330));
        userListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        userListView->setDefaultDropAction(Qt::IgnoreAction);

        horizontalLayout->addWidget(userListView);

        notifications = new QTextEdit(verticalLayoutWidget_2);
        notifications->setObjectName(QString::fromUtf8("notifications"));
        notifications->setMinimumSize(QSize(0, 330));
        notifications->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(notifications);


        verticalLayoutHome_2->addLayout(horizontalLayout);


        verticalLayoutHome->addLayout(verticalLayoutHome_2);

        connectionStacked->addWidget(Home);
        Discussion = new QWidget();
        Discussion->setObjectName(QString::fromUtf8("Discussion"));
        widget = new QWidget(Discussion);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 10, 440, 400));
        widget->setMinimumSize(QSize(440, 400));
        appNameLabel_2 = new QLabel(widget);
        appNameLabel_2->setObjectName(QString::fromUtf8("appNameLabel_2"));
        appNameLabel_2->setGeometry(QRect(10, 10, 420, 30));
        appNameLabel_2->setMinimumSize(QSize(420, 30));
        appNameLabel_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 16pt \"Comic Sans MS\";"));
        receverName = new QLabel(widget);
        receverName->setObjectName(QString::fromUtf8("receverName"));
        receverName->setGeometry(QRect(130, 52, 300, 20));
        receverName->setMinimumSize(QSize(300, 20));
        horizontalLayoutWidget = new QWidget(widget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 370, 421, 26));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        messageWriteZone = new QLineEdit(horizontalLayoutWidget);
        messageWriteZone->setObjectName(QString::fromUtf8("messageWriteZone"));
        messageWriteZone->setMinimumSize(QSize(338, 20));

        horizontalLayout_3->addWidget(messageWriteZone);

        sendButton = new QPushButton(horizontalLayoutWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setMinimumSize(QSize(75, 23));

        horizontalLayout_3->addWidget(sendButton);

        goBackButton = new QPushButton(widget);
        goBackButton->setObjectName(QString::fromUtf8("goBackButton"));
        goBackButton->setGeometry(QRect(9, 53, 115, 20));
        goBackButton->setMinimumSize(QSize(115, 20));
        discussionZone = new QTextEdit(widget);
        discussionZone->setObjectName(QString::fromUtf8("discussionZone"));
        discussionZone->setGeometry(QRect(10, 90, 421, 281));
        discussionZone->setMinimumSize(QSize(421, 281));
        discussionZone->setUndoRedoEnabled(false);
        discussionZone->setReadOnly(true);
        connectionStacked->addWidget(Discussion);

        retranslateUi(TextUsConnection);

        connectionStacked->setCurrentIndex(1);
        connexionButton->setDefault(false);


        QMetaObject::connectSlotsByName(TextUsConnection);
    } // setupUi

    void retranslateUi(QWidget *TextUsConnection)
    {
        TextUsConnection->setWindowTitle(QCoreApplication::translate("TextUsConnection", "EneamChat", nullptr));
        connectFormIndication->setText(QCoreApplication::translate("TextUsConnection", "CONNECTEZ-VOUS ICI ", nullptr));
        connectUserNameEdit->setPlaceholderText(QCoreApplication::translate("TextUsConnection", "Entrez votre identifiant", nullptr));
        connectlUserNameLabel->setText(QCoreApplication::translate("TextUsConnection", "Nom d'utilisateur", nullptr));
        connexionButton->setText(QCoreApplication::translate("TextUsConnection", "Connectez-vous", nullptr));
        label_3->setText(QCoreApplication::translate("TextUsConnection", "Bienvenue sur EneamChat", nullptr));
        appNameLabelHome->setText(QCoreApplication::translate("TextUsConnection", "EneamChat", nullptr));
        homeReturnButton->setText(QCoreApplication::translate("TextUsConnection", "Quitter", nullptr));
        myName->setText(QCoreApplication::translate("TextUsConnection", "My Name", nullptr));
        appNameLabel_2->setText(QCoreApplication::translate("TextUsConnection", "EneamChat", nullptr));
        receverName->setText(QCoreApplication::translate("TextUsConnection", "Nom du Destinataire", nullptr));
        messageWriteZone->setPlaceholderText(QCoreApplication::translate("TextUsConnection", "\303\211crivez votre message ici...", nullptr));
        sendButton->setText(QCoreApplication::translate("TextUsConnection", "Envoyer", nullptr));
        goBackButton->setText(QCoreApplication::translate("TextUsConnection", "Retour", nullptr));
        discussionZone->setPlaceholderText(QCoreApplication::translate("TextUsConnection", "Vos \303\251changes de messages s'affichent ici. Utilusez les symboles suivants pour appliquer un style \303\240 vos textes :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextUsConnection: public Ui_TextUsConnection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTUSCONNECTION_H
