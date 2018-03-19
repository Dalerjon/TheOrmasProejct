/****************************************************************************
** Meta object code from reading C++ file 'CreateAccDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateAccDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateAccDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateAccDlg_t {
    QByteArrayData data[11];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateAccDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateAccDlg_t qt_meta_stringdata_CreateAccDlg = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CreateAccDlg"
QT_MOC_LITERAL(1, 13, 13), // "CreateAccount"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "EditAccount"
QT_MOC_LITERAL(4, 40, 13), // "DeleteAccount"
QT_MOC_LITERAL(5, 54, 5), // "Close"
QT_MOC_LITERAL(6, 60, 10), // "OpenStsDlg"
QT_MOC_LITERAL(7, 71, 10), // "OpenCOADlg"
QT_MOC_LITERAL(8, 82, 5), // "SetID"
QT_MOC_LITERAL(9, 88, 2), // "ID"
QT_MOC_LITERAL(10, 91, 9) // "childName"

    },
    "CreateAccDlg\0CreateAccount\0\0EditAccount\0"
    "DeleteAccount\0Close\0OpenStsDlg\0"
    "OpenCOADlg\0SetID\0ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateAccDlg[] = {

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

void CreateAccDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateAccDlg *_t = static_cast<CreateAccDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CreateAccount(); break;
        case 1: _t->EditAccount(); break;
        case 2: _t->DeleteAccount(); break;
        case 3: _t->Close(); break;
        case 4: _t->OpenStsDlg(); break;
        case 5: _t->OpenCOADlg(); break;
        case 6: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject CreateAccDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateAccDlg.data,
      qt_meta_data_CreateAccDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateAccDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateAccDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateAccDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateAccDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateAccount"))
        return static_cast< Ui::CreateAccount*>(const_cast< CreateAccDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateAccDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
