#pragma once

#include <QObject>
#include <LmCdl/UniqueIdentifier.h>

class Vehicle;

namespace LmCdl {
class I_QmlApi;
class I_VcsiApplicationApi;
}

class ActionsView : public QObject {
    Q_OBJECT
public:
    explicit ActionsView(
        LmCdl::I_QmlApi& qmlApi,
        LmCdl::I_VcsiApplicationApi& vcsiApplicationApi,
        Vehicle &vehicle);
    virtual ~ActionsView();

private:
    LmCdl::I_QmlApi& qmlApi_;
    LmCdl::I_VcsiApplicationApi& vcsiApplicationApi_;
    Vehicle& vehicle_;
};
