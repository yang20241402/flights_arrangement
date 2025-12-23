/****************************************************************************
** Meta object code from reading C++ file 'viewmanager.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/viewmanager.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN11ViewManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto ViewManager::qt_create_metaobjectdata<qt_meta_tag_ZN11ViewManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ViewManager",
        "viewChanged",
        "",
        "ViewType",
        "from",
        "to",
        "userLoggedIn",
        "userId",
        "userLoggedOut",
        "showLoginView",
        "showRegisterView",
        "showPasswordResetView",
        "showUserCenterView",
        "showMainView",
        "showAdminPanel",
        "showFlightAdminPanel",
        "onLoginSuccessful",
        "onAdminLoginSuccessful",
        "onRegistrationCompleted",
        "onPasswordResetCompleted",
        "onOpenChangeTicketPage",
        "departCity",
        "arriveCity",
        "flightNo",
        "flightDate"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'viewChanged'
        QtMocHelpers::SignalData<void(enum ViewType, enum ViewType)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 3, 5 },
        }}),
        // Signal 'userLoggedIn'
        QtMocHelpers::SignalData<void(int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Signal 'userLoggedOut'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showLoginView'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showRegisterView'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showPasswordResetView'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showUserCenterView'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showMainView'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showAdminPanel'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showFlightAdminPanel'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onLoginSuccessful'
        QtMocHelpers::SlotData<void(int)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'onAdminLoginSuccessful'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onRegistrationCompleted'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onPasswordResetCompleted'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onOpenChangeTicketPage'
        QtMocHelpers::SlotData<void(const QString &, const QString &, const QString &, const QDate &)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 21 }, { QMetaType::QString, 22 }, { QMetaType::QString, 23 }, { QMetaType::QDate, 24 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ViewManager, qt_meta_tag_ZN11ViewManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ViewManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11ViewManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11ViewManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11ViewManagerE_t>.metaTypes,
    nullptr
} };

void ViewManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ViewManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->viewChanged((*reinterpret_cast< std::add_pointer_t<enum ViewType>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<enum ViewType>>(_a[2]))); break;
        case 1: _t->userLoggedIn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->userLoggedOut(); break;
        case 3: _t->showLoginView(); break;
        case 4: _t->showRegisterView(); break;
        case 5: _t->showPasswordResetView(); break;
        case 6: _t->showUserCenterView(); break;
        case 7: _t->showMainView(); break;
        case 8: _t->showAdminPanel(); break;
        case 9: _t->showFlightAdminPanel(); break;
        case 10: _t->onLoginSuccessful((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->onAdminLoginSuccessful(); break;
        case 12: _t->onRegistrationCompleted(); break;
        case 13: _t->onPasswordResetCompleted(); break;
        case 14: _t->onOpenChangeTicketPage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QDate>>(_a[4]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ViewManager::*)(ViewType , ViewType )>(_a, &ViewManager::viewChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ViewManager::*)(int )>(_a, &ViewManager::userLoggedIn, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ViewManager::*)()>(_a, &ViewManager::userLoggedOut, 2))
            return;
    }
}

const QMetaObject *ViewManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ViewManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11ViewManagerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ViewManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void ViewManager::viewChanged(ViewType _t1, ViewType _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void ViewManager::userLoggedIn(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void ViewManager::userLoggedOut()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
