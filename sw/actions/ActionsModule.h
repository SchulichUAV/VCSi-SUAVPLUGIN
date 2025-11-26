#pragma once

#include <QObject>

class ActionsView;

namespace LmCdl {
class I_QmlApi;
}

class ActionsModule : public QObject {
    Q_OBJECT
public:
    explicit ActionsModule(
        LmCdl::I_QmlApi& qmlApi);
    virtual ~ActionsModule();

private:
        LmCdl::I_QmlApi& qmlApi_;

        std::unique_ptr<ActionsView> actionsView_;
}
