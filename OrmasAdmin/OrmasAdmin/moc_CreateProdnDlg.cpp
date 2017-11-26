/****************************************************************************
** Meta object code from reading C++ file 'CreateProdnDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateProdnDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateProdnDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateProdnDlg_t {
    QByteArrayData data[8];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateProdnDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateProdnDlg_t qt_meta_stringdata_CreateProdnDlg = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CreateProdnDlg"
QT_MOC_LITERAL(1, 15, 17), // "CloseCreatedForms"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 16), // "CreateProduction"
QT_MOC_LITERAL(4, 51, 14), // "EditProduction"
QT_MOC_LITERAL(5, 66, 16), // "DeleteProduction"
QT_MOC_LITERAL(6, 83, 5), // "Close"
QT_MOC_LITERAL(7, 89, 16) // "OpenProdnListDlg"

    },
    "CreateProdnDlg\0CloseCreatedForms\0\0"
    "CreateProduction\0EditProduction\0"
    "DeleteProduction\0Close\0OpenProdnListDlg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateProdnDlg[] = {

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

void CreateProdnDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateProdnDlg *_t = static_cast<CreateProdnDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CloseCreatedForms(); break;
        case 1: _t->CreateProduction(); break;
        case 2: _t->EditProduction(); break;
        case 3: _t->DeleteProduction(); break;
        case 4: _t->Close(); break;
        case 5: _t->OpenProdnListDlg(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CreateProdnDlg::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CreateProdnDlg::CloseCreatedForms)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CreateProdnDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateProdnDlg.data,
      qt_meta_data_CreateProdnDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateProdnDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateProdnDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateProdnDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateProdnDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateProduction"))
        return static_cast< Ui::CreateProduction*>(const_cast< CreateProdnDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateProdnDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void CreateProdnDlg::CloseCreatedForms()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
