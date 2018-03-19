/****************************************************************************
** Meta object code from reading C++ file 'CreatePPlanDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreatePPlanDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreatePPlanDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreatePPlanDlg_t {
    QByteArrayData data[13];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreatePPlanDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreatePPlanDlg_t qt_meta_stringdata_CreatePPlanDlg = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CreatePPlanDlg"
QT_MOC_LITERAL(1, 15, 17), // "CloseCreatedForms"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 20), // "CreateProductionPlan"
QT_MOC_LITERAL(4, 55, 18), // "EditProductionPlan"
QT_MOC_LITERAL(5, 74, 20), // "DeleteProductionPlan"
QT_MOC_LITERAL(6, 95, 5), // "Close"
QT_MOC_LITERAL(7, 101, 10), // "OpenEmpDlg"
QT_MOC_LITERAL(8, 112, 10), // "OpenStsDlg"
QT_MOC_LITERAL(9, 123, 16), // "OpenPPlanListDlg"
QT_MOC_LITERAL(10, 140, 5), // "SetID"
QT_MOC_LITERAL(11, 146, 2), // "ID"
QT_MOC_LITERAL(12, 149, 9) // "childName"

    },
    "CreatePPlanDlg\0CloseCreatedForms\0\0"
    "CreateProductionPlan\0EditProductionPlan\0"
    "DeleteProductionPlan\0Close\0OpenEmpDlg\0"
    "OpenStsDlg\0OpenPPlanListDlg\0SetID\0ID\0"
    "childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreatePPlanDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    2,   67,    2, 0x0a /* Public */,

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
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   11,   12,

       0        // eod
};

void CreatePPlanDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreatePPlanDlg *_t = static_cast<CreatePPlanDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CloseCreatedForms(); break;
        case 1: _t->CreateProductionPlan(); break;
        case 2: _t->EditProductionPlan(); break;
        case 3: _t->DeleteProductionPlan(); break;
        case 4: _t->Close(); break;
        case 5: _t->OpenEmpDlg(); break;
        case 6: _t->OpenStsDlg(); break;
        case 7: _t->OpenPPlanListDlg(); break;
        case 8: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CreatePPlanDlg::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CreatePPlanDlg::CloseCreatedForms)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CreatePPlanDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreatePPlanDlg.data,
      qt_meta_data_CreatePPlanDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreatePPlanDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreatePPlanDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreatePPlanDlg.stringdata0))
        return static_cast<void*>(const_cast< CreatePPlanDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateProductionPlan"))
        return static_cast< Ui::CreateProductionPlan*>(const_cast< CreatePPlanDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreatePPlanDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CreatePPlanDlg::CloseCreatedForms()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
