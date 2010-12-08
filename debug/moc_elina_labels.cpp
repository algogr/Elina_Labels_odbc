/****************************************************************************
** Meta object code from reading C++ file 'elina_labels.h'
**
** Created: Tue Dec 7 09:39:04 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../elina_labels.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'elina_labels.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Elina_Labels[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      31,   13,   13,   13, 0x0a,
      54,   42,   13,   13, 0x08,
      97,   13,   13,   13, 0x08,
     110,   13,   13,   13, 0x08,
     134,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Elina_Labels[] = {
    "Elina_Labels\0\0requestNewData()\0"
    "readData()\0socketError\0"
    "displayError(QAbstractSocket::SocketError)\0"
    "onTypeChar()\0rowClicked(QModelIndex)\0"
    "next1Clicked()\0"
};

const QMetaObject Elina_Labels::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Elina_Labels,
      qt_meta_data_Elina_Labels, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Elina_Labels::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Elina_Labels::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Elina_Labels::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Elina_Labels))
        return static_cast<void*>(const_cast< Elina_Labels*>(this));
    return QDialog::qt_metacast(_clname);
}

int Elina_Labels::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: requestNewData(); break;
        case 1: readData(); break;
        case 2: displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 3: onTypeChar(); break;
        case 4: rowClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: next1Clicked(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
