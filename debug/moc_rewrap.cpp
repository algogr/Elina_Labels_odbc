/****************************************************************************
** Meta object code from reading C++ file 'rewrap.h'
**
** Created: Wed Aug 22 13:22:57 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../rewrap.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rewrap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rewrap[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
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
     113,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rewrap[] = {
    "rewrap\0\0scanned_old()\0scanned_new1()\0"
    "scanned_new2()\0scanned_new3()\0"
    "scanned_new4()\0scanned_new5()\0"
    "insertClicked()\0cancelClicked()\0"
};

const QMetaObject rewrap::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_rewrap,
      qt_meta_data_rewrap, 0 }
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
        switch (_id) {
        case 0: scanned_old(); break;
        case 1: scanned_new1(); break;
        case 2: scanned_new2(); break;
        case 3: scanned_new3(); break;
        case 4: scanned_new4(); break;
        case 5: scanned_new5(); break;
        case 6: insertClicked(); break;
        case 7: cancelClicked(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
