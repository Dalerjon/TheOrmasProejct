/****************************************************************************
** Meta object code from reading C++ file 'CreateCurDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateCurDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateCurDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateCurDlg_t {
    QByteArrayData data[6];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateCurDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateCurDlg_t qt_meta_stringdata_CreateCurDlg = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CreateCurDlg"
QT_MOC_LITERAL(1, 13, 14), // "CreateCurrency"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12), // "EditCurrency"
QT_MOC_LITERAL(4, 42, 14), // "DeleteCurrency"
QT_MOC_LITERAL(5, 57, 5) // "Close"

    },
    "CreateCurDlg\0CreateCurrency\0\0EditCurrency\0"
    "DeleteCurrency\0Close"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateCurDlg[] = {

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

void CreateCurDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateCurDlg *_t = static_cast<CreateCurDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CreateCurrency(); break;
        case 1: _t->EditCurrency(); break;
        case 2: _t->DeleteCurrency(); break;
        case 3: _t->Close(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CreateCurDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateCurDlg.data,
      qt_meta_data_CreateCurDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateCurDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateCurDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateCurDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateCurDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateCurrency"))
        return static_cast< Ui::CreateCurrency*>(const_cast< CreateCurDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateCurDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
