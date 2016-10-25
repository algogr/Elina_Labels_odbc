/****************************************************************************
** Meta object code from reading C++ file 'rewrap.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "rewrap.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rewrap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rewrap[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      22,    7,    7,    7, 0x08,
      37,    7,    7,    7, 0x08,
      52,    7,    7,    7, 0x08,
      67,    7,    7,    7, 0x08,
      82,    7,    7,    7, 0x08,
      97,    7,    7,    7, 0x08,
     112,    7,    7,    7, 0x08,
     128,    7,    7,    7, 0x08,
     144,    7,    7,    7, 0x08,
     160,    7,    7,    7, 0x08,
     176,    7,    7,    7, 0x08,
     192,    7,    7,    7, 0x08,
     205,    7,    7,    7, 0x08,
     221,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rewrap[] = {
    "rewrap\0\0scanned_old()\0scanned_Aold()\0"
    "scanned_new1()\0scanned_new2()\0"
    "scanned_new3()\0scanned_new4()\0"
    "scanned_new5()\0scanned_Anew1()\0"
    "scanned_Anew2()\0scanned_Anew3()\0"
    "scanned_Anew4()\0scanned_Anew5()\0"
    "doubleread()\0insertClicked()\0"
    "cancelClicked()\0"
};

void rewrap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        rewrap *_t = static_cast<rewrap *>(_o);
        switch (_id) {
        case 0: _t->scanned_old(); break;
        case 1: _t->scanned_Aold(); break;
        case 2: _t->scanned_new1(); break;
        case 3: _t->scanned_new2(); break;
        case 4: _t->scanned_new3(); break;
        case 5: _t->scanned_new4(); break;
        case 6: _t->scanned_new5(); break;
        case 7: _t->scanned_Anew1(); break;
        case 8: _t->scanned_Anew2(); break;
        case 9: _t->scanned_Anew3(); break;
        case 10: _t->scanned_Anew4(); break;
        case 11: _t->scanned_Anew5(); break;
        case 12: _t->doubleread(); break;
        case 13: _t->insertClicked(); break;
        case 14: _t->cancelClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rewrap::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rewrap::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_rewrap,
      qt_meta_data_rewrap, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rewrap::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rewrap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rewrap::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rewrap))
        return static_cast<void*>(const_cast< rewrap*>(this));
    return QDialog::qt_metacast(_clname);
}

int rewrap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
