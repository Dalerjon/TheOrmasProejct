/****************************************************************************
** Meta object code from reading C++ file 'CreateStockTrDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateStockTrDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateStockTrDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateStockTrDlg_t {
    QByteArrayData data[16];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateStockTrDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateStockTrDlg_t qt_meta_stringdata_CreateStockTrDlg = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CreateStockTrDlg"
QT_MOC_LITERAL(1, 17, 17), // "CloseCreatedForms"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 19), // "CreateStockTransfer"
QT_MOC_LITERAL(4, 56, 17), // "EditStockTransfer"
QT_MOC_LITERAL(5, 74, 19), // "DeleteStockTransfer"
QT_MOC_LITERAL(6, 94, 5), // "Close"
QT_MOC_LITERAL(7, 100, 10), // "OpenEmpDlg"
QT_MOC_LITERAL(8, 111, 12), // "OpenSkEmpDlg"
QT_MOC_LITERAL(9, 124, 10), // "OpenStsDlg"
QT_MOC_LITERAL(10, 135, 18), // "OpenStockTrListDlg"
QT_MOC_LITERAL(11, 154, 16), // "StatusWasChenged"
QT_MOC_LITERAL(12, 171, 15), // "TextEditChanged"
QT_MOC_LITERAL(13, 187, 5), // "SetID"
QT_MOC_LITERAL(14, 193, 2), // "ID"
QT_MOC_LITERAL(15, 196, 9) // "childName"

    },
    "CreateStockTrDlg\0CloseCreatedForms\0\0"
    "CreateStockTransfer\0EditStockTransfer\0"
    "DeleteStockTransfer\0Close\0OpenEmpDlg\0"
    "OpenSkEmpDlg\0OpenStsDlg\0OpenStockTrListDlg\0"
    "StatusWasChenged\0TextEditChanged\0SetID\0"
    "ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateStockTrDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    2,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   14,   15,

       0        // eod
};

void CreateStockTrDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateStockTrDlg *_t = static_cast<CreateStockTrDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CloseCreatedForms(); break;
        case 1: _t->CreateStockTransfer(); break;
        case 2: _t->EditStockTransfer(); break;
        case 3: _t->DeleteStockTransfer(); break;
        case 4: _t->Close(); break;
        case 5: _t->OpenEmpDlg(); break;
        case 6: _t->OpenSkEmpDlg(); break;
        case 7: _t->OpenStsDlg(); break;
        case 8: _t->OpenStockTrListDlg(); break;
        case 9: _t->StatusWasChenged(); break;
        case 10: _t->TextEditChanged(); break;
        case 11: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CreateStockTrDlg::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CreateStockTrDlg::CloseCreatedForms)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CreateStockTrDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateStockTrDlg.data,
      qt_meta_data_CreateStockTrDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateStockTrDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateStockTrDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateStockTrDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateStockTrDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateStockTransfer"))
        return static_cast< Ui::CreateStockTransfer*>(const_cast< CreateStockTrDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateStockTrDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void CreateStockTrDlg::CloseCreatedForms()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
