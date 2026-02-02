#pragma once

#include <QObject>
#include <memory>

class ActionsView;
class Vehicle;

namespace LmCdl {
class I_QmlApi;
class I_VcsiApplicationApi;
}

class ActionsModule : public QObject {
    Q_OBJECT
public:
    explicit ActionsModule(
        LmCdl::I_QmlApi& qmlApi,
        LmCdl::I_VcsiApplicationApi& vcsiApplicationApi,
        Vehicle& vehicle);
    virtual ~ActionsModule();

private:
    LmCdl::I_QmlApi& qmlApi_;
    Vehicle& vehicle_;

    std::unique_ptr<ActionsView> actionsView_;
};