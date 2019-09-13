/****************************************************************************
** Meta object code from reading C++ file 'GenerateWTBSDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GenerateWTBSDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GenerateWTBSDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GenerateWTBS_t {
    QByteArrayData data[7];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GenerateWTBS_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GenerateWTBS_t qt_meta_stringdata_GenerateWTBS = {
    {
QT_MOC_LITERAL(0, 0, 12), // "GenerateWTBS"
QT_MOC_LITERAL(1, 13, 8), // "Generate"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "Close"
QT_MOC_LITERAL(4, 29, 12), // "InitComboBox"
QT_MOC_LITERAL(5, 42, 15), // "GetPrevMonthEnd"
QT_MOC_LITERAL(6, 58, 11) // "std::string"

    },
    "GenerateWTBS\0Generate\0\0Close\0InitComboBox\0"
    "GetPrevMonthEnd\0std::string"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GenerateWTBS[] = {

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
       5,    1,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 6, 0x80000000 | 6,    2,

       0        // eod
};

void GenerateWTBS::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GenerateWTBS *_t = static_cast<GenerateWTBS *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Generate(); break;
        case 1: _t->Close(); break;
        case 2: _t->InitComboBox(); break;
        case 3: { std::string _r = _t->GetPrevMonthEnd((*reinterpret_cast< std::string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject GenerateWTBS::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GenerateWTBS.data,
      qt_meta_data_GenerateWTBS,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GenerateWTBS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GenerateWTBS::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GenerateWTBS.stringdata0))
        return static_cast<void*>(const_cast< GenerateWTBS*>(this));
    if (!strcmp(_clname, "Ui::GenerateWarehouseTurnover"))
        return static_cast< Ui::GenerateWarehouseTurnover*>(const_cast< GenerateWTBS*>(this));
    return QDialog::qt_metacast(_clname);
}

int GenerateWTBS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
