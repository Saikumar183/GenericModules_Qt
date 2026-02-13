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
    QByteArrayData data[41];
    char stringdata0[736];
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
QT_MOC_LITERAL(4, 41, 15), // "UpdateLogString"
QT_MOC_LITERAL(5, 57, 3), // "msg"
QT_MOC_LITERAL(6, 61, 17), // "ScanTimerFunction"
QT_MOC_LITERAL(7, 79, 24), // "on_tbn_ComWindow_clicked"
QT_MOC_LITERAL(8, 104, 19), // "buildModbusRTUFrame"
QT_MOC_LITERAL(9, 124, 7), // "slaveId"
QT_MOC_LITERAL(10, 132, 12), // "functionCode"
QT_MOC_LITERAL(11, 145, 12), // "startAddress"
QT_MOC_LITERAL(12, 158, 15), // "const uint16_t*"
QT_MOC_LITERAL(13, 174, 11), // "dataAddress"
QT_MOC_LITERAL(14, 186, 8), // "dataSize"
QT_MOC_LITERAL(15, 195, 27), // "buildModbusRTUSlaveResponse"
QT_MOC_LITERAL(16, 223, 15), // "ModbusException"
QT_MOC_LITERAL(17, 239, 2), // "ex"
QT_MOC_LITERAL(18, 242, 37), // "on_Cmbx_Func_Code_currentInde..."
QT_MOC_LITERAL(19, 280, 4), // "arg1"
QT_MOC_LITERAL(20, 285, 20), // "onSerialDataReceived"
QT_MOC_LITERAL(21, 306, 14), // "serialPortData"
QT_MOC_LITERAL(22, 321, 16), // "ProcessUdpRxData"
QT_MOC_LITERAL(23, 338, 7), // "UdpData"
QT_MOC_LITERAL(24, 346, 22), // "SetComLineEditFontSize"
QT_MOC_LITERAL(25, 369, 4), // "Font"
QT_MOC_LITERAL(26, 374, 22), // "onRegisterCountChanged"
QT_MOC_LITERAL(27, 397, 4), // "text"
QT_MOC_LITERAL(28, 402, 7), // "SendCmd"
QT_MOC_LITERAL(29, 410, 26), // "on_tbn_ResetCounts_clicked"
QT_MOC_LITERAL(30, 437, 7), // "checked"
QT_MOC_LITERAL(31, 445, 25), // "on_le_slaveid_textChanged"
QT_MOC_LITERAL(32, 471, 31), // "on_le_registercount_textChanged"
QT_MOC_LITERAL(33, 503, 30), // "on_le_startaddress_textChanged"
QT_MOC_LITERAL(34, 534, 36), // "on_checkBox_ModbusOverSerial_..."
QT_MOC_LITERAL(35, 571, 33), // "on_checkBox_ModbusOverUdp_cli..."
QT_MOC_LITERAL(36, 605, 26), // "on_checkBox_Master_clicked"
QT_MOC_LITERAL(37, 632, 25), // "on_checkBox_Slave_clicked"
QT_MOC_LITERAL(38, 658, 28), // "on_checkBox_autoSend_clicked"
QT_MOC_LITERAL(39, 687, 22), // "on_tbn_SendCmd_clicked"
QT_MOC_LITERAL(40, 710, 25) // "on_checkBox_Frame_clicked"

    },
    "ModbusScreen\0sendSerialData\0\0sendUdpData\0"
    "UpdateLogString\0msg\0ScanTimerFunction\0"
    "on_tbn_ComWindow_clicked\0buildModbusRTUFrame\0"
    "slaveId\0functionCode\0startAddress\0"
    "const uint16_t*\0dataAddress\0dataSize\0"
    "buildModbusRTUSlaveResponse\0ModbusException\0"
    "ex\0on_Cmbx_Func_Code_currentIndexChanged\0"
    "arg1\0onSerialDataReceived\0serialPortData\0"
    "ProcessUdpRxData\0UdpData\0"
    "SetComLineEditFontSize\0Font\0"
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
    "on_tbn_SendCmd_clicked\0on_checkBox_Frame_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModbusScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  139,    2, 0x06 /* Public */,
       3,    1,  142,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,  145,    2, 0x0a /* Public */,
       6,    0,  148,    2, 0x0a /* Public */,
       7,    0,  149,    2, 0x0a /* Public */,
       8,    5,  150,    2, 0x0a /* Public */,
      15,    6,  161,    2, 0x0a /* Public */,
      18,    1,  174,    2, 0x0a /* Public */,
      20,    1,  177,    2, 0x0a /* Public */,
      22,    1,  180,    2, 0x0a /* Public */,
      24,    1,  183,    2, 0x0a /* Public */,
      26,    1,  186,    2, 0x08 /* Private */,
      28,    0,  189,    2, 0x08 /* Private */,
      29,    0,  190,    2, 0x08 /* Private */,
       7,    1,  191,    2, 0x08 /* Private */,
      31,    1,  194,    2, 0x08 /* Private */,
      32,    1,  197,    2, 0x08 /* Private */,
      33,    1,  200,    2, 0x08 /* Private */,
      34,    1,  203,    2, 0x08 /* Private */,
      35,    1,  206,    2, 0x08 /* Private */,
      36,    1,  209,    2, 0x08 /* Private */,
      37,    1,  212,    2, 0x08 /* Private */,
      38,    1,  215,    2, 0x08 /* Private */,
      39,    0,  218,    2, 0x08 /* Private */,
      40,    1,  219,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UShort, 0x80000000 | 12, QMetaType::UShort,    9,   10,   11,   13,   14,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UShort, 0x80000000 | 12, QMetaType::UShort, 0x80000000 | 16,    9,   10,   11,   13,   14,   17,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QByteArray,   21,
    QMetaType::Void, QMetaType::QByteArray,   23,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   30,

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
        case 2: _t->UpdateLogString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->ScanTimerFunction(); break;
        case 4: _t->on_tbn_ComWindow_clicked(); break;
        case 5: _t->buildModbusRTUFrame((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3])),(*reinterpret_cast< const uint16_t*(*)>(_a[4])),(*reinterpret_cast< quint16(*)>(_a[5]))); break;
        case 6: _t->buildModbusRTUSlaveResponse((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3])),(*reinterpret_cast< const uint16_t*(*)>(_a[4])),(*reinterpret_cast< quint16(*)>(_a[5])),(*reinterpret_cast< ModbusException(*)>(_a[6]))); break;
        case 7: _t->on_Cmbx_Func_Code_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->onSerialDataReceived((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 9: _t->ProcessUdpRxData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 10: _t->SetComLineEditFontSize((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->onRegisterCountChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->SendCmd(); break;
        case 13: _t->on_tbn_ResetCounts_clicked(); break;
        case 14: _t->on_tbn_ComWindow_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->on_le_slaveid_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->on_le_registercount_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->on_le_startaddress_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: _t->on_checkBox_ModbusOverSerial_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->on_checkBox_ModbusOverUdp_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->on_checkBox_Master_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->on_checkBox_Slave_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->on_checkBox_autoSend_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->on_tbn_SendCmd_clicked(); break;
        case 24: _t->on_checkBox_Frame_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
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
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 25;
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
