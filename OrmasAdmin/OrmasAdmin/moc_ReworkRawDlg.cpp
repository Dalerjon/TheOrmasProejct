/****************************************************************************
** Meta object code from reading C++ file 'ReworkRawDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ReworkRawDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ReworkRawDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ReworkRawDlg_t {
    QByteArrayData data[9];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ReworkRawDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ReworkRawDlg_t qt_meta_stringdata_ReworkRawDlg = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ReworkRawDlg"
QT_MOC_LITERAL(1, 13, 6), // "Rework"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 5), // "Close"
QT_MOC_LITERAL(4, 27, 11), // "OpenProdDlg"
QT_MOC_LITERAL(5, 39, 15), // "TextEditChanged"
QT_MOC_LITERAL(6, 55, 5), // "SetID"
QT_MOC_LITERAL(7, 61, 2), // "ID"
QT_MOC_LITERAL(8, 64, 9) // "childName"

    },
    "ReworkRawDlg\0Rework\0\0Close\0OpenProdDlg\0"
    "TextEditChanged\0SetID\0ID\0childName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReworkRawDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    2,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    7,    8,

       0        // eod
};

void ReworkRawDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ReworkRawDlg *_t = static_cast<ReworkRawDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Rework(); break;
        case 1: _t->Close(); break;
        case 2: _t->OpenProdDlg(); break;
        case 3: _t->TextEditChanged(); break;
        case 4: _t->SetID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject ReworkRawDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ReworkRawDlg.data,
      qt_meta_data_ReworkRawDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ReworkRawDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReworkRawDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ReworkRawDlg.stringdata0))
        return static_cast<void*>(const_cast< ReworkRawDlg*>(this));
    if (!strcmp(_clname, "Ui::ReworkRaw"))
        return static_cast< Ui::ReworkRaw*>(const_cast< ReworkRawDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int ReworkRawDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
