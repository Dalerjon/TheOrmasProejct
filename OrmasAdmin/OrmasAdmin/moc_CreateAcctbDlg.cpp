/****************************************************************************
** Meta object code from reading C++ file 'CreateAcctbDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateAcctbDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateAcctbDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateAcctbDlg_t {
    QByteArrayData data[10];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateAcctbDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateAcctbDlg_t qt_meta_stringdata_CreateAcctbDlg = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CreateAcctbDlg"
QT_MOC_LITERAL(1, 15, 17), // "CreateAccountable"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 15), // "EditAccountable"
QT_MOC_LITERAL(4, 50, 17), // "DeleteAccountable"
QT_MOC_LITERAL(5, 68, 5), // "Close"
QT_MOC_LITERAL(6, 74, 10), // "OpenEmpDlg"
QT_MOC_LITERAL(7, 85, 5), // "SetID"
QT_MOC_LITERAL(8, 91, 2), // "ID"
QT_MOC_LITERAL(9, 94, 9) // "childName"

    },
    "CreateAcctbDlg\0CreateAccountable\0\0"
    "EditAccountable\0DeleteAccountable\0"
    "Close\0OpenEmpDlg\0SetID\0ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateAcctbDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    2,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    8,    9,

       0        // eod
};

void CreateAcctbDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateAcctbDlg *_t = static_cast<CreateAcctbDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CreateAccountable(); break;
        case 1: _t->EditAccountable(); break;
        case 2: _t->DeleteAccountable(); break;
        case 3: _t->Close(); break;
        case 4: _t->OpenEmpDlg(); break;
        case 5: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject CreateAcctbDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateAcctbDlg.data,
      qt_meta_data_CreateAcctbDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateAcctbDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateAcctbDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateAcctbDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateAcctbDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateAccountable"))
        return static_cast< Ui::CreateAccountable*>(const_cast< CreateAcctbDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateAcctbDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
