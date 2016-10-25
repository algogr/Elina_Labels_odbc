/****************************************************************************
** Meta object code from reading C++ file 'elina_labels.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "elina_labels.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'elina_labels.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Elina_Labels[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      27,   13,   13,   13, 0x08,
      51,   13,   13,   13, 0x08,
      66,   13,   13,   13, 0x08,
      82,   13,   13,   13, 0x08,
      98,   13,   13,   13, 0x08,
     114,   13,   13,   13, 0x08,
     141,   13,   13,   13, 0x08,
     151,   13,   13,   13, 0x08,
     170,   13,   13,   13, 0x08,
     186,   13,   13,   13, 0x08,
     201,   13,   13,   13, 0x08,
     219,   13,   13,   13, 0x08,
     231,   13,   13,   13, 0x08,
     245,   13,   13,   13, 0x08,
     260,   13,   13,   13, 0x08,
     275,   13,   13,   13, 0x08,
     306,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Elina_Labels[] = {
    "Elina_Labels\0\0onTypeChar()\0"
    "rowClicked(QModelIndex)\0next1Clicked()\0"
    "insertClicked()\0removeClicked()\0"
    "rewrapClicked()\0rowClickedSel(QModelIndex)\0"
    "Scanned()\0setSpinBoxFormat()\0"
    "clearLineEdit()\0copy_machine()\0"
    "copy_middledate()\0upClicked()\0"
    "downClicked()\0checkClicked()\0"
    "weight_check()\0rowClickedSelProd(QModelIndex)\0"
    "dummycheckpressed()\0"
};

void Elina_Labels::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Elina_Labels *_t = static_cast<Elina_Labels *>(_o);
        switch (_id) {
        case 0: _t->onTypeChar(); break;
        case 1: _t->rowClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->next1Clicked(); break;
        case 3: _t->insertClicked(); break;
        case 4: _t->removeClicked(); break;
        case 5: _t->rewrapClicked(); break;
        case 6: _t->rowClickedSel((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->Scanned(); break;
        case 8: _t->setSpinBoxFormat(); break;
        case 9: _t->clearLineEdit(); break;
        case 10: _t->copy_machine(); break;
        case 11: _t->copy_middledate(); break;
        case 12: _t->upClicked(); break;
        case 13: _t->downClicked(); break;
        case 14: _t->checkClicked(); break;
        case 15: _t->weight_check(); break;
        case 16: _t->rowClickedSelProd((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 17: _t->dummycheckpressed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Elina_Labels::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Elina_Labels::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Elina_Labels,
      qt_meta_data_Elina_Labels, &staticMetaObjectExtraData }
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
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
