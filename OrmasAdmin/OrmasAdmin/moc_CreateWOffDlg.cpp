/****************************************************************************
** Meta object code from reading C++ file 'CreateWOffDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateWOffDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateWOffDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateWOffDlg_t {
    QByteArrayData data[16];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateWOffDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateWOffDlg_t qt_meta_stringdata_CreateWOffDlg = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CreateWOffDlg"
QT_MOC_LITERAL(1, 14, 17), // "CloseCreatedForms"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 14), // "CreateWriteOff"
QT_MOC_LITERAL(4, 48, 12), // "EditWriteOff"
QT_MOC_LITERAL(5, 61, 14), // "DeleteWriteOff"
QT_MOC_LITERAL(6, 76, 5), // "Close"
QT_MOC_LITERAL(7, 82, 10), // "OpenCltDlg"
QT_MOC_LITERAL(8, 93, 10), // "OpenEmpDlg"
QT_MOC_LITERAL(9, 104, 10), // "OpenStsDlg"
QT_MOC_LITERAL(10, 115, 15), // "OpenWOffListDlg"
QT_MOC_LITERAL(11, 131, 15), // "TextEditChanged"
QT_MOC_LITERAL(12, 147, 16), // "StatusWasChenged"
QT_MOC_LITERAL(13, 164, 5), // "SetID"
QT_MOC_LITERAL(14, 170, 2), // "ID"
QT_MOC_LITERAL(15, 173, 9) // "childName"

    },
    "CreateWOffDlg\0CloseCreatedForms\0\0"
    "CreateWriteOff\0EditWriteOff\0DeleteWriteOff\0"
    "Close\0OpenCltDlg\0OpenEmpDlg\0OpenStsDlg\0"
    "OpenWOffListDlg\0TextEditChanged\0"
    "StatusWasChenged\0SetID\0ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateWOffDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    2,   85,    2, 0x0a /* Public */,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   14,   15,

       0        // eod
};

void CreateWOffDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateWOffDlg *_t = static_cast<CreateWOffDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CloseCreatedForms(); break;
        case 1: _t->CreateWriteOff(); break;
        case 2: _t->EditWriteOff(); break;
        case 3: _t->DeleteWriteOff(); break;
        case 4: _t->Close(); break;
        case 5: _t->OpenCltDlg(); break;
        case 6: _t->OpenEmpDlg(); break;
        case 7: _t->OpenStsDlg(); break;
        case 8: _t->OpenWOffListDlg(); break;
        case 9: _t->TextEditChanged(); break;
        case 10: _t->StatusWasChenged(); break;
        case 11: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CreateWOffDlg::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CreateWOffDlg::CloseCreatedForms)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CreateWOffDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateWOffDlg.data,
      qt_meta_data_CreateWOffDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateWOffDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateWOffDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateWOffDlg.stringdata0))
        return static_cast<void*>(const_cast< CreateWOffDlg*>(this));
    if (!strcmp(_clname, "Ui::CreateWriteOff"))
        return static_cast< Ui::CreateWriteOff*>(const_cast< CreateWOffDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateWOffDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void CreateWOffDlg::CloseCreatedForms()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
