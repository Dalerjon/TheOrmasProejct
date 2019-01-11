/****************************************************************************
** Meta object code from reading C++ file 'CashInfoDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CashInfoDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CashInfoDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CashInfoDlg_t {
    QByteArrayData data[3];
    char stringdata0[19];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CashInfoDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CashInfoDlg_t qt_meta_stringdata_CashInfoDlg = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CashInfoDlg"
QT_MOC_LITERAL(1, 12, 5), // "Close"
QT_MOC_LITERAL(2, 18, 0) // ""

    },
    "CashInfoDlg\0Close\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CashInfoDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void CashInfoDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CashInfoDlg *_t = static_cast<CashInfoDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Close(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CashInfoDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CashInfoDlg.data,
      qt_meta_data_CashInfoDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CashInfoDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CashInfoDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CashInfoDlg.stringdata0))
        return static_cast<void*>(const_cast< CashInfoDlg*>(this));
    if (!strcmp(_clname, "Ui::CashInfo"))
        return static_cast< Ui::CashInfo*>(const_cast< CashInfoDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CashInfoDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
