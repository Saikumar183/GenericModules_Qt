/****************************************************************************
** Meta object code from reading C++ file 'modbusscreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../modbusscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modbusscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModbusScreen_t {
    QByteArrayData data[37];
    char stringdata0[671];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModbusScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModbusScreen_t qt_meta_stringdata_ModbusScreen = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ModbusScreen"
QT_MOC_LITERAL(1, 13, 14), // "sendSerialData"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "sendUdpData"
QT_MOC_LITERAL(4, 41, 17), // "ScanTimerFunction"
QT_MOC_LITERAL(5, 59, 24), // "on_tbn_ComWindow_clicked"
QT_MOC_LITERAL(6, 84, 19), // "buildModbusRTUFrame"
QT_MOC_LITERAL(7, 104, 7), // "slaveId"
QT_MOC_LITERAL(8, 112, 12), // "functionCode"
QT_MOC_LITERAL(9, 125, 12), // "startAddress"
QT_MOC_LITERAL(10, 138, 15), // "const uint16_t*"
QT_MOC_LITERAL(11, 154, 11), // "dataAddress"
QT_MOC_LITERAL(12, 166, 8), // "dataSize"
QT_MOC_LITERAL(13, 175, 27), // "buildModbusRTUSlaveResponse"
QT_MOC_LITERAL(14, 203, 15), // "ModbusException"
QT_MOC_LITERAL(15, 219, 2), // "ex"
QT_MOC_LITERAL(16, 222, 37), // "on_Cmbx_Func_Code_currentInde..."
QT_MOC_LITERAL(17, 260, 4), // "arg1"
QT_MOC_LITERAL(18, 265, 20), // "onSerialDataReceived"
QT_MOC_LITERAL(19, 286, 12), // "QSerialPort*"
QT_MOC_LITERAL(20, 299, 10), // "serialPort"
QT_MOC_LITERAL(21, 310, 16), // "ProcessUdpRxData"
QT_MOC_LITERAL(22, 327, 7), // "UdpData"
QT_MOC_LITERAL(23, 335, 22), // "onRegisterCountChanged"
QT_MOC_LITERAL(24, 358, 4), // "text"
QT_MOC_LITERAL(25, 363, 7), // "SendCmd"
QT_MOC_LITERAL(26, 371, 26), // "on_tbn_ResetCounts_clicked"
QT_MOC_LITERAL(27, 398, 7), // "checked"
QT_MOC_LITERAL(28, 406, 25), // "on_le_slaveid_textChanged"
QT_MOC_LITERAL(29, 432, 31), // "on_le_registercount_textChanged"
QT_MOC_LITERAL(30, 464, 30), // "on_le_startaddress_textChanged"
QT_MOC_LITERAL(31, 495, 36), // "on_checkBox_ModbusOverSerial_..."
QT_MOC_LITERAL(32, 532, 33), // "on_checkBox_ModbusOverUdp_cli..."
QT_MOC_LITERAL(33, 566, 26), // "on_checkBox_Master_clicked"
QT_MOC_LITERAL(34, 593, 25), // "on_checkBox_Slave_clicked"
QT_MOC_LITERAL(35, 619, 28), // "on_checkBox_autoSend_clicked"
QT_MOC_LITERAL(36, 648, 22) // "on_tbn_SendCmd_clicked"

    },
    "ModbusScreen\0sendSerialData\0\0sendUdpData\0"
    "ScanTimerFunction\0on_tbn_ComWindow_clicked\0"
    "buildModbusRTUFrame\0slaveId\0functionCode\0"
    "startAddress\0const uint16_t*\0dataAddress\0"
    "dataSize\0buildModbusRTUSlaveResponse\0"
    "ModbusException\0ex\0"
    "on_Cmbx_Func_Code_currentIndexChanged\0"
    "arg1\0onSerialDataReceived\0QSerialPort*\0"
    "serialPort\0ProcessUdpRxData\0UdpData\0"
    "onRegisterCountChanged\0text\0SendCmd\0"
    "on_tbn_ResetCounts_clicked\0checked\0"
    "on_le_slaveid_textChanged\0"
    "on_le_registercount_textChanged\0"
    "on_le_startaddress_textChanged\0"
    "on_checkBox_ModbusOverSerial_clicked\0"
    "on_checkBox_ModbusOverUdp_clicked\0"
    "on_checkBox_Master_clicked\0"
    "on_checkBox_Slave_clicked\0"
    "on_checkBox_autoSend_clicked\0"
    "on_tbn_SendCmd_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModbusScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  124,    2, 0x06 /* Public */,
       3,    1,  127,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  130,    2, 0x0a /* Public */,
       5,    0,  131,    2, 0x0a /* Public */,
       6,    5,  132,    2, 0x0a /* Public */,
      13,    6,  143,    2, 0x0a /* Public */,
      16,    1,  156,    2, 0x0a /* Public */,
      18,    1,  159,    2, 0x0a /* Public */,
      21,    1,  162,    2, 0x0a /* Public */,
      23,    1,  165,    2, 0x08 /* Private */,
      25,    0,  168,    2, 0x08 /* Private */,
      26,    0,  169,    2, 0x08 /* Private */,
       5,    1,  170,    2, 0x08 /* Private */,
      28,    1,  173,    2, 0x08 /* Private */,
      29,    1,  176,    2, 0x08 /* Private */,
      30,    1,  179,    2, 0x08 /* Private */,
      31,    1,  182,    2, 0x08 /* Private */,
      32,    1,  185,    2, 0x08 /* Private */,
      33,    1,  188,    2, 0x08 /* Private */,
      34,    1,  191,    2, 0x08 /* Private */,
      35,    1,  194,    2, 0x08 /* Private */,
      36,    0,  197,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UShort, 0x80000000 | 10, QMetaType::UShort,    7,    8,    9,   11,   12,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UShort, 0x80000000 | 10, QMetaType::UShort, 0x80000000 | 14,    7,    8,    9,   11,   12,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, QMetaType::QByteArray,   22,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void,

       0        // eod
};

void ModbusScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModbusScreen *_t = static_cast<ModbusScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendSerialData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->sendUdpData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->ScanTimerFunction(); break;
        case 3: _t->on_tbn_ComWindow_clicked(); break;
        case 4: _t->buildModbusRTUFrame((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3])),(*reinterpret_cast< const uint16_t*(*)>(_a[4])),(*reinterpret_cast< quint16(*)>(_a[5]))); break;
        case 5: _t->buildModbusRTUSlaveResponse((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3])),(*reinterpret_cast< const uint16_t*(*)>(_a[4])),(*reinterpret_cast< quint16(*)>(_a[5])),(*reinterpret_cast< ModbusException(*)>(_a[6]))); break;
        case 6: _t->on_Cmbx_Func_Code_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->onSerialDataReceived((*reinterpret_cast< QSerialPort*(*)>(_a[1]))); break;
        case 8: _t->ProcessUdpRxData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 9: _t->onRegisterCountChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->SendCmd(); break;
        case 11: _t->on_tbn_ResetCounts_clicked(); break;
        case 12: _t->on_tbn_ComWindow_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_le_slaveid_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->on_le_registercount_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->on_le_startaddress_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->on_checkBox_ModbusOverSerial_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->on_checkBox_ModbusOverUdp_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->on_checkBox_Master_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->on_checkBox_Slave_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->on_checkBox_autoSend_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->on_tbn_SendCmd_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSerialPort* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ModbusScreen::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModbusScreen::sendSerialData)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ModbusScreen::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModbusScreen::sendUdpData)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ModbusScreen::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ModbusScreen.data,
      qt_meta_data_ModbusScreen,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ModbusScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModbusScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ModbusScreen.stringdata0))
        return static_cast<void*>(const_cast< ModbusScreen*>(this));
    return QWidget::qt_metacast(_clname);
}

int ModbusScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void ModbusScreen::sendSerialData(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ModbusScreen::sendUdpData(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
