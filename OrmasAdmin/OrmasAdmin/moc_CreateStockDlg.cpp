/****************************************************************************
** Meta object code from reading C++ file 'CreateStockDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateStockDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateStockDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateStockDlg_t {
    QByteArrayData data[12];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateStockDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateStockDlg_t qt_meta_stringdata_CreateStockDlg = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CreateStockDlg"
QT_MOC_LITERAL(1, 15, 10), // "AddProduct"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "EditProduct"
QT_MOC_LITERAL(4, 39, 13), // "DeleteProduct"
QT_MOC_LITERAL(5, 53, 5), // "Close"
QT_MOC_LITERAL(6, 59, 11), // "OpenProdDlg"
QT_MOC_LITERAL(7, 71, 10), // "OpenStsDlg"
QT_MOC_LITERAL(8, 82, 10), // "OpenCurDlg"
QT_MOC_LITERAL(9, 93, 5), // "SetID"
QT_MOC_LITERAL(10, 99, 2), // "ID"
QT_MOC_LITERAL(11, 102, 9) // "childName"

    },
    "CreateStockDlg\0AddProduct\0\0EditProduct\0"
    "DeleteProduct\0Close\0OpenProdDlg\0"
    "OpenStsDlg\0OpenCurDlg\0SetID\0ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateStockDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    2,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   10,   11,

       0        // eod
};

void CreateStockDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateStockDlg *_t = static_cast<CreateStockDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AddProduct(); break;
        case 1: _t->EditProduct(); break;
        case 2: _t->DeleteProduct(); break;
        case 3: _t->Close(); break;
        case 4: _t->OpenProdDlg(); break;
        case 5: _t->OpenStsDlg(); break;
        case 6: _t->OpenCurDlg(); break;
        case 7: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject CreateStockDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateStockDlg.data,
      qt_meta_data_CreateStockDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateStockDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateStockDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateStockDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateStockDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateStock"))
        return static_cast< Ui::CreateStock*>(const_cast< CreateStockDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateStockDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
