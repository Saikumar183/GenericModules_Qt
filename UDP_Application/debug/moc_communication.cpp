/****************************************************************************
** Meta object code from reading C++ file 'communication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../communication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'communication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Communication_t {
    QByteArrayData data[48];
    char stringdata0[691];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Communication_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Communication_t qt_meta_stringdata_Communication = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Communication"
QT_MOC_LITERAL(1, 14, 21), // "SendData_toMainWindow"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 7), // "uint8_t"
QT_MOC_LITERAL(4, 45, 26), // "updateAlarmTableWithString"
QT_MOC_LITERAL(5, 72, 8), // "uint16_t"
QT_MOC_LITERAL(6, 81, 11), // "_nodeNumber"
QT_MOC_LITERAL(7, 93, 12), // "_ErrorNumber"
QT_MOC_LITERAL(8, 106, 14), // "UpdateLogTable"
QT_MOC_LITERAL(9, 121, 17), // "showStatusMessage"
QT_MOC_LITERAL(10, 139, 12), // "UpdateScreen"
QT_MOC_LITERAL(11, 152, 19), // "RetryCommuinication"
QT_MOC_LITERAL(12, 172, 14), // "UpdateDateTime"
QT_MOC_LITERAL(13, 187, 17), // "Debug_Application"
QT_MOC_LITERAL(14, 205, 15), // "loadNetworkData"
QT_MOC_LITERAL(15, 221, 20), // "showMsgOnLoginScreen"
QT_MOC_LITERAL(16, 242, 20), // "processReceivedFrame"
QT_MOC_LITERAL(17, 263, 6), // "rxData"
QT_MOC_LITERAL(18, 270, 26), // "processReceivedFrame_Slave"
QT_MOC_LITERAL(19, 297, 15), // "SendModbusFrame"
QT_MOC_LITERAL(20, 313, 5), // "frame"
QT_MOC_LITERAL(21, 319, 14), // "expectedLength"
QT_MOC_LITERAL(22, 334, 12), // "functionCode"
QT_MOC_LITERAL(23, 347, 9), // "timeoutMs"
QT_MOC_LITERAL(24, 357, 19), // "ModbusFrameResponse"
QT_MOC_LITERAL(25, 377, 4), // "data"
QT_MOC_LITERAL(26, 382, 7), // "success"
QT_MOC_LITERAL(27, 390, 15), // "handleReadyRead"
QT_MOC_LITERAL(28, 406, 14), // "CheckHeartBeat"
QT_MOC_LITERAL(29, 421, 12), // "displayError"
QT_MOC_LITERAL(30, 434, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(31, 463, 11), // "socketError"
QT_MOC_LITERAL(32, 475, 8), // "sendData"
QT_MOC_LITERAL(33, 484, 12), // "QHostAddress"
QT_MOC_LITERAL(34, 497, 11), // "destination"
QT_MOC_LITERAL(35, 509, 15), // "destinationPort"
QT_MOC_LITERAL(36, 525, 8), // "uint32_t"
QT_MOC_LITERAL(37, 534, 22), // "Init_UDP_Communication"
QT_MOC_LITERAL(38, 557, 13), // "Reconnect_UDP"
QT_MOC_LITERAL(39, 571, 14), // "connectNetwork"
QT_MOC_LITERAL(40, 586, 9), // "closePort"
QT_MOC_LITERAL(41, 596, 19), // "buildModbusRTUFrame"
QT_MOC_LITERAL(42, 616, 7), // "slaveId"
QT_MOC_LITERAL(43, 624, 12), // "startAddress"
QT_MOC_LITERAL(44, 637, 5), // "long*"
QT_MOC_LITERAL(45, 643, 11), // "dataAddress"
QT_MOC_LITERAL(46, 655, 8), // "dataSize"
QT_MOC_LITERAL(47, 664, 26) // "ModbusFrameResponseHandler"

    },
    "Communication\0SendData_toMainWindow\0"
    "\0uint8_t\0updateAlarmTableWithString\0"
    "uint16_t\0_nodeNumber\0_ErrorNumber\0"
    "UpdateLogTable\0showStatusMessage\0"
    "UpdateScreen\0RetryCommuinication\0"
    "UpdateDateTime\0Debug_Application\0"
    "loadNetworkData\0showMsgOnLoginScreen\0"
    "processReceivedFrame\0rxData\0"
    "processReceivedFrame_Slave\0SendModbusFrame\0"
    "frame\0expectedLength\0functionCode\0"
    "timeoutMs\0ModbusFrameResponse\0data\0"
    "success\0handleReadyRead\0CheckHeartBeat\0"
    "displayError\0QAbstractSocket::SocketError\0"
    "socketError\0sendData\0QHostAddress\0"
    "destination\0destinationPort\0uint32_t\0"
    "Init_UDP_Communication\0Reconnect_UDP\0"
    "connectNetwork\0closePort\0buildModbusRTUFrame\0"
    "slaveId\0startAddress\0long*\0dataAddress\0"
    "dataSize\0ModbusFrameResponseHandler"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Communication[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,  154,    2, 0x06 /* Public */,
       4,    2,  161,    2, 0x06 /* Public */,
       8,    1,  166,    2, 0x06 /* Public */,
       9,    1,  169,    2, 0x06 /* Public */,
       9,    2,  172,    2, 0x06 /* Public */,
      10,    0,  177,    2, 0x06 /* Public */,
      11,    0,  178,    2, 0x06 /* Public */,
      12,    0,  179,    2, 0x06 /* Public */,
      13,    0,  180,    2, 0x06 /* Public */,
      14,    0,  181,    2, 0x06 /* Public */,
      15,    1,  182,    2, 0x06 /* Public */,
      16,    1,  185,    2, 0x06 /* Public */,
      18,    1,  188,    2, 0x06 /* Public */,
      19,    4,  191,    2, 0x06 /* Public */,
      24,    2,  200,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      27,    0,  205,    2, 0x0a /* Public */,
      28,    0,  206,    2, 0x0a /* Public */,
      29,    1,  207,    2, 0x0a /* Public */,
      32,    3,  210,    2, 0x0a /* Public */,
      32,    1,  217,    2, 0x0a /* Public */,
      32,    1,  220,    2, 0x0a /* Public */,
      32,    1,  223,    2, 0x0a /* Public */,
      37,    0,  226,    2, 0x0a /* Public */,
      38,    0,  227,    2, 0x0a /* Public */,
      39,    0,  228,    2, 0x0a /* Public */,
      40,    0,  229,    2, 0x0a /* Public */,
      41,    5,  230,    2, 0x0a /* Public */,
      47,    2,  241,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, QMetaType::QByteArray,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    6,    7,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QByteArray,   17,
    QMetaType::Void, QMetaType::QByteArray,   17,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int, QMetaType::UChar, QMetaType::Int,   20,   21,   22,   23,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Bool,   25,   26,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 30,   31,
    QMetaType::Void, 0x80000000 | 33, QMetaType::UShort, QMetaType::QByteArray,   34,   35,   25,
    QMetaType::Void, 0x80000000 | 36,    2,
    QMetaType::Void, QMetaType::Char,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UShort, 0x80000000 | 44, QMetaType::UShort,   42,   22,   43,   45,   46,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Bool,   25,   26,

       0        // eod
};

