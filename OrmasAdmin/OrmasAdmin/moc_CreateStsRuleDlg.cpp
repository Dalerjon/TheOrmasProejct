/****************************************************************************
** Meta object code from reading C++ file 'CreateStsRuleDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateStsRuleDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateStsRuleDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateStsRuleDlg_t {
    QByteArrayData data[8];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateStsRuleDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateStsRuleDlg_t qt_meta_stringdata_CreateStsRuleDlg = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CreateStsRuleDlg"
QT_MOC_LITERAL(1, 17, 17), // "CloseCreatedForms"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 16), // "CreateStatusRule"
QT_MOC_LITERAL(4, 53, 14), // "EditStatusRule"
QT_MOC_LITERAL(5, 68, 16), // "DeleteStatusRule"
QT_MOC_LITERAL(6, 85, 5), // "Close"
QT_MOC_LITERAL(7, 91, 10) // "OpenStsDlg"

    },
    "CreateStsRuleDlg\0CloseCreatedForms\0\0"
    "CreateStatusRule\0EditStatusRule\0"
    "DeleteStatusRule\0Close\0OpenStsDlg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateStsRuleDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CreateStsRuleDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateStsRuleDlg *_t = static_cast<CreateStsRuleDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CloseCreatedForms(); break;
        case 1: _t->CreateStatusRule(); break;
        case 2: _t->EditStatusRule(); break;
        case 3: _t->DeleteStatusRule(); break;
        case 4: _t->Close(); break;
        case 5: _t->OpenStsDlg(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CreateStsRuleDlg::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CreateStsRuleDlg::CloseCreatedForms)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CreateStsRuleDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateStsRuleDlg.data,
      qt_meta_data_CreateStsRuleDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateStsRuleDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateStsRuleDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateStsRuleDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateStsRuleDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateStatusRule"))
        return static_cast< Ui::CreateStatusRule*>(const_cast< CreateStsRuleDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateStsRuleDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CreateStsRuleDlg::CloseCreatedForms()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
