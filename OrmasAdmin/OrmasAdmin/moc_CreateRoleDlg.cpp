/****************************************************************************
** Meta object code from reading C++ file 'CreateRoleDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateRoleDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateRoleDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateRoleDlg_t {
    QByteArrayData data[7];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateRoleDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateRoleDlg_t qt_meta_stringdata_CreateRoleDlg = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CreateRoleDlg"
QT_MOC_LITERAL(1, 14, 10), // "CreateRole"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "EditRole"
QT_MOC_LITERAL(4, 35, 10), // "DeleteRole"
QT_MOC_LITERAL(5, 46, 5), // "Close"
QT_MOC_LITERAL(6, 52, 15) // "TextEditChanged"

    },
    "CreateRoleDlg\0CreateRole\0\0EditRole\0"
    "DeleteRole\0Close\0TextEditChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateRoleDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CreateRoleDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateRoleDlg *_t = static_cast<CreateRoleDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CreateRole(); break;
        case 1: _t->EditRole(); break;
        case 2: _t->DeleteRole(); break;
        case 3: _t->Close(); break;
        case 4: _t->TextEditChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CreateRoleDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateRoleDlg.data,
      qt_meta_data_CreateRoleDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateRoleDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateRoleDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateRoleDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateRoleDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateRole"))
        return static_cast< Ui::CreateRole*>(const_cast< CreateRoleDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateRoleDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
