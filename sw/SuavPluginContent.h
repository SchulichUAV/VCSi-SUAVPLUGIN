#pragma once

#include <QObject>
#include <memory>

class ActionsView;
class ParameterModule;
class MavlinkConnection;
class SuavView;
class RtkModule;

namespace LmCdl
{
    class I_QmlApi;
    class I_VcsiApplicationApi;
    class I_VehicleCollectionApi;
}

class SuavPluginContent : public QObject {
    Q_OBJECT

public:
    explicit SuavPluginContent(
        LmCdl::I_VehicleCollectionApi& collectionApi, LmCdl::I_QmlApi& qmlApi,
        LmCdl::I_VcsiApplicationApi& vcsiApplicationApi);
    virtual ~SuavPluginContent();

private:
    std::unique_ptr<MavlinkConnection> mavlinkConnection_;
    std::unique_ptr<ParameterModule> parameterModule_;
    std::unique_ptr<RtkModule> rtkModule_;
    std::unique_ptr<SuavView> mainView_;
    std::unique_ptr<ActionsView> actionsView_;
};
