/****************************************************************************
** Meta object code from reading C++ file 'CreateSpecDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateSpecDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateSpecDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateSpecDlg_t {
    QByteArrayData data[14];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateSpecDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateSpecDlg_t qt_meta_stringdata_CreateSpecDlg = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CreateSpecDlg"
QT_MOC_LITERAL(1, 14, 17), // "CloseCreatedForms"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 19), // "CreateSpecification"
QT_MOC_LITERAL(4, 53, 17), // "EditSpecification"
QT_MOC_LITERAL(5, 71, 19), // "DeleteSpecification"
QT_MOC_LITERAL(6, 91, 5), // "Close"
QT_MOC_LITERAL(7, 97, 11), // "OpenProdDlg"
QT_MOC_LITERAL(8, 109, 10), // "OpenEmpDlg"
QT_MOC_LITERAL(9, 120, 15), // "OpenSpecListDlg"
QT_MOC_LITERAL(10, 136, 15), // "TextEditChanged"
QT_MOC_LITERAL(11, 152, 5), // "SetID"
QT_MOC_LITERAL(12, 158, 2), // "ID"
QT_MOC_LITERAL(13, 161, 9) // "childName"

    },
    "CreateSpecDlg\0CloseCreatedForms\0\0"
    "CreateSpecification\0EditSpecification\0"
    "DeleteSpecification\0Close\0OpenProdDlg\0"
    "OpenEmpDlg\0OpenSpecListDlg\0TextEditChanged\0"
    "SetID\0ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateSpecDlg[] = {

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

void CreateSpecDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateSpecDlg *_t = static_cast<CreateSpecDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CloseCreatedForms(); break;
        case 1: _t->CreateSpecification(); break;
        case 2: _t->EditSpecification(); break;
        case 3: _t->DeleteSpecification(); break;
        case 4: _t->Close(); break;
        case 5: _t->OpenProdDlg(); break;
        case 6: _t->OpenEmpDlg(); break;
        case 7: _t->OpenSpecListDlg(); break;
        case 8: _t->TextEditChanged(); break;
        case 9: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CreateSpecDlg::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CreateSpecDlg::CloseCreatedForms)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CreateSpecDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateSpecDlg.data,
      qt_meta_data_CreateSpecDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateSpecDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateSpecDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateSpecDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateSpecDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateSpecification"))
        return static_cast< Ui::CreateSpecification*>(const_cast< CreateSpecDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateSpecDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void CreateSpecDlg::CloseCreatedForms()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
