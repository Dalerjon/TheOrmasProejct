/****************************************************************************
** Meta object code from reading C++ file 'CreateRfdDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateRfdDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateRfdDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateRfdDlg_t {
    QByteArrayData data[11];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateRfdDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateRfdDlg_t qt_meta_stringdata_CreateRfdDlg = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CreateRfdDlg"
QT_MOC_LITERAL(1, 13, 12), // "CreateRefund"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "EditRefund"
QT_MOC_LITERAL(4, 38, 12), // "DeleteRefund"
QT_MOC_LITERAL(5, 51, 5), // "Close"
QT_MOC_LITERAL(6, 57, 11), // "OpenUserDlg"
QT_MOC_LITERAL(7, 69, 10), // "OpenCurDlg"
QT_MOC_LITERAL(8, 80, 5), // "SetID"
QT_MOC_LITERAL(9, 86, 2), // "ID"
QT_MOC_LITERAL(10, 89, 9) // "childName"

    },
    "CreateRfdDlg\0CreateRefund\0\0EditRefund\0"
    "DeleteRefund\0Close\0OpenUserDlg\0"
    "OpenCurDlg\0SetID\0ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateRfdDlg[] = {

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

void CreateRfdDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateRfdDlg *_t = static_cast<CreateRfdDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CreateRefund(); break;
        case 1: _t->EditRefund(); break;
        case 2: _t->DeleteRefund(); break;
        case 3: _t->Close(); break;
        case 4: _t->OpenUserDlg(); break;
        case 5: _t->OpenCurDlg(); break;
        case 6: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject CreateRfdDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateRfdDlg.data,
      qt_meta_data_CreateRfdDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateRfdDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateRfdDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateRfdDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateRfdDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateRefund"))
        return static_cast< Ui::CreateRefund*>(const_cast< CreateRfdDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateRfdDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
