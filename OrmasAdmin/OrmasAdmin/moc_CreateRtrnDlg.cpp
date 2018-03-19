/****************************************************************************
** Meta object code from reading C++ file 'CreateRtrnDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateRtrnDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateRtrnDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateRtrnDlg_t {
    QByteArrayData data[15];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateRtrnDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateRtrnDlg_t qt_meta_stringdata_CreateRtrnDlg = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CreateRtrnDlg"
QT_MOC_LITERAL(1, 14, 17), // "CloseCreatedForms"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 12), // "CreateReturn"
QT_MOC_LITERAL(4, 46, 10), // "EditReturn"
QT_MOC_LITERAL(5, 57, 12), // "DeleteReturn"
QT_MOC_LITERAL(6, 70, 5), // "Close"
QT_MOC_LITERAL(7, 76, 10), // "OpenCltDlg"
QT_MOC_LITERAL(8, 87, 10), // "OpenEmpDlg"
QT_MOC_LITERAL(9, 98, 10), // "OpenStsDlg"
QT_MOC_LITERAL(10, 109, 15), // "OpenRtrnListDlg"
QT_MOC_LITERAL(11, 125, 16), // "StatusWasChenged"
QT_MOC_LITERAL(12, 142, 5), // "SetID"
QT_MOC_LITERAL(13, 148, 2), // "ID"
QT_MOC_LITERAL(14, 151, 9) // "childName"

    },
    "CreateRtrnDlg\0CloseCreatedForms\0\0"
    "CreateReturn\0EditReturn\0DeleteReturn\0"
    "Close\0OpenCltDlg\0OpenEmpDlg\0OpenStsDlg\0"
    "OpenRtrnListDlg\0StatusWasChenged\0SetID\0"
    "ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateRtrnDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    2,   79,    2, 0x0a /* Public */,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   13,   14,

       0        // eod
};

void CreateRtrnDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateRtrnDlg *_t = static_cast<CreateRtrnDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CloseCreatedForms(); break;
        case 1: _t->CreateReturn(); break;
        case 2: _t->EditReturn(); break;
        case 3: _t->DeleteReturn(); break;
        case 4: _t->Close(); break;
        case 5: _t->OpenCltDlg(); break;
        case 6: _t->OpenEmpDlg(); break;
        case 7: _t->OpenStsDlg(); break;
        case 8: _t->OpenRtrnListDlg(); break;
        case 9: _t->StatusWasChenged(); break;
        case 10: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CreateRtrnDlg::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CreateRtrnDlg::CloseCreatedForms)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CreateRtrnDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateRtrnDlg.data,
      qt_meta_data_CreateRtrnDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateRtrnDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateRtrnDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateRtrnDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateRtrnDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateReturn"))
        return static_cast< Ui::CreateReturn*>(const_cast< CreateRtrnDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateRtrnDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void CreateRtrnDlg::CloseCreatedForms()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
