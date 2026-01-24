#pragma once

#include <QObject>
#include <LmCdl/UniqueIdentifier.h>

namespace LmCdl
{
    class I_QmlApi;
}

class SuavView : public QObject
{
    Q_OBJECT
public:
    explicit SuavView(LmCdl::I_QmlApi &qmlApi);
    virtual ~SuavView();

private:
    LmCdl::I_QmlApi &qmlApi_;
};