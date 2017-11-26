/****************************************************************************
** Meta object code from reading C++ file 'CreateSlrDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateSlrDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateSlrDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateSlrDlg_t {
    QByteArrayData data[12];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateSlrDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateSlrDlg_t qt_meta_stringdata_CreateSlrDlg = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CreateSlrDlg"
QT_MOC_LITERAL(1, 13, 12), // "CreateSalary"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "EditSalary"
QT_MOC_LITERAL(4, 38, 12), // "DeleteSalary"
QT_MOC_LITERAL(5, 51, 5), // "Close"
QT_MOC_LITERAL(6, 57, 10), // "OpenEmpDlg"
QT_MOC_LITERAL(7, 68, 10), // "OpenCurDlg"
QT_MOC_LITERAL(8, 79, 14), // "OpenSlrTypeDlg"
QT_MOC_LITERAL(9, 94, 5), // "SetID"
QT_MOC_LITERAL(10, 100, 2), // "ID"
QT_MOC_LITERAL(11, 103, 9) // "childName"

    },
    "CreateSlrDlg\0CreateSalary\0\0EditSalary\0"
    "DeleteSalary\0Close\0OpenEmpDlg\0OpenCurDlg\0"
    "OpenSlrTypeDlg\0SetID\0ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateSlrDlg[] = {

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

void CreateSlrDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateSlrDlg *_t = static_cast<CreateSlrDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CreateSalary(); break;
        case 1: _t->EditSalary(); break;
        case 2: _t->DeleteSalary(); break;
        case 3: _t->Close(); break;
        case 4: _t->OpenEmpDlg(); break;
        case 5: _t->OpenCurDlg(); break;
        case 6: _t->OpenSlrTypeDlg(); break;
        case 7: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject CreateSlrDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateSlrDlg.data,
      qt_meta_data_CreateSlrDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateSlrDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateSlrDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateSlrDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateSlrDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateSalary"))
        return static_cast< Ui::CreateSalary*>(const_cast< CreateSlrDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateSlrDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
