/****************************************************************************
** Meta object code from reading C++ file 'CreateStsDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateStsDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateStsDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateStsDlg_t {
    QByteArrayData data[7];
    char stringdata[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateStsDlg_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateStsDlg_t qt_meta_stringdata_CreateStsDlg = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CreateStsDlg"
QT_MOC_LITERAL(1, 13, 12), // "CreateStatus"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "EditStatus"
QT_MOC_LITERAL(4, 38, 12), // "DeleteStatus"
QT_MOC_LITERAL(5, 51, 5), // "Close"
QT_MOC_LITERAL(6, 57, 15) // "TextEditChanged"

    },
    "CreateStsDlg\0CreateStatus\0\0EditStatus\0"
    "DeleteStatus\0Close\0TextEditChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateStsDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CreateStsDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateStsDlg *_t = static_cast<CreateStsDlg *>(_o);
        switch (_id) {
        case 0: _t->CreateStatus(); break;
        case 1: _t->EditStatus(); break;
        case 2: _t->DeleteStatus(); break;
        case 3: _t->Close(); break;
        case 4: _t->TextEditChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CreateStsDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateStsDlg.data,
      qt_meta_data_CreateStsDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateStsDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateStsDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateStsDlg.stringdata))
        return static_cast<void*>(const_cast< CreateStsDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateStatus"))
        return static_cast< Ui::CreateStatus*>(const_cast< CreateStsDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateStsDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
