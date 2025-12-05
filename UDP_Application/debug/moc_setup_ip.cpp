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
    QByteArrayData data[29];
    char stringdata0[477];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SetUp_IP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SetUp_IP_t qt_meta_stringdata_SetUp_IP = {
    {
QT_MOC_LITERAL(0, 0, 8), // "SetUp_IP"
QT_MOC_LITERAL(1, 9, 14), // "ConnectNetWork"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "load_ip"
QT_MOC_LITERAL(4, 33, 7), // "save_ip"
QT_MOC_LITERAL(5, 41, 19), // "buildModbusRTUFrame"
QT_MOC_LITERAL(6, 61, 7), // "slaveId"
QT_MOC_LITERAL(7, 69, 12), // "functionCode"
QT_MOC_LITERAL(8, 82, 12), // "startAddress"
QT_MOC_LITERAL(9, 95, 5), // "long*"
QT_MOC_LITERAL(10, 101, 11), // "dataAddress"
QT_MOC_LITERAL(11, 113, 8), // "dataSize"
QT_MOC_LITERAL(12, 122, 9), // "closePort"
QT_MOC_LITERAL(13, 132, 14), // "updateScanTime"
QT_MOC_LITERAL(14, 147, 30), // "on_tbn_NetworkSettings_clicked"
QT_MOC_LITERAL(15, 178, 22), // "on_tbn_SendCmd_clicked"
QT_MOC_LITERAL(16, 201, 24), // "on_tbn_ClosePort_clicked"
QT_MOC_LITERAL(17, 226, 25), // "on_le_slaveid_textChanged"
QT_MOC_LITERAL(18, 252, 4), // "arg1"
QT_MOC_LITERAL(19, 257, 37), // "on_Cmbx_Func_Code_currentInde..."
QT_MOC_LITERAL(20, 295, 31), // "on_le_registercount_textChanged"
QT_MOC_LITERAL(21, 327, 20), // "on_tbn_Apply_clicked"
QT_MOC_LITERAL(22, 348, 20), // "UpdatePasswordString"
QT_MOC_LITERAL(23, 369, 9), // "_PassWord"
QT_MOC_LITERAL(24, 379, 15), // "loadNetworkData"
QT_MOC_LITERAL(25, 395, 26), // "on_tbn_ResetCounts_clicked"
QT_MOC_LITERAL(26, 422, 20), // "processReceivedFrame"
QT_MOC_LITERAL(27, 443, 6), // "rxData"
QT_MOC_LITERAL(28, 450, 26) // "processReceivedFrame_Slave"

    },
    "SetUp_IP\0ConnectNetWork\0\0load_ip\0"
    "save_ip\0buildModbusRTUFrame\0slaveId\0"
    "functionCode\0startAddress\0long*\0"
    "dataAddress\0dataSize\0closePort\0"
    "updateScanTime\0on_tbn_NetworkSettings_clicked\0"
    "on_tbn_SendCmd_clicked\0on_tbn_ClosePort_clicked\0"
    "on_le_slaveid_textChanged\0arg1\0"
    "on_Cmbx_Func_Code_currentIndexChanged\0"
    "on_le_registercount_textChanged\0"
    "on_tbn_Apply_clicked\0UpdatePasswordString\0"
    "_PassWord\0loadNetworkData\0"
    "on_tbn_ResetCounts_clicked\0"
    "processReceivedFrame\0rxData\0"
    "processReceivedFrame_Slave"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SetUp_IP[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    0,  105,    2, 0x06 /* Public */,
       4,    0,  106,    2, 0x06 /* Public */,
       5,    5,  107,    2, 0x06 /* Public */,
      12,    0,  118,    2, 0x06 /* Public */,
      13,    1,  119,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  122,    2, 0x08 /* Private */,
      15,    0,  123,    2, 0x08 /* Private */,
      16,    0,  124,    2, 0x08 /* Private */,
      17,    1,  125,    2, 0x08 /* Private */,
      19,    1,  128,    2, 0x08 /* Private */,
      20,    1,  131,    2, 0x0a /* Public */,
      21,    0,  134,    2, 0x0a /* Public */,
      22,    1,  135,    2, 0x0a /* Public */,
      24,    0,  138,    2, 0x0a /* Public */,
      25,    0,  139,    2, 0x0a /* Public */,
      26,    1,  140,    2, 0x0a /* Public */,
      28,    1,  143,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UShort, 0x80000000 | 9, QMetaType::UShort,    6,    7,    8,   10,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   27,
    QMetaType::Void, QMetaType::QByteArray,   27,

       0        // eod
};

void SetUp_IP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SetUp_IP *_t = static_cast<SetUp_IP *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ConnectNetWork(); break;
        case 1: _t->load_ip(); break;
        case 2: _t->save_ip(); break;
        case 3: _t->buildModbusRTUFrame((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3])),(*reinterpret_cast< long*(*)>(_a[4])),(*reinterpret_cast< quint16(*)>(_a[5]))); break;
        case 4: _t->closePort(); break;
        case 5: _t->updateScanTime((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->on_tbn_NetworkSettings_clicked(); break;
        case 7: _t->on_tbn_SendCmd_clicked(); break;
        case 8: _t->on_tbn_ClosePort_clicked(); break;
        case 9: _t->on_le_slaveid_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_Cmbx_Func_Code_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_le_registercount_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_tbn_Apply_clicked(); break;
        case 13: _t->UpdatePasswordString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->loadNetworkData(); break;
        case 15: _t->on_tbn_ResetCounts_clicked(); break;
        case 16: _t->processReceivedFrame((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 17: _t->processReceivedFrame_Slave((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SetUp_IP::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SetUp_IP::ConnectNetWork)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SetUp_IP::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SetUp_IP::load_ip)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SetUp_IP::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SetUp_IP::save_ip)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (SetUp_IP::*_t)(quint8 , quint8 , quint16 , long * , quint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SetUp_IP::buildModbusRTUFrame)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (SetUp_IP::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SetUp_IP::closePort)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (SetUp_IP::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SetUp_IP::updateScanTime)) {
                *result = 5;
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
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void SetUp_IP::ConnectNetWork()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void SetUp_IP::load_ip()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void SetUp_IP::save_ip()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void SetUp_IP::buildModbusRTUFrame(quint8 _t1, quint8 _t2, quint16 _t3, long * _t4, quint16 _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SetUp_IP::closePort()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void SetUp_IP::updateScanTime(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
