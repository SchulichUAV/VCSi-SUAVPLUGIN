#pragma once

#include <QObject>
#include <LmCdl/UniqueIdentifier.h>

namespace LmCdl {
class I_QmlApi;
class I_VcsiApplicationApi;
}

class ActionsView : public QObject {
    Q_OBJECT
public:
    explicit ActionsView(
        LmCdl::I_QmlApi& qmlApi,
        LmCdl::I_VcsiApplicationApi& vcsiApplicationApi);
    virtual ~ActionsView();

private:
    LmCdl::I_QmlApi& qmlApi_;
    LmCdl::I_VcsiApplicationApi& vcsiApplicationApi_;
};
