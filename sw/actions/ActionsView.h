#pragma once

#include <QObject>
#include <LmCdl/UniqueIdentifier.h>

namespace LmCdl {
class I_QmlApi;
}

class ActionsView : public QObject {
    Q_OBJECT
public:
    explicit ActionsView(
        LmCdl::I_QmlApi& qmlApi);
    virtual ~ActionsView();

private:
    LmCdl::I_QmlApi& qmlApi_;
};
