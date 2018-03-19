/****************************************************************************
** Meta object code from reading C++ file 'CreateRcpPDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateRcpPDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateRcpPDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateRcpPDlg_t {
    QByteArrayData data[15];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateRcpPDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateRcpPDlg_t qt_meta_stringdata_CreateRcpPDlg = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CreateRcpPDlg"
QT_MOC_LITERAL(1, 14, 17), // "CloseCreatedForms"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 20), // "CreateReceiptProduct"
QT_MOC_LITERAL(4, 54, 18), // "EditReceiptProduct"
QT_MOC_LITERAL(5, 73, 20), // "DeleteReceiptProduct"
QT_MOC_LITERAL(6, 94, 5), // "Close"
QT_MOC_LITERAL(7, 100, 10), // "OpenEmpDlg"
QT_MOC_LITERAL(8, 111, 12), // "OpenSkEmpDlg"
QT_MOC_LITERAL(9, 124, 10), // "OpenStsDlg"
QT_MOC_LITERAL(10, 135, 15), // "OpenRcpPListDlg"
QT_MOC_LITERAL(11, 151, 16), // "StatusWasChenged"
QT_MOC_LITERAL(12, 168, 5), // "SetID"
QT_MOC_LITERAL(13, 174, 2), // "ID"
QT_MOC_LITERAL(14, 177, 9) // "childName"

    },
    "CreateRcpPDlg\0CloseCreatedForms\0\0"
    "CreateReceiptProduct\0EditReceiptProduct\0"
    "DeleteReceiptProduct\0Close\0OpenEmpDlg\0"
    "OpenSkEmpDlg\0OpenStsDlg\0OpenRcpPListDlg\0"
    "StatusWasChenged\0SetID\0ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateRcpPDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    2,   79,    2, 0x0a /* Public */,

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
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   13,   14,

       0        // eod
};

void CreateRcpPDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateRcpPDlg *_t = static_cast<CreateRcpPDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CloseCreatedForms(); break;
        case 1: _t->CreateReceiptProduct(); break;
        case 2: _t->EditReceiptProduct(); break;
        case 3: _t->DeleteReceiptProduct(); break;
        case 4: _t->Close(); break;
        case 5: _t->OpenEmpDlg(); break;
        case 6: _t->OpenSkEmpDlg(); break;
        case 7: _t->OpenStsDlg(); break;
        case 8: _t->OpenRcpPListDlg(); break;
        case 9: _t->StatusWasChenged(); break;
        case 10: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CreateRcpPDlg::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CreateRcpPDlg::CloseCreatedForms)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CreateRcpPDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateRcpPDlg.data,
      qt_meta_data_CreateRcpPDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateRcpPDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateRcpPDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateRcpPDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateRcpPDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateReceiptProduct"))
        return static_cast< Ui::CreateReceiptProduct*>(const_cast< CreateRcpPDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateRcpPDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void CreateRcpPDlg::CloseCreatedForms()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
