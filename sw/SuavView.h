#pragma once

#include <QObject>
#include <LmCdl/UniqueIdentifier.h>

class ParameterModule;
class RtkModule;
class MavlinkConnection;

namespace LmCdl
{
    class I_QmlApi;
}

class SuavView : public QObject
{
    Q_OBJECT
public:
    explicit SuavView(LmCdl::I_QmlApi &qmlApi, RtkModule &rtkModule, MavlinkConnection &mavlinkConnection, ParameterModule &parameterModule);
    virtual ~SuavView();

private:
    LmCdl::I_QmlApi &qmlApi_;
};