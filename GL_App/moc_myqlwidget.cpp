/****************************************************************************
** Meta object code from reading C++ file 'myqlwidget.h'
**
** Created: Sun May 11 12:28:47 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "myqlwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myqlwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyGLWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x05,
      40,   12,   11,   11, 0x05,
      62,   12,   11,   11, 0x05,
      89,   84,   11,   11, 0x05,
     108,  106,   11,   11, 0x05,
     135,  133,   11,   11, 0x05,
     162,  160,   11,   11, 0x05,
     195,  187,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     226,   12,   11,   11, 0x0a,
     244,   12,   11,   11, 0x0a,
     262,   12,   11,   11, 0x0a,
     280,   84,   11,   11, 0x0a,
     293,  106,   11,   11, 0x0a,
     314,  133,   11,   11, 0x0a,
     335,  160,   11,   11, 0x0a,
     356,  187,   11,   11, 0x0a,
     395,  383,   11,   11, 0x0a,
     416,  383,   11,   11, 0x0a,
     439,  383,   11,   11, 0x0a,
     463,  383,   11,   11, 0x0a,
     491,  486,   11,   11, 0x0a,
     513,  507,   11,   11, 0x0a,
     527,   11,   11,   11, 0x0a,
     545,   11,   11,   11, 0x0a,
     560,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyGLWidget[] = {
    "MyGLWidget\0\0angle\0xRotationChanged(int)\0"
    "yRotationChanged(int)\0zRotationChanged(int)\0"
    "zoom\0zoomChanged(int)\0x\0"
    "resolutionChanged_x(int)\0y\0"
    "resolutionChanged_y(int)\0z\0"
    "resolutionChanged_z(int)\0spacing\0"
    "resolutionChanged_spacing(int)\0"
    "setXRotation(int)\0setYRotation(int)\0"
    "setZRotation(int)\0setZoom(int)\0"
    "setResolution_x(int)\0setResolution_y(int)\0"
    "setResolution_z(int)\0setResolution_spacing(int)\0"
    "colorchoice\0changeColorRed(bool)\0"
    "changeColorGreen(bool)\0changeColorYellow(bool)\0"
    "changeColorWhite(bool)\0size\0changeSize(int)\0"
    "yesno\0animate(bool)\0changeAmplitude()\0"
    "openFile(bool)\0stopAnimation(bool)\0"
};

void MyGLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyGLWidget *_t = static_cast<MyGLWidget *>(_o);
        switch (_id) {
        case 0: _t->xRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->yRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->zRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->zoomChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->resolutionChanged_x((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->resolutionChanged_y((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->resolutionChanged_z((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->resolutionChanged_spacing((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setXRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setYRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setZRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->setZoom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setResolution_x((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setResolution_y((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->setResolution_z((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->setResolution_spacing((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->changeColorRed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->changeColorGreen((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->changeColorYellow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->changeColorWhite((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->changeSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->animate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->changeAmplitude(); break;
        case 23: _t->openFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->stopAnimation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyGLWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyGLWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_MyGLWidget,
      qt_meta_data_MyGLWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyGLWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyGLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyGLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyGLWidget))
        return static_cast<void*>(const_cast< MyGLWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int MyGLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void MyGLWidget::xRotationChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyGLWidget::yRotationChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyGLWidget::zRotationChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyGLWidget::zoomChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyGLWidget::resolutionChanged_x(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyGLWidget::resolutionChanged_y(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MyGLWidget::resolutionChanged_z(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MyGLWidget::resolutionChanged_spacing(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
