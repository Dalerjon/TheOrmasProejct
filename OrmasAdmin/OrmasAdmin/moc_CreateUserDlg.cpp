/****************************************************************************
** Meta object code from reading C++ file 'CreateUserDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateUserDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateUserDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateUserDlg_t {
    QByteArrayData data[11];
    char stringdata[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateUserDlg_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateUserDlg_t qt_meta_stringdata_CreateUserDlg = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CreateUserDlg"
QT_MOC_LITERAL(1, 14, 10), // "CreateUser"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "EditUser"
QT_MOC_LITERAL(4, 35, 10), // "DeleteUser"
QT_MOC_LITERAL(5, 46, 5), // "Close"
QT_MOC_LITERAL(6, 52, 10), // "OpenLcnDlg"
QT_MOC_LITERAL(7, 63, 11), // "OpenRoleDlg"
QT_MOC_LITERAL(8, 75, 5), // "SetID"
QT_MOC_LITERAL(9, 81, 2), // "ID"
QT_MOC_LITERAL(10, 84, 9) // "childName"

    },
    "CreateUserDlg\0CreateUser\0\0EditUser\0"
    "DeleteUser\0Close\0OpenLcnDlg\0OpenRoleDlg\0"
    "SetID\0ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateUserDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    2,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    9,   10,

       0        // eod
};

void CreateUserDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateUserDlg *_t = static_cast<CreateUserDlg *>(_o);
        switch (_id) {
        case 0: _t->CreateUser(); break;
        case 1: _t->EditUser(); break;
        case 2: _t->DeleteUser(); break;
        case 3: _t->Close(); break;
        case 4: _t->OpenLcnDlg(); break;
        case 5: _t->OpenRoleDlg(); break;
        case 6: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject CreateUserDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateUserDlg.data,
      qt_meta_data_CreateUserDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateUserDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateUserDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateUserDlg.stringdata))
        return static_cast<void*>(const_cast< CreateUserDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateUser"))
        return static_cast< Ui::CreateUser*>(const_cast< CreateUserDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateUserDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
