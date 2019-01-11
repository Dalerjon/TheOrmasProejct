/****************************************************************************
** Meta object code from reading C++ file 'CreateBrhDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateBrhDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateBrhDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateBrhDlg_t {
    QByteArrayData data[6];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateBrhDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateBrhDlg_t qt_meta_stringdata_CreateBrhDlg = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CreateBrhDlg"
QT_MOC_LITERAL(1, 13, 12), // "CreateBranch"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "EditBranch"
QT_MOC_LITERAL(4, 38, 12), // "DeleteBranch"
QT_MOC_LITERAL(5, 51, 5) // "Close"

    },
    "CreateBrhDlg\0CreateBranch\0\0EditBranch\0"
    "DeleteBranch\0Close"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateBrhDlg[] = {

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

void CreateBrhDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateBrhDlg *_t = static_cast<CreateBrhDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CreateBranch(); break;
        case 1: _t->EditBranch(); break;
        case 2: _t->DeleteBranch(); break;
        case 3: _t->Close(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CreateBrhDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateBrhDlg.data,
      qt_meta_data_CreateBrhDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateBrhDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateBrhDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateBrhDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateBrhDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateBranch"))
        return static_cast< Ui::CreateBranch*>(const_cast< CreateBrhDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateBrhDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
