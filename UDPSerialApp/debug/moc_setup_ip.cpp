/****************************************************************************
** Meta object code from reading C++ file 'setup_ip.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../setup_ip.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setup_ip.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SetUp_IP_t {
    QByteArrayData data[10];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SetUp_IP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SetUp_IP_t qt_meta_stringdata_SetUp_IP = {
    {
QT_MOC_LITERAL(0, 0, 8), // "SetUp_IP"
QT_MOC_LITERAL(1, 9, 16), // "ProcessUdpRxData"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "updateScanTime"
QT_MOC_LITERAL(4, 42, 30), // "on_tbn_NetworkSettings_clicked"
QT_MOC_LITERAL(5, 73, 21), // "on_btnShowIPs_clicked"
QT_MOC_LITERAL(6, 95, 20), // "on_tbn_Apply_clicked"
QT_MOC_LITERAL(7, 116, 7), // "checked"
QT_MOC_LITERAL(8, 124, 15), // "loadNetworkData"
QT_MOC_LITERAL(9, 140, 11) // "SendUdpData"

    },
    "SetUp_IP\0ProcessUdpRxData\0\0updateScanTime\0"
    "on_tbn_NetworkSettings_clicked\0"
    "on_btnShowIPs_clicked\0on_tbn_Apply_clicked\0"
    "checked\0loadNetworkData\0SendUdpData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SetUp_IP[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   60,    2, 0x08 /* Private */,
       5,    0,   61,    2, 0x08 /* Private */,
       6,    1,   62,    2, 0x08 /* Private */,
       6,    0,   65,    2, 0x0a /* Public */,
       8,    0,   66,    2, 0x0a /* Public */,
       9,    1,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,

       0        // eod
};

void SetUp_IP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SetUp_IP *_t = static_cast<SetUp_IP *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ProcessUdpRxData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->updateScanTime((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_tbn_NetworkSettings_clicked(); break;
        case 3: _t->on_btnShowIPs_clicked(); break;
        case 4: _t->on_tbn_Apply_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_tbn_Apply_clicked(); break;
        case 6: _t->loadNetworkData(); break;
        case 7: _t->SendUdpData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SetUp_IP::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SetUp_IP::ProcessUdpRxData)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SetUp_IP::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SetUp_IP::updateScanTime)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SetUp_IP::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SetUp_IP.data,
      qt_meta_data_SetUp_IP,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SetUp_IP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SetUp_IP::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SetUp_IP.stringdata0))
        return static_cast<void*>(const_cast< SetUp_IP*>(this));
    return QDialog::qt_metacast(_clname);
}

int SetUp_IP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void SetUp_IP::ProcessUdpRxData(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SetUp_IP::updateScanTime(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
