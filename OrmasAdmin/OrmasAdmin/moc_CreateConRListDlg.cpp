/****************************************************************************
** Meta object code from reading C++ file 'CreateConRListDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateConRListDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateConRListDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateConRListDlg_t {
    QByteArrayData data[14];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateConRListDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateConRListDlg_t qt_meta_stringdata_CreateConRListDlg = {
    {
QT_MOC_LITERAL(0, 0, 17), // "CreateConRListDlg"
QT_MOC_LITERAL(1, 18, 13), // "DataIsChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 16), // "AddProductToList"
QT_MOC_LITERAL(4, 50, 17), // "EditProductInList"
QT_MOC_LITERAL(5, 68, 13), // "DeleteProduct"
QT_MOC_LITERAL(6, 82, 5), // "Close"
QT_MOC_LITERAL(7, 88, 11), // "OpenConRDlg"
QT_MOC_LITERAL(8, 100, 11), // "OpenProdDlg"
QT_MOC_LITERAL(9, 112, 10), // "OpenStsDlg"
QT_MOC_LITERAL(10, 123, 15), // "TextEditChanged"
QT_MOC_LITERAL(11, 139, 5), // "SetID"
QT_MOC_LITERAL(12, 145, 2), // "ID"
QT_MOC_LITERAL(13, 148, 9) // "childName"

    },
    "CreateConRListDlg\0DataIsChanged\0\0"
    "AddProductToList\0EditProductInList\0"
    "DeleteProduct\0Close\0OpenConRDlg\0"
    "OpenProdDlg\0OpenStsDlg\0TextEditChanged\0"
    "SetID\0ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateConRListDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    2,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   12,   13,

       0        // eod
};

void CreateConRListDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateConRListDlg *_t = static_cast<CreateConRListDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DataIsChanged(); break;
        case 1: _t->AddProductToList(); break;
        case 2: _t->EditProductInList(); break;
        case 3: _t->DeleteProduct(); break;
        case 4: _t->Close(); break;
        case 5: _t->OpenConRDlg(); break;
        case 6: _t->OpenProdDlg(); break;
        case 7: _t->OpenStsDlg(); break;
        case 8: _t->TextEditChanged(); break;
        case 9: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CreateConRListDlg::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CreateConRListDlg::DataIsChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CreateConRListDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateConRListDlg.data,
      qt_meta_data_CreateConRListDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateConRListDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateConRListDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateConRListDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateConRListDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateConRList"))
        return static_cast< Ui::CreateConRList*>(const_cast< CreateConRListDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateConRListDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void CreateConRListDlg::DataIsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
