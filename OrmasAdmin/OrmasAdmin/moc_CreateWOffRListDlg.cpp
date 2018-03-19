/****************************************************************************
** Meta object code from reading C++ file 'CreateWOffRListDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateWOffRListDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateWOffRListDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateWOffRListDlg_t {
    QByteArrayData data[12];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateWOffRListDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateWOffRListDlg_t qt_meta_stringdata_CreateWOffRListDlg = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CreateWOffRListDlg"
QT_MOC_LITERAL(1, 19, 16), // "AddProductToList"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 17), // "EditProductInList"
QT_MOC_LITERAL(4, 55, 13), // "DeleteProduct"
QT_MOC_LITERAL(5, 69, 5), // "Close"
QT_MOC_LITERAL(6, 75, 12), // "OpenWOffRDlg"
QT_MOC_LITERAL(7, 88, 11), // "OpenProdDlg"
QT_MOC_LITERAL(8, 100, 10), // "OpenStsDlg"
QT_MOC_LITERAL(9, 111, 5), // "SetID"
QT_MOC_LITERAL(10, 117, 2), // "ID"
QT_MOC_LITERAL(11, 120, 9) // "childName"

    },
    "CreateWOffRListDlg\0AddProductToList\0"
    "\0EditProductInList\0DeleteProduct\0Close\0"
    "OpenWOffRDlg\0OpenProdDlg\0OpenStsDlg\0"
    "SetID\0ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateWOffRListDlg[] = {

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

void CreateWOffRListDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateWOffRListDlg *_t = static_cast<CreateWOffRListDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AddProductToList(); break;
        case 1: _t->EditProductInList(); break;
        case 2: _t->DeleteProduct(); break;
        case 3: _t->Close(); break;
        case 4: _t->OpenWOffRDlg(); break;
        case 5: _t->OpenProdDlg(); break;
        case 6: _t->OpenStsDlg(); break;
        case 7: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject CreateWOffRListDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateWOffRListDlg.data,
      qt_meta_data_CreateWOffRListDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateWOffRListDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateWOffRListDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateWOffRListDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateWOffRListDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateWOffRList"))
        return static_cast< Ui::CreateWOffRList*>(const_cast< CreateWOffRListDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateWOffRListDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
