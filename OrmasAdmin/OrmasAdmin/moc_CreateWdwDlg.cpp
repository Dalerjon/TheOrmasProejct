/****************************************************************************
** Meta object code from reading C++ file 'CreateWdwDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateWdwDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateWdwDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateWdwDlg_t {
    QByteArrayData data[17];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateWdwDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateWdwDlg_t qt_meta_stringdata_CreateWdwDlg = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CreateWdwDlg"
QT_MOC_LITERAL(1, 13, 16), // "CreateWithdrawal"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 14), // "EditWithdrawal"
QT_MOC_LITERAL(4, 46, 16), // "DeleteWithdrawal"
QT_MOC_LITERAL(5, 63, 5), // "Close"
QT_MOC_LITERAL(6, 69, 15), // "TextEditChanged"
QT_MOC_LITERAL(7, 85, 13), // "SATextChanged"
QT_MOC_LITERAL(8, 99, 13), // "UserIsChanged"
QT_MOC_LITERAL(9, 113, 11), // "OpenSAccDlg"
QT_MOC_LITERAL(10, 125, 11), // "OpenUserDlg"
QT_MOC_LITERAL(11, 137, 16), // "AccountIsChenged"
QT_MOC_LITERAL(12, 154, 9), // "SortTable"
QT_MOC_LITERAL(13, 164, 11), // "QTableView*"
QT_MOC_LITERAL(14, 176, 5), // "SetID"
QT_MOC_LITERAL(15, 182, 2), // "ID"
QT_MOC_LITERAL(16, 185, 9) // "childName"

    },
    "CreateWdwDlg\0CreateWithdrawal\0\0"
    "EditWithdrawal\0DeleteWithdrawal\0Close\0"
    "TextEditChanged\0SATextChanged\0"
    "UserIsChanged\0OpenSAccDlg\0OpenUserDlg\0"
    "AccountIsChenged\0SortTable\0QTableView*\0"
    "SetID\0ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateWdwDlg[] = {

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

void CreateWdwDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateWdwDlg *_t = static_cast<CreateWdwDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CreateWithdrawal(); break;
        case 1: _t->EditWithdrawal(); break;
        case 2: _t->DeleteWithdrawal(); break;
        case 3: _t->Close(); break;
        case 4: _t->TextEditChanged(); break;
        case 5: _t->SATextChanged(); break;
        case 6: _t->UserIsChanged(); break;
        case 7: _t->OpenSAccDlg(); break;
        case 8: _t->OpenUserDlg(); break;
        case 9: _t->AccountIsChenged(); break;
        case 10: _t->SortTable((*reinterpret_cast< QTableView*(*)>(_a[1]))); break;
        case 11: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject CreateWdwDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateWdwDlg.data,
      qt_meta_data_CreateWdwDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateWdwDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateWdwDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateWdwDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateWdwDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateWithdrawal"))
        return static_cast< Ui::CreateWithdrawal*>(const_cast< CreateWdwDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateWdwDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
