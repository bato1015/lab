/****************************************************************************
** Meta object code from reading C++ file 'InfoBar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Base/InfoBar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'InfoBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cnoid__InfoBar_t {
    QByteArrayData data[8];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cnoid__InfoBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cnoid__InfoBar_t qt_meta_stringdata_cnoid__InfoBar = {
    {
QT_MOC_LITERAL(0, 0, 14), // "cnoid::InfoBar"
QT_MOC_LITERAL(1, 15, 14), // "onFocusChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "QWidget*"
QT_MOC_LITERAL(4, 40, 3), // "old"
QT_MOC_LITERAL(5, 44, 3), // "now"
QT_MOC_LITERAL(6, 48, 20), // "onIndicatorDestroyed"
QT_MOC_LITERAL(7, 69, 3) // "obj"

    },
    "cnoid::InfoBar\0onFocusChanged\0\0QWidget*\0"
    "old\0now\0onIndicatorDestroyed\0obj"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cnoid__InfoBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x08 /* Private */,
       6,    1,   29,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, QMetaType::QObjectStar,    7,

       0        // eod
};

void cnoid::InfoBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InfoBar *_t = static_cast<InfoBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onFocusChanged((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 1: _t->onIndicatorDestroyed((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject cnoid::InfoBar::staticMetaObject = {
    { &QStatusBar::staticMetaObject, qt_meta_stringdata_cnoid__InfoBar.data,
      qt_meta_data_cnoid__InfoBar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *cnoid::InfoBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cnoid::InfoBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cnoid__InfoBar.stringdata0))
        return static_cast<void*>(this);
    return QStatusBar::qt_metacast(_clname);
}

int cnoid::InfoBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStatusBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
