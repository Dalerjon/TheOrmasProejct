/****************************************************************************
** Meta object code from reading C++ file 'CreateDivAccDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateDivAccDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateDivAccDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateDivAccDlg_t {
    QByteArrayData data[11];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateDivAccDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateDivAccDlg_t qt_meta_stringdata_CreateDivAccDlg = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CreateDivAccDlg"
QT_MOC_LITERAL(1, 16, 17), // "CloseCreatedForms"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 21), // "CreateDivisionAccount"
QT_MOC_LITERAL(4, 57, 19), // "EditDivisionAccount"
QT_MOC_LITERAL(5, 77, 21), // "DeleteDivisionAccount"
QT_MOC_LITERAL(6, 99, 5), // "Close"
QT_MOC_LITERAL(7, 105, 10), // "OpenAccDlg"
QT_MOC_LITERAL(8, 116, 5), // "SetID"
QT_MOC_LITERAL(9, 122, 2), // "ID"
QT_MOC_LITERAL(10, 125, 9) // "childName"

    },
    "CreateDivAccDlg\0CloseCreatedForms\0\0"
    "CreateDivisionAccount\0EditDivisionAccount\0"
    "DeleteDivisionAccount\0Close\0OpenAccDlg\0"
    "SetID\0ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateDivAccDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    2,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    9,   10,

       0        // eod
};

void CreateDivAccDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateDivAccDlg *_t = static_cast<CreateDivAccDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CloseCreatedForms(); break;
        case 1: _t->CreateDivisionAccount(); break;
        case 2: _t->EditDivisionAccount(); break;
        case 3: _t->DeleteDivisionAccount(); break;
        case 4: _t->Close(); break;
        case 5: _t->OpenAccDlg(); break;
        case 6: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CreateDivAccDlg::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CreateDivAccDlg::CloseCreatedForms)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CreateDivAccDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateDivAccDlg.data,
      qt_meta_data_CreateDivAccDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateDivAccDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateDivAccDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateDivAccDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateDivAccDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateDivisionAccount"))
        return static_cast< Ui::CreateDivisionAccount*>(const_cast< CreateDivAccDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateDivAccDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void CreateDivAccDlg::CloseCreatedForms()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
