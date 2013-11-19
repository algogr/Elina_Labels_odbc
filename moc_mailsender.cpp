/****************************************************************************
** Meta object code from reading C++ file 'mailsender.h'
**
** Created: Thu Jun 27 12:47:08 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mailsender.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mailsender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MailSender[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   12,   11,   11, 0x08,
      88,   68,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MailSender[] = {
    "MailSender\0\0socketError\0"
    "errorReceived(QAbstractSocket::SocketError)\0"
    "proxy,authenticator\0"
    "proxyAuthentication(QNetworkProxy,QAuthenticator*)\0"
};

void MailSender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MailSender *_t = static_cast<MailSender *>(_o);
        switch (_id) {
        case 0: _t->errorReceived((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 1: _t->proxyAuthentication((*reinterpret_cast< const QNetworkProxy(*)>(_a[1])),(*reinterpret_cast< QAuthenticator*(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MailSender::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MailSender::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MailSender,
      qt_meta_data_MailSender, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MailSender::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MailSender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MailSender::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MailSender))
        return static_cast<void*>(const_cast< MailSender*>(this));
    return QObject::qt_metacast(_clname);
}

int MailSender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
