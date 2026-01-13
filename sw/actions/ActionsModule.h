#pragma once

#include <QObject>
#include <memory>

class ActionsView;

namespace LmCdl {
class I_QmlApi;
class I_VcsiApplicationApi;
}

class ActionsModule : public QObject {
    Q_OBJECT
public:
    explicit ActionsModule(
        LmCdl::I_QmlApi& qmlApi,
        LmCdl::I_VcsiApplicationApi& vcsiApplicationApi);
    virtual ~ActionsModule();

private:
    LmCdl::I_QmlApi& qmlApi_;

    std::unique_ptr<ActionsView> actionsView_;
};