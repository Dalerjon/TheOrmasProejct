/****************************************************************************
** Meta object code from reading C++ file 'CreateSAccDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateSAccDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateSAccDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateSAccDlg_t {
    QByteArrayData data[12];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateSAccDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateSAccDlg_t qt_meta_stringdata_CreateSAccDlg = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CreateSAccDlg"
QT_MOC_LITERAL(1, 14, 16), // "CreateSubaccount"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 14), // "EditSubaccount"
QT_MOC_LITERAL(4, 47, 16), // "DeleteSubaccount"
QT_MOC_LITERAL(5, 64, 5), // "Close"
QT_MOC_LITERAL(6, 70, 10), // "OpenStsDlg"
QT_MOC_LITERAL(7, 81, 15), // "TextEditChanged"
QT_MOC_LITERAL(8, 97, 10), // "OpenCOADlg"
QT_MOC_LITERAL(9, 108, 5), // "SetID"
QT_MOC_LITERAL(10, 114, 2), // "ID"
QT_MOC_LITERAL(11, 117, 9) // "childName"

    },
    "CreateSAccDlg\0CreateSubaccount\0\0"
    "EditSubaccount\0DeleteSubaccount\0Close\0"
    "OpenStsDlg\0TextEditChanged\0OpenCOADlg\0"
    "SetID\0ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateSAccDlg[] = {

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

void CreateSAccDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateSAccDlg *_t = static_cast<CreateSAccDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CreateSubaccount(); break;
        case 1: _t->EditSubaccount(); break;
        case 2: _t->DeleteSubaccount(); break;
        case 3: _t->Close(); break;
        case 4: _t->OpenStsDlg(); break;
        case 5: _t->TextEditChanged(); break;
        case 6: _t->OpenCOADlg(); break;
        case 7: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject CreateSAccDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateSAccDlg.data,
      qt_meta_data_CreateSAccDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateSAccDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateSAccDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateSAccDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateSAccDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateSubaccount"))
        return static_cast< Ui::CreateSubaccount*>(const_cast< CreateSAccDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateSAccDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
