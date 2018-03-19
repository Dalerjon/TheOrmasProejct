/****************************************************************************
** Meta object code from reading C++ file 'CreatePurDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreatePurDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreatePurDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreatePurDlg_t {
    QByteArrayData data[11];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreatePurDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreatePurDlg_t qt_meta_stringdata_CreatePurDlg = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CreatePurDlg"
QT_MOC_LITERAL(1, 13, 14), // "CreatePurveyor"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12), // "EditPurveyor"
QT_MOC_LITERAL(4, 42, 14), // "DeletePurveyor"
QT_MOC_LITERAL(5, 57, 5), // "Close"
QT_MOC_LITERAL(6, 63, 10), // "OpenLcnDlg"
QT_MOC_LITERAL(7, 74, 11), // "OpenRoleDlg"
QT_MOC_LITERAL(8, 86, 5), // "SetID"
QT_MOC_LITERAL(9, 92, 2), // "ID"
QT_MOC_LITERAL(10, 95, 9) // "childName"

    },
    "CreatePurDlg\0CreatePurveyor\0\0EditPurveyor\0"
    "DeletePurveyor\0Close\0OpenLcnDlg\0"
    "OpenRoleDlg\0SetID\0ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreatePurDlg[] = {

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

void CreatePurDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreatePurDlg *_t = static_cast<CreatePurDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CreatePurveyor(); break;
        case 1: _t->EditPurveyor(); break;
        case 2: _t->DeletePurveyor(); break;
        case 3: _t->Close(); break;
        case 4: _t->OpenLcnDlg(); break;
        case 5: _t->OpenRoleDlg(); break;
        case 6: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject CreatePurDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreatePurDlg.data,
      qt_meta_data_CreatePurDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreatePurDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreatePurDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreatePurDlg.stringdata0))
        return static_cast<void*>(const_cast< CreatePurDlg*>(this));
    if (!strcmp(_clname, "Ui::CreatePurveyor"))
        return static_cast< Ui::CreatePurveyor*>(const_cast< CreatePurDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreatePurDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