void Communication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Communication *_t = static_cast<Communication *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendData_toMainWindow((*reinterpret_cast< uint8_t(*)>(_a[1])),(*reinterpret_cast< uint8_t(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 1: _t->updateAlarmTableWithString((*reinterpret_cast< uint16_t(*)>(_a[1])),(*reinterpret_cast< uint16_t(*)>(_a[2]))); break;
        case 2: _t->UpdateLogTable((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->showStatusMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->showStatusMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->UpdateScreen(); break;
        case 6: _t->RetryCommuinication(); break;
        case 7: _t->UpdateDateTime(); break;
        case 8: _t->Debug_Application(); break;
        case 9: _t->loadNetworkData(); break;
        case 10: _t->showMsgOnLoginScreen((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->processReceivedFrame((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 12: _t->processReceivedFrame_Slave((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 13: _t->SendModbusFrame((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 14: _t->ModbusFrameResponse((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 15: _t->handleReadyRead(); break;
        case 16: _t->CheckHeartBeat(); break;
        case 17: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 18: _t->sendData((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 19: _t->sendData((*reinterpret_cast< uint32_t(*)>(_a[1]))); break;
        case 20: _t->sendData((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 21: _t->sendData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 22: _t->Init_UDP_Communication(); break;
        case 23: { bool _r = _t->Reconnect_UDP();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 24: _t->connectNetwork(); break;
        case 25: _t->closePort(); break;
        case 26: _t->buildModbusRTUFrame((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3])),(*reinterpret_cast< long*(*)>(_a[4])),(*reinterpret_cast< quint16(*)>(_a[5]))); break;
        case 27: _t->ModbusFrameResponseHandler((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Communication::*_t)(uint8_t , uint8_t , const QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communication::SendData_toMainWindow)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(uint16_t , uint16_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communication::updateAlarmTableWithString)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communication::UpdateLogTable)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communication::showStatusMessage)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communication::showStatusMessage)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Communication::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communication::UpdateScreen)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Communication::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communication::RetryCommuinication)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Communication::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communication::UpdateDateTime)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (Communication::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communication::Debug_Application)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (Communication::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communication::loadNetworkData)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communication::showMsgOnLoginScreen)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communication::processReceivedFrame)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communication::processReceivedFrame_Slave)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(QByteArray , int , quint8 , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communication::SendModbusFrame)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(QByteArray , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communication::ModbusFrameResponse)) {
                *result = 14;
                return;
            }
        }
    }
}

const QMetaObject Communication::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Communication.data,
      qt_meta_data_Communication,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Communication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Communication::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Communication.stringdata0))
        return static_cast<void*>(const_cast< Communication*>(this));
    return QObject::qt_metacast(_clname);
}

int Communication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    }
    return _id;
}

// SIGNAL 0
void Communication::SendData_toMainWindow(uint8_t _t1, uint8_t _t2, const QByteArray _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Communication::updateAlarmTableWithString(uint16_t _t1, uint16_t _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Communication::UpdateLogTable(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Communication::showStatusMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Communication::showStatusMessage(QString _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Communication::UpdateScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void Communication::RetryCommuinication()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void Communication::UpdateDateTime()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void Communication::Debug_Application()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void Communication::loadNetworkData()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void Communication::showMsgOnLoginScreen(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Communication::processReceivedFrame(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Communication::processReceivedFrame_Slave(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Communication::SendModbusFrame(QByteArray _t1, int _t2, quint8 _t3, int _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Communication::ModbusFrameResponse(QByteArray _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
