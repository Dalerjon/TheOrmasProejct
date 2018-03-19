/****************************************************************************
** Meta object code from reading C++ file 'CreateCOADlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateCOADlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateCOADlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateCOADlg_t {
    QByteArrayData data[10];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateCOADlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateCOADlg_t qt_meta_stringdata_CreateCOADlg = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CreateCOADlg"
QT_MOC_LITERAL(1, 13, 21), // "CreateChartOfAccounts"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 19), // "EditChartOfAccounts"
QT_MOC_LITERAL(4, 56, 21), // "DeleteChartOfAccounts"
QT_MOC_LITERAL(5, 78, 5), // "Close"
QT_MOC_LITERAL(6, 84, 12), // "OpenAccTpDlg"
QT_MOC_LITERAL(7, 97, 5), // "SetID"
QT_MOC_LITERAL(8, 103, 2), // "ID"
QT_MOC_LITERAL(9, 106, 9) // "childName"

    },
    "CreateCOADlg\0CreateChartOfAccounts\0\0"
    "EditChartOfAccounts\0DeleteChartOfAccounts\0"
    "Close\0OpenAccTpDlg\0SetID\0ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateCOADlg[] = {

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

void CreateCOADlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateCOADlg *_t = static_cast<CreateCOADlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CreateChartOfAccounts(); break;
        case 1: _t->EditChartOfAccounts(); break;
        case 2: _t->DeleteChartOfAccounts(); break;
        case 3: _t->Close(); break;
        case 4: _t->OpenAccTpDlg(); break;
        case 5: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject CreateCOADlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateCOADlg.data,
      qt_meta_data_CreateCOADlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateCOADlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateCOADlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateCOADlg.stringdata0))
        return static_cast<void*>(const_cast< CreateCOADlg*>(this));
    if (!strcmp(_clname, "Ui::CreateChartOfAccounts"))
        return static_cast< Ui::CreateChartOfAccounts*>(const_cast< CreateCOADlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateCOADlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
