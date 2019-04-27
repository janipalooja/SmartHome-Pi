/****************************************************************************
** Meta object code from reading C++ file 'serial.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "serial.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Serial_t {
    QByteArrayData data[29];
    char stringdata0[438];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Serial_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Serial_t qt_meta_stringdata_Serial = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Serial"
QT_MOC_LITERAL(1, 7, 18), // "temperatureChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "humidityChanged"
QT_MOC_LITERAL(4, 43, 10), // "CO2Changed"
QT_MOC_LITERAL(5, 54, 24), // "lightswitch1StateChanged"
QT_MOC_LITERAL(6, 79, 24), // "lightswitch2StateChanged"
QT_MOC_LITERAL(7, 104, 24), // "lightswitch3StateChanged"
QT_MOC_LITERAL(8, 129, 24), // "lightswitch4StateChanged"
QT_MOC_LITERAL(9, 154, 15), // "daylightChanged"
QT_MOC_LITERAL(10, 170, 14), // "setTemperature"
QT_MOC_LITERAL(11, 185, 11), // "setHumidity"
QT_MOC_LITERAL(12, 197, 6), // "setCO2"
QT_MOC_LITERAL(13, 204, 20), // "setLightswitch1State"
QT_MOC_LITERAL(14, 225, 20), // "setLightswitch2State"
QT_MOC_LITERAL(15, 246, 20), // "setLightswitch3State"
QT_MOC_LITERAL(16, 267, 20), // "setLightswitch4State"
QT_MOC_LITERAL(17, 288, 11), // "setDaylight"
QT_MOC_LITERAL(18, 300, 10), // "readSerial"
QT_MOC_LITERAL(19, 311, 11), // "writeSerial"
QT_MOC_LITERAL(20, 323, 4), // "data"
QT_MOC_LITERAL(21, 328, 11), // "temperature"
QT_MOC_LITERAL(22, 340, 8), // "humidity"
QT_MOC_LITERAL(23, 349, 3), // "CO2"
QT_MOC_LITERAL(24, 353, 18), // "lightswitch1_state"
QT_MOC_LITERAL(25, 372, 18), // "lightswitch2_state"
QT_MOC_LITERAL(26, 391, 18), // "lightswitch3_state"
QT_MOC_LITERAL(27, 410, 18), // "lightswitch4_state"
QT_MOC_LITERAL(28, 429, 8) // "daylight"

    },
    "Serial\0temperatureChanged\0\0humidityChanged\0"
    "CO2Changed\0lightswitch1StateChanged\0"
    "lightswitch2StateChanged\0"
    "lightswitch3StateChanged\0"
    "lightswitch4StateChanged\0daylightChanged\0"
    "setTemperature\0setHumidity\0setCO2\0"
    "setLightswitch1State\0setLightswitch2State\0"
    "setLightswitch3State\0setLightswitch4State\0"
    "setDaylight\0readSerial\0writeSerial\0"
    "data\0temperature\0humidity\0CO2\0"
    "lightswitch1_state\0lightswitch2_state\0"
    "lightswitch3_state\0lightswitch4_state\0"
    "daylight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Serial[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       8,  140, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    0,  105,    2, 0x06 /* Public */,
       4,    0,  106,    2, 0x06 /* Public */,
       5,    0,  107,    2, 0x06 /* Public */,
       6,    0,  108,    2, 0x06 /* Public */,
       7,    0,  109,    2, 0x06 /* Public */,
       8,    0,  110,    2, 0x06 /* Public */,
       9,    0,  111,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,  112,    2, 0x0a /* Public */,
      11,    1,  115,    2, 0x0a /* Public */,
      12,    1,  118,    2, 0x0a /* Public */,
      13,    1,  121,    2, 0x0a /* Public */,
      14,    1,  124,    2, 0x0a /* Public */,
      15,    1,  127,    2, 0x0a /* Public */,
      16,    1,  130,    2, 0x0a /* Public */,
      17,    1,  133,    2, 0x0a /* Public */,
      18,    0,  136,    2, 0x0a /* Public */,
      19,    1,  137,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   20,

 // properties: name, type, flags
      21, QMetaType::Float, 0x00495103,
      22, QMetaType::Float, 0x00495103,
      23, QMetaType::Float, 0x00495103,
      24, QMetaType::Int, 0x00495003,
      25, QMetaType::Int, 0x00495003,
      26, QMetaType::Int, 0x00495003,
      27, QMetaType::Int, 0x00495003,
      28, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,

       0        // eod
};

void Serial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Serial *_t = static_cast<Serial *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->temperatureChanged(); break;
        case 1: _t->humidityChanged(); break;
        case 2: _t->CO2Changed(); break;
        case 3: _t->lightswitch1StateChanged(); break;
        case 4: _t->lightswitch2StateChanged(); break;
        case 5: _t->lightswitch3StateChanged(); break;
        case 6: _t->lightswitch4StateChanged(); break;
        case 7: _t->daylightChanged(); break;
        case 8: _t->setTemperature((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 9: _t->setHumidity((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 10: _t->setCO2((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 11: _t->setLightswitch1State((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setLightswitch2State((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setLightswitch3State((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->setLightswitch4State((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->setDaylight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->readSerial(); break;
        case 17: _t->writeSerial((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Serial::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serial::temperatureChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Serial::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serial::humidityChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Serial::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serial::CO2Changed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Serial::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serial::lightswitch1StateChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Serial::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serial::lightswitch2StateChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Serial::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serial::lightswitch3StateChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Serial::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serial::lightswitch4StateChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Serial::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serial::daylightChanged)) {
                *result = 7;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Serial *_t = static_cast<Serial *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< float*>(_v) = _t->temperature(); break;
        case 1: *reinterpret_cast< float*>(_v) = _t->humidity(); break;
        case 2: *reinterpret_cast< float*>(_v) = _t->CO2(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->lightswitch1_state(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->lightswitch2_state(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->lightswitch3_state(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->lightswitch4_state(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->daylight(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Serial *_t = static_cast<Serial *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTemperature(*reinterpret_cast< float*>(_v)); break;
        case 1: _t->setHumidity(*reinterpret_cast< float*>(_v)); break;
        case 2: _t->setCO2(*reinterpret_cast< float*>(_v)); break;
        case 3: _t->setLightswitch1State(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setLightswitch2State(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setLightswitch3State(*reinterpret_cast< int*>(_v)); break;
        case 6: _t->setLightswitch4State(*reinterpret_cast< int*>(_v)); break;
        case 7: _t->setDaylight(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Serial::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Serial.data,
    qt_meta_data_Serial,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Serial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Serial::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Serial.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Serial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Serial::temperatureChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Serial::humidityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Serial::CO2Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Serial::lightswitch1StateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Serial::lightswitch2StateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Serial::lightswitch3StateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Serial::lightswitch4StateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Serial::daylightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
