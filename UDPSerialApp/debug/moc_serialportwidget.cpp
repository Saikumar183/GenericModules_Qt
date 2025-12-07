/****************************************************************************
** Meta object code from reading C++ file 'serialportwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../serialportwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialportwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialPortWidget_t {
    QByteArrayData data[35];
    char stringdata0[524];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialPortWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialPortWidget_t qt_meta_stringdata_SerialPortWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "SerialPortWidget"
QT_MOC_LITERAL(1, 17, 9), // "commerror"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 20), // "onSerialDataReceived"
QT_MOC_LITERAL(4, 49, 12), // "QSerialPort*"
QT_MOC_LITERAL(5, 62, 10), // "serialPort"
QT_MOC_LITERAL(6, 73, 21), // "onReopenButtonClicked"
QT_MOC_LITERAL(7, 95, 19), // "ModbusFrameResponse"
QT_MOC_LITERAL(8, 115, 4), // "data"
QT_MOC_LITERAL(9, 120, 7), // "success"
QT_MOC_LITERAL(10, 128, 14), // "updatePortList"
QT_MOC_LITERAL(11, 143, 17), // "onOpenPortClicked"
QT_MOC_LITERAL(12, 161, 17), // "onSendDataClicked"
QT_MOC_LITERAL(13, 179, 19), // "Send_Serial_Command"
QT_MOC_LITERAL(14, 199, 7), // "uint8_t"
QT_MOC_LITERAL(15, 207, 3), // "CMD"
QT_MOC_LITERAL(16, 211, 13), // "showcomstatus"
QT_MOC_LITERAL(17, 225, 4), // "info"
QT_MOC_LITERAL(18, 230, 21), // "onNumberButtonClicked"
QT_MOC_LITERAL(19, 252, 21), // "onStringButtonClicked"
QT_MOC_LITERAL(20, 274, 18), // "onCRCButtonClicked"
QT_MOC_LITERAL(21, 293, 19), // "updateSendDataField"
QT_MOC_LITERAL(22, 313, 4), // "Data"
QT_MOC_LITERAL(23, 318, 26), // "onBaudRateSelectionChanged"
QT_MOC_LITERAL(24, 345, 5), // "index"
QT_MOC_LITERAL(25, 351, 17), // "showErrorOccurred"
QT_MOC_LITERAL(26, 369, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(27, 398, 15), // "SendModbusFrame"
QT_MOC_LITERAL(28, 414, 5), // "frame"
QT_MOC_LITERAL(29, 420, 14), // "expectedLength"
QT_MOC_LITERAL(30, 435, 12), // "functionCode"
QT_MOC_LITERAL(31, 448, 9), // "timeoutMs"
QT_MOC_LITERAL(32, 458, 29), // "readSerialPortSettingsAndData"
QT_MOC_LITERAL(33, 488, 14), // "sendSerialData"
QT_MOC_LITERAL(34, 503, 20) // "startSendingCommands"

    },
    "SerialPortWidget\0commerror\0\0"
    "onSerialDataReceived\0QSerialPort*\0"
    "serialPort\0onReopenButtonClicked\0"
    "ModbusFrameResponse\0data\0success\0"
    "updatePortList\0onOpenPortClicked\0"
    "onSendDataClicked\0Send_Serial_Command\0"
    "uint8_t\0CMD\0showcomstatus\0info\0"
    "onNumberButtonClicked\0onStringButtonClicked\0"
    "onCRCButtonClicked\0updateSendDataField\0"
    "Data\0onBaudRateSelectionChanged\0index\0"
    "showErrorOccurred\0QSerialPort::SerialPortError\0"
    "SendModbusFrame\0frame\0expectedLength\0"
    "functionCode\0timeoutMs\0"
    "readSerialPortSettingsAndData\0"
    "sendSerialData\0startSendingCommands"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPortWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,
       3,    1,  112,    2, 0x06 /* Public */,
       6,    0,  115,    2, 0x06 /* Public */,
       7,    2,  116,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  121,    2, 0x0a /* Public */,
      11,    0,  122,    2, 0x0a /* Public */,
      12,    0,  123,    2, 0x0a /* Public */,
      13,    1,  124,    2, 0x0a /* Public */,
      16,    1,  127,    2, 0x0a /* Public */,
      18,    0,  130,    2, 0x0a /* Public */,
      19,    0,  131,    2, 0x0a /* Public */,
      20,    0,  132,    2, 0x0a /* Public */,
      21,    1,  133,    2, 0x0a /* Public */,
      23,    1,  136,    2, 0x0a /* Public */,
      25,    1,  139,    2, 0x0a /* Public */,
      27,    4,  142,    2, 0x0a /* Public */,
      32,    0,  151,    2, 0x0a /* Public */,
      33,    1,  152,    2, 0x0a /* Public */,
      34,    0,  155,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Bool,    8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, 0x80000000 | 26,    2,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int, QMetaType::UChar, QMetaType::Int,   28,   29,   30,   31,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,

       0        // eod
};

void SerialPortWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialPortWidget *_t = static_cast<SerialPortWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->commerror((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onSerialDataReceived((*reinterpret_cast< QSerialPort*(*)>(_a[1]))); break;
        case 2: _t->onReopenButtonClicked(); break;
        case 3: _t->ModbusFrameResponse((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->updatePortList(); break;
        case 5: _t->onOpenPortClicked(); break;
        case 6: _t->onSendDataClicked(); break;
        case 7: { bool _r = _t->Send_Serial_Command((*reinterpret_cast< uint8_t(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: _t->showcomstatus((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->onNumberButtonClicked(); break;
        case 10: _t->onStringButtonClicked(); break;
        case 11: _t->onCRCButtonClicked(); break;
        case 12: _t->updateSendDataField((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->onBaudRateSelectionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->showErrorOccurred((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 15: _t->SendModbusFrame((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 16: _t->readSerialPortSettingsAndData(); break;
        case 17: _t->sendSerialData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 18: _t->startSendingCommands(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
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
            typedef void (SerialPortWidget::*_t)(const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialPortWidget::commerror)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SerialPortWidget::*_t)(QSerialPort * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialPortWidget::onSerialDataReceived)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SerialPortWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialPortWidget::onReopenButtonClicked)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (SerialPortWidget::*_t)(QByteArray , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialPortWidget::ModbusFrameResponse)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject SerialPortWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SerialPortWidget.data,
      qt_meta_data_SerialPortWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SerialPortWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialPortWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SerialPortWidget.stringdata0))
        return static_cast<void*>(const_cast< SerialPortWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SerialPortWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void SerialPortWidget::commerror(const QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SerialPortWidget::onSerialDataReceived(QSerialPort * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SerialPortWidget::onReopenButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void SerialPortWidget::ModbusFrameResponse(QByteArray _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
