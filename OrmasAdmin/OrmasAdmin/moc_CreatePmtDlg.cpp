/****************************************************************************
** Meta object code from reading C++ file 'CreatePmtDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreatePmtDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreatePmtDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreatePmtDlg_t {
    QByteArrayData data[17];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreatePmtDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreatePmtDlg_t qt_meta_stringdata_CreatePmtDlg = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CreatePmtDlg"
QT_MOC_LITERAL(1, 13, 13), // "CreatePayment"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "EditPayment"
QT_MOC_LITERAL(4, 40, 13), // "DeletePayment"
QT_MOC_LITERAL(5, 54, 15), // "TextEditChanged"
QT_MOC_LITERAL(6, 70, 14), // "AccTextChanged"
QT_MOC_LITERAL(7, 85, 5), // "Close"
QT_MOC_LITERAL(8, 91, 11), // "OpenUserDlg"
QT_MOC_LITERAL(9, 103, 10), // "OpenAccDlg"
QT_MOC_LITERAL(10, 114, 13), // "OpenStatusDlg"
QT_MOC_LITERAL(11, 128, 16), // "AccountIsChenged"
QT_MOC_LITERAL(12, 145, 9), // "SortTable"
QT_MOC_LITERAL(13, 155, 11), // "QTableView*"
QT_MOC_LITERAL(14, 167, 5), // "SetID"
QT_MOC_LITERAL(15, 173, 2), // "ID"
QT_MOC_LITERAL(16, 176, 9) // "childName"

    },
    "CreatePmtDlg\0CreatePayment\0\0EditPayment\0"
    "DeletePayment\0TextEditChanged\0"
    "AccTextChanged\0Close\0OpenUserDlg\0"
    "OpenAccDlg\0OpenStatusDlg\0AccountIsChenged\0"
    "SortTable\0QTableView*\0SetID\0ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreatePmtDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    1,   84,    2, 0x08 /* Private */,
      14,    2,   87,    2, 0x0a /* Public */,

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
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   15,   16,

       0        // eod
};

void CreatePmtDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreatePmtDlg *_t = static_cast<CreatePmtDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CreatePayment(); break;
        case 1: _t->EditPayment(); break;
        case 2: _t->DeletePayment(); break;
        case 3: _t->TextEditChanged(); break;
        case 4: _t->AccTextChanged(); break;
        case 5: _t->Close(); break;
        case 6: _t->OpenUserDlg(); break;
        case 7: _t->OpenAccDlg(); break;
        case 8: _t->OpenStatusDlg(); break;
        case 9: _t->AccountIsChenged(); break;
        case 10: _t->SortTable((*reinterpret_cast< QTableView*(*)>(_a[1]))); break;
        case 11: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject CreatePmtDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreatePmtDlg.data,
      qt_meta_data_CreatePmtDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreatePmtDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreatePmtDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreatePmtDlg.stringdata0))
        return static_cast<void*>(const_cast< CreatePmtDlg*>(this));
    if (!strcmp(_clname, "Ui::CreatePayment"))
        return static_cast< Ui::CreatePayment*>(const_cast< CreatePmtDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreatePmtDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
