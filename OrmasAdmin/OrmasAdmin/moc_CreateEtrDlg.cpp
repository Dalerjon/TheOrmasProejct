/****************************************************************************
** Meta object code from reading C++ file 'CreateEtrDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateEtrDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateEtrDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateEtrDlg_t {
    QByteArrayData data[16];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateEtrDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateEtrDlg_t qt_meta_stringdata_CreateEtrDlg = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CreateEtrDlg"
QT_MOC_LITERAL(1, 13, 11), // "CreateEntry"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "EditEntry"
QT_MOC_LITERAL(4, 36, 11), // "DeleteEntry"
QT_MOC_LITERAL(5, 48, 5), // "Close"
QT_MOC_LITERAL(6, 54, 11), // "OpenDAccDlg"
QT_MOC_LITERAL(7, 66, 11), // "OpenCAccDlg"
QT_MOC_LITERAL(8, 78, 12), // "OpenDSAccDlg"
QT_MOC_LITERAL(9, 91, 12), // "OpenCSAccDlg"
QT_MOC_LITERAL(10, 104, 13), // "DATextChanged"
QT_MOC_LITERAL(11, 118, 13), // "CATextChanged"
QT_MOC_LITERAL(12, 132, 15), // "TextEditChanged"
QT_MOC_LITERAL(13, 148, 5), // "SetID"
QT_MOC_LITERAL(14, 154, 2), // "ID"
QT_MOC_LITERAL(15, 157, 9) // "childName"

    },
    "CreateEtrDlg\0CreateEntry\0\0EditEntry\0"
    "DeleteEntry\0Close\0OpenDAccDlg\0OpenCAccDlg\0"
    "OpenDSAccDlg\0OpenCSAccDlg\0DATextChanged\0"
    "CATextChanged\0TextEditChanged\0SetID\0"
    "ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateEtrDlg[] = {

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
      12,    0,   84,    2, 0x08 /* Private */,
      13,    2,   85,    2, 0x0a /* Public */,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   14,   15,

       0        // eod
};

void CreateEtrDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateEtrDlg *_t = static_cast<CreateEtrDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CreateEntry(); break;
        case 1: _t->EditEntry(); break;
        case 2: _t->DeleteEntry(); break;
        case 3: _t->Close(); break;
        case 4: _t->OpenDAccDlg(); break;
        case 5: _t->OpenCAccDlg(); break;
        case 6: _t->OpenDSAccDlg(); break;
        case 7: _t->OpenCSAccDlg(); break;
        case 8: _t->DATextChanged(); break;
        case 9: _t->CATextChanged(); break;
        case 10: _t->TextEditChanged(); break;
        case 11: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject CreateEtrDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateEtrDlg.data,
      qt_meta_data_CreateEtrDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateEtrDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateEtrDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateEtrDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateEtrDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateEntry"))
        return static_cast< Ui::CreateEntry*>(const_cast< CreateEtrDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateEtrDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
