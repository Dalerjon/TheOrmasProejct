/****************************************************************************
** Meta object code from reading C++ file 'CreateOthStDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateOthStDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateOthStDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateOthStDlg_t {
    QByteArrayData data[11];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateOthStDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateOthStDlg_t qt_meta_stringdata_CreateOthStDlg = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CreateOthStDlg"
QT_MOC_LITERAL(1, 15, 17), // "CreateOtherStocks"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 15), // "EditOtherStocks"
QT_MOC_LITERAL(4, 50, 17), // "DeleteOtherStocks"
QT_MOC_LITERAL(5, 68, 5), // "Close"
QT_MOC_LITERAL(6, 74, 10), // "OpenCmpDlg"
QT_MOC_LITERAL(7, 85, 15), // "TextEditChanged"
QT_MOC_LITERAL(8, 101, 5), // "SetID"
QT_MOC_LITERAL(9, 107, 2), // "ID"
QT_MOC_LITERAL(10, 110, 9) // "childName"

    },
    "CreateOthStDlg\0CreateOtherStocks\0\0"
    "EditOtherStocks\0DeleteOtherStocks\0"
    "Close\0OpenCmpDlg\0TextEditChanged\0SetID\0"
    "ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateOthStDlg[] = {

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

void CreateOthStDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateOthStDlg *_t = static_cast<CreateOthStDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CreateOtherStocks(); break;
        case 1: _t->EditOtherStocks(); break;
        case 2: _t->DeleteOtherStocks(); break;
        case 3: _t->Close(); break;
        case 4: _t->OpenCmpDlg(); break;
        case 5: _t->TextEditChanged(); break;
        case 6: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject CreateOthStDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateOthStDlg.data,
      qt_meta_data_CreateOthStDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateOthStDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateOthStDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateOthStDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateOthStDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateOtherStocks"))
        return static_cast< Ui::CreateOtherStocks*>(const_cast< CreateOthStDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateOthStDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
