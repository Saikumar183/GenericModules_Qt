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
    QByteArrayData data[33];
    char stringdata0[626];
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
QT_MOC_LITERAL(3, 29, 17), // "ScanTimerFunction"
QT_MOC_LITERAL(4, 47, 24), // "on_tbn_ComWindow_clicked"
QT_MOC_LITERAL(5, 72, 19), // "buildModbusRTUFrame"
QT_MOC_LITERAL(6, 92, 7), // "slaveId"
QT_MOC_LITERAL(7, 100, 12), // "functionCode"
QT_MOC_LITERAL(8, 113, 12), // "startAddress"
QT_MOC_LITERAL(9, 126, 15), // "const uint16_t*"
QT_MOC_LITERAL(10, 142, 11), // "dataAddress"
QT_MOC_LITERAL(11, 154, 8), // "dataSize"
QT_MOC_LITERAL(12, 163, 27), // "buildModbusRTUSlaveResponse"
QT_MOC_LITERAL(13, 191, 15), // "ModbusException"
QT_MOC_LITERAL(14, 207, 2), // "ex"
QT_MOC_LITERAL(15, 210, 37), // "on_Cmbx_Func_Code_currentInde..."
QT_MOC_LITERAL(16, 248, 4), // "arg1"
QT_MOC_LITERAL(17, 253, 20), // "onSerialDataReceived"
QT_MOC_LITERAL(18, 274, 12), // "QSerialPort*"
QT_MOC_LITERAL(19, 287, 10), // "serialPort"
QT_MOC_LITERAL(20, 298, 22), // "onRegisterCountChanged"
QT_MOC_LITERAL(21, 321, 4), // "text"
QT_MOC_LITERAL(22, 326, 22), // "on_tbn_SendCmd_clicked"
QT_MOC_LITERAL(23, 349, 26), // "on_tbn_ResetCounts_clicked"
QT_MOC_LITERAL(24, 376, 7), // "checked"
QT_MOC_LITERAL(25, 384, 25), // "on_le_slaveid_textChanged"
QT_MOC_LITERAL(26, 410, 31), // "on_le_registercount_textChanged"
QT_MOC_LITERAL(27, 442, 30), // "on_le_startaddress_textChanged"
QT_MOC_LITERAL(28, 473, 36), // "on_checkBox_ModbusOverSerial_..."
QT_MOC_LITERAL(29, 510, 33), // "on_checkBox_ModbusOverUdp_cli..."
QT_MOC_LITERAL(30, 544, 26), // "on_checkBox_Master_clicked"
QT_MOC_LITERAL(31, 571, 25), // "on_checkBox_Slave_clicked"
QT_MOC_LITERAL(32, 597, 28) // "on_checkBox_autoSend_clicked"

    },
    "ModbusScreen\0sendSerialData\0\0"
    "ScanTimerFunction\0on_tbn_ComWindow_clicked\0"
    "buildModbusRTUFrame\0slaveId\0functionCode\0"
    "startAddress\0const uint16_t*\0dataAddress\0"
    "dataSize\0buildModbusRTUSlaveResponse\0"
    "ModbusException\0ex\0"
    "on_Cmbx_Func_Code_currentIndexChanged\0"
    "arg1\0onSerialDataReceived\0QSerialPort*\0"
    "serialPort\0onRegisterCountChanged\0"
    "text\0on_tbn_SendCmd_clicked\0"
    "on_tbn_ResetCounts_clicked\0checked\0"
    "on_le_slaveid_textChanged\0"
    "on_le_registercount_textChanged\0"
    "on_le_startaddress_textChanged\0"
    "on_checkBox_ModbusOverSerial_clicked\0"
    "on_checkBox_ModbusOverUdp_clicked\0"
    "on_checkBox_Master_clicked\0"
    "on_checkBox_Slave_clicked\0"
    "on_checkBox_autoSend_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModbusScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  112,    2, 0x0a /* Public */,
       4,    0,  113,    2, 0x0a /* Public */,
       5,    5,  114,    2, 0x0a /* Public */,
      12,    6,  125,    2, 0x0a /* Public */,
      15,    1,  138,    2, 0x0a /* Public */,
      17,    1,  141,    2, 0x0a /* Public */,
      20,    1,  144,    2, 0x08 /* Private */,
      22,    0,  147,    2, 0x08 /* Private */,
      23,    0,  148,    2, 0x08 /* Private */,
       4,    1,  149,    2, 0x08 /* Private */,
      25,    1,  152,    2, 0x08 /* Private */,
      26,    1,  155,    2, 0x08 /* Private */,
      27,    1,  158,    2, 0x08 /* Private */,
      28,    1,  161,    2, 0x08 /* Private */,
      29,    1,  164,    2, 0x08 /* Private */,
      30,    1,  167,    2, 0x08 /* Private */,
      31,    1,  170,    2, 0x08 /* Private */,
      32,    1,  173,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UShort, 0x80000000 | 9, QMetaType::UShort,    6,    7,    8,   10,   11,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UShort, 0x80000000 | 9, QMetaType::UShort, 0x80000000 | 13,    6,    7,    8,   10,   11,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,

       0        // eod
};

void ModbusScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModbusScreen *_t = static_cast<ModbusScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendSerialData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->ScanTimerFunction(); break;
        case 2: _t->on_tbn_ComWindow_clicked(); break;
        case 3: _t->buildModbusRTUFrame((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3])),(*reinterpret_cast< const uint16_t*(*)>(_a[4])),(*reinterpret_cast< quint16(*)>(_a[5]))); break;
        case 4: _t->buildModbusRTUSlaveResponse((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3])),(*reinterpret_cast< const uint16_t*(*)>(_a[4])),(*reinterpret_cast< quint16(*)>(_a[5])),(*reinterpret_cast< ModbusException(*)>(_a[6]))); break;
        case 5: _t->on_Cmbx_Func_Code_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->onSerialDataReceived((*reinterpret_cast< QSerialPort*(*)>(_a[1]))); break;
        case 7: _t->onRegisterCountChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_tbn_SendCmd_clicked(); break;
        case 9: _t->on_tbn_ResetCounts_clicked(); break;
        case 10: _t->on_tbn_ComWindow_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_le_slaveid_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_le_registercount_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->on_le_startaddress_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->on_checkBox_ModbusOverSerial_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->on_checkBox_ModbusOverUdp_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->on_checkBox_Master_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->on_checkBox_Slave_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->on_checkBox_autoSend_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
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
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void ModbusScreen::sendSerialData(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
