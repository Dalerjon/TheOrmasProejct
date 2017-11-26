/****************************************************************************
** Meta object code from reading C++ file 'ClcWagesDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ClcWagesDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClcWagesDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ClcWagesDlg_t {
    QByteArrayData data[9];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClcWagesDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClcWagesDlg_t qt_meta_stringdata_ClcWagesDlg = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ClcWagesDlg"
QT_MOC_LITERAL(1, 12, 9), // "Calculate"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "Close"
QT_MOC_LITERAL(4, 29, 11), // "ChangeState"
QT_MOC_LITERAL(5, 41, 10), // "OpenEmpDlg"
QT_MOC_LITERAL(6, 52, 5), // "SetID"
QT_MOC_LITERAL(7, 58, 2), // "ID"
QT_MOC_LITERAL(8, 61, 9) // "childName"

    },
    "ClcWagesDlg\0Calculate\0\0Close\0ChangeState\0"
    "OpenEmpDlg\0SetID\0ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClcWagesDlg[] = {

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
       6,    2,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    7,    8,

       0        // eod
};

void ClcWagesDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClcWagesDlg *_t = static_cast<ClcWagesDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Calculate(); break;
        case 1: _t->Close(); break;
        case 2: _t->ChangeState(); break;
        case 3: _t->OpenEmpDlg(); break;
        case 4: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject ClcWagesDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ClcWagesDlg.data,
      qt_meta_data_ClcWagesDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ClcWagesDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClcWagesDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ClcWagesDlg.stringdata0))
        return static_cast<void*>(const_cast< ClcWagesDlg*>(this));
    if (!strcmp(_clname, "Ui::CalculateWages"))
        return static_cast< Ui::CalculateWages*>(const_cast< ClcWagesDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int ClcWagesDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
