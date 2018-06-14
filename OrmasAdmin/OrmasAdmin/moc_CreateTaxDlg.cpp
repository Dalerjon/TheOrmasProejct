/****************************************************************************
** Meta object code from reading C++ file 'CreateTaxDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateTaxDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateTaxDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateTaxDlg_t {
    QByteArrayData data[6];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateTaxDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateTaxDlg_t qt_meta_stringdata_CreateTaxDlg = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CreateTaxDlg"
QT_MOC_LITERAL(1, 13, 9), // "CreateTax"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "EditTax"
QT_MOC_LITERAL(4, 32, 9), // "DeleteTax"
QT_MOC_LITERAL(5, 42, 5) // "Close"

    },
    "CreateTaxDlg\0CreateTax\0\0EditTax\0"
    "DeleteTax\0Close"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateTaxDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CreateTaxDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateTaxDlg *_t = static_cast<CreateTaxDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CreateTax(); break;
        case 1: _t->EditTax(); break;
        case 2: _t->DeleteTax(); break;
        case 3: _t->Close(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CreateTaxDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateTaxDlg.data,
      qt_meta_data_CreateTaxDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateTaxDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateTaxDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateTaxDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateTaxDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateTax"))
        return static_cast< Ui::CreateTax*>(const_cast< CreateTaxDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateTaxDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
