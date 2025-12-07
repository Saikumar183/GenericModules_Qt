/****************************************************************************
** Meta object code from reading C++ file 'blocksonnumber.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../blocksonnumber.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'blocksonnumber.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BlocksOnNumber_t {
    QByteArrayData data[12];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BlocksOnNumber_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BlocksOnNumber_t qt_meta_stringdata_BlocksOnNumber = {
    {
QT_MOC_LITERAL(0, 0, 14), // "BlocksOnNumber"
QT_MOC_LITERAL(1, 15, 15), // "updateLineEdits"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "count"
QT_MOC_LITERAL(4, 38, 20), // "refreshFormattedData"
QT_MOC_LITERAL(5, 59, 15), // "onFormatChanged"
QT_MOC_LITERAL(6, 75, 15), // "onEndianChanged"
QT_MOC_LITERAL(7, 91, 28), // "convertEditsToSelectedFormat"
QT_MOC_LITERAL(8, 120, 27), // "updateRegisterCountLineEdit"
QT_MOC_LITERAL(9, 148, 7), // "maxData"
QT_MOC_LITERAL(10, 156, 39), // "on_CmBx_byteFormate_currentIn..."
QT_MOC_LITERAL(11, 196, 5) // "index"

    },
    "BlocksOnNumber\0updateLineEdits\0\0count\0"
    "refreshFormattedData\0onFormatChanged\0"
    "onEndianChanged\0convertEditsToSelectedFormat\0"
    "updateRegisterCountLineEdit\0maxData\0"
    "on_CmBx_byteFormate_currentIndexChanged\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BlocksOnNumber[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       1,    1,   57,    2, 0x0a /* Public */,
       4,    0,   60,    2, 0x0a /* Public */,
       5,    1,   61,    2, 0x0a /* Public */,
       6,    1,   64,    2, 0x0a /* Public */,
       7,    0,   67,    2, 0x0a /* Public */,
       8,    1,   68,    2, 0x0a /* Public */,
      10,    1,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void BlocksOnNumber::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BlocksOnNumber *_t = static_cast<BlocksOnNumber *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateLineEdits((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateLineEdits((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->refreshFormattedData(); break;
        case 3: _t->onFormatChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onEndianChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->convertEditsToSelectedFormat(); break;
        case 6: _t->updateRegisterCountLineEdit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->on_CmBx_byteFormate_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject BlocksOnNumber::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BlocksOnNumber.data,
      qt_meta_data_BlocksOnNumber,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BlocksOnNumber::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BlocksOnNumber::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BlocksOnNumber.stringdata0))
        return static_cast<void*>(const_cast< BlocksOnNumber*>(this));
    return QWidget::qt_metacast(_clname);
}

int BlocksOnNumber::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
