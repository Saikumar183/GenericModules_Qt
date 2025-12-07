/****************************************************************************
** Meta object code from reading C++ file 'endianregistergridwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../endianregistergridwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'endianregistergridwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EndianRegisterGridWidget_t {
    QByteArrayData data[13];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EndianRegisterGridWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EndianRegisterGridWidget_t qt_meta_stringdata_EndianRegisterGridWidget = {
    {
QT_MOC_LITERAL(0, 0, 24), // "EndianRegisterGridWidget"
QT_MOC_LITERAL(1, 25, 13), // "setEndianMode"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 13), // "EndianMode_et"
QT_MOC_LITERAL(4, 54, 4), // "mode"
QT_MOC_LITERAL(5, 59, 11), // "setEditable"
QT_MOC_LITERAL(6, 71, 8), // "editable"
QT_MOC_LITERAL(7, 80, 18), // "setEndianModeIndex"
QT_MOC_LITERAL(8, 99, 5), // "index"
QT_MOC_LITERAL(9, 105, 16), // "setDisplayFormat"
QT_MOC_LITERAL(10, 122, 16), // "DisplayFormat_et"
QT_MOC_LITERAL(11, 139, 3), // "fmt"
QT_MOC_LITERAL(12, 143, 21) // "setDisplayFormatIndex"

    },
    "EndianRegisterGridWidget\0setEndianMode\0"
    "\0EndianMode_et\0mode\0setEditable\0"
    "editable\0setEndianModeIndex\0index\0"
    "setDisplayFormat\0DisplayFormat_et\0fmt\0"
    "setDisplayFormatIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EndianRegisterGridWidget[] = {

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
       1,    1,   39,    2, 0x0a /* Public */,
       5,    1,   42,    2, 0x0a /* Public */,
       7,    1,   45,    2, 0x0a /* Public */,
       9,    1,   48,    2, 0x0a /* Public */,
      12,    1,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void EndianRegisterGridWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EndianRegisterGridWidget *_t = static_cast<EndianRegisterGridWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setEndianMode((*reinterpret_cast< EndianMode_et(*)>(_a[1]))); break;
        case 1: _t->setEditable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setEndianModeIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setDisplayFormat((*reinterpret_cast< DisplayFormat_et(*)>(_a[1]))); break;
        case 4: _t->setDisplayFormatIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject EndianRegisterGridWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EndianRegisterGridWidget.data,
      qt_meta_data_EndianRegisterGridWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EndianRegisterGridWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EndianRegisterGridWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EndianRegisterGridWidget.stringdata0))
        return static_cast<void*>(const_cast< EndianRegisterGridWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int EndianRegisterGridWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
