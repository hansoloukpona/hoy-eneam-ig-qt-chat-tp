/****************************************************************************
** Meta object code from reading C++ file 'textusconnection.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ProjetClient/textusconnection.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'textusconnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TextUsConnection_t {
    const uint offsetsAndSize[36];
    char stringdata0[325];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TextUsConnection_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TextUsConnection_t qt_meta_stringdata_TextUsConnection = {
    {
QT_MOC_LITERAL(0, 16), // "TextUsConnection"
QT_MOC_LITERAL(17, 13), // "donneesRecues"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 26), // "on_connexionButton_clicked"
QT_MOC_LITERAL(59, 8), // "connecte"
QT_MOC_LITERAL(68, 10), // "deconnecte"
QT_MOC_LITERAL(79, 21), // "on_sendButton_clicked"
QT_MOC_LITERAL(101, 33), // "on_messageWriteZone_returnPre..."
QT_MOC_LITERAL(135, 23), // "on_goBackButton_clicked"
QT_MOC_LITERAL(159, 18), // "afficherDiscussion"
QT_MOC_LITERAL(178, 27), // "on_homeReturnButton_clicked"
QT_MOC_LITERAL(206, 12), // "erreurSocket"
QT_MOC_LITERAL(219, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(248, 6), // "erreur"
QT_MOC_LITERAL(255, 21), // "readBroadcastDatagram"
QT_MOC_LITERAL(277, 29), // "on_userListView_doubleClicked"
QT_MOC_LITERAL(307, 11), // "QModelIndex"
QT_MOC_LITERAL(319, 5) // "index"

    },
    "TextUsConnection\0donneesRecues\0\0"
    "on_connexionButton_clicked\0connecte\0"
    "deconnecte\0on_sendButton_clicked\0"
    "on_messageWriteZone_returnPressed\0"
    "on_goBackButton_clicked\0afficherDiscussion\0"
    "on_homeReturnButton_clicked\0erreurSocket\0"
    "QAbstractSocket::SocketError\0erreur\0"
    "readBroadcastDatagram\0"
    "on_userListView_doubleClicked\0QModelIndex\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TextUsConnection[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x08,    0 /* Private */,
       3,    0,   87,    2, 0x08,    1 /* Private */,
       4,    0,   88,    2, 0x08,    2 /* Private */,
       5,    0,   89,    2, 0x08,    3 /* Private */,
       6,    0,   90,    2, 0x08,    4 /* Private */,
       7,    0,   91,    2, 0x08,    5 /* Private */,
       8,    0,   92,    2, 0x08,    6 /* Private */,
       9,    0,   93,    2, 0x08,    7 /* Private */,
      10,    0,   94,    2, 0x08,    8 /* Private */,
      11,    1,   95,    2, 0x08,    9 /* Private */,
      14,    0,   98,    2, 0x08,   11 /* Private */,
      15,    1,   99,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,

       0        // eod
};

void TextUsConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TextUsConnection *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->donneesRecues(); break;
        case 1: _t->on_connexionButton_clicked(); break;
        case 2: _t->connecte(); break;
        case 3: _t->deconnecte(); break;
        case 4: _t->on_sendButton_clicked(); break;
        case 5: _t->on_messageWriteZone_returnPressed(); break;
        case 6: _t->on_goBackButton_clicked(); break;
        case 7: _t->afficherDiscussion(); break;
        case 8: _t->on_homeReturnButton_clicked(); break;
        case 9: _t->erreurSocket((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 10: _t->readBroadcastDatagram(); break;
        case 11: _t->on_userListView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject TextUsConnection::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_TextUsConnection.offsetsAndSize,
    qt_meta_data_TextUsConnection,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TextUsConnection_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>


>,
    nullptr
} };


const QMetaObject *TextUsConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextUsConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TextUsConnection.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TextUsConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
