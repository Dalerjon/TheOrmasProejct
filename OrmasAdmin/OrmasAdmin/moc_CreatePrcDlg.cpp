/****************************************************************************
** Meta object code from reading C++ file 'CreatePrcDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreatePrcDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreatePrcDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreatePrcDlg_t {
    QByteArrayData data[11];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreatePrcDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreatePrcDlg_t qt_meta_stringdata_CreatePrcDlg = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CreatePrcDlg"
QT_MOC_LITERAL(1, 13, 11), // "CreatePrice"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "EditPrice"
QT_MOC_LITERAL(4, 36, 11), // "DeletePrice"
QT_MOC_LITERAL(5, 48, 5), // "Close"
QT_MOC_LITERAL(6, 54, 10), // "OpenPrdDlg"
QT_MOC_LITERAL(7, 65, 10), // "OpenCurDlg"
QT_MOC_LITERAL(8, 76, 5), // "SetID"
QT_MOC_LITERAL(9, 82, 2), // "ID"
QT_MOC_LITERAL(10, 85, 9) // "childName"

    },
    "CreatePrcDlg\0CreatePrice\0\0EditPrice\0"
    "DeletePrice\0Close\0OpenPrdDlg\0OpenCurDlg\0"
    "SetID\0ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreatePrcDlg[] = {

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

void CreatePrcDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreatePrcDlg *_t = static_cast<CreatePrcDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CreatePrice(); break;
        case 1: _t->EditPrice(); break;
        case 2: _t->DeletePrice(); break;
        case 3: _t->Close(); break;
        case 4: _t->OpenPrdDlg(); break;
        case 5: _t->OpenCurDlg(); break;
        case 6: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject CreatePrcDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreatePrcDlg.data,
      qt_meta_data_CreatePrcDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreatePrcDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreatePrcDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreatePrcDlg.stringdata0))
        return static_cast<void*>(const_cast< CreatePrcDlg*>(this));
    if (!strcmp(_clname, "Ui::CreatePrice"))
        return static_cast< Ui::CreatePrice*>(const_cast< CreatePrcDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreatePrcDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
