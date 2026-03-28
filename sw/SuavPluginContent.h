#pragma once

#include <QObject>
#include <memory>

class CasinoModule;
class ParameterModule;
class Vehicle;
class MavlinkConnection;
class SuavView;
class RtkModule;

 namespace LmCdl
{
    class I_QmlApi;
    class I_VehicleCollectionApi;
}

class SuavPluginContent : public QObject {
    Q_OBJECT

public:
    explicit SuavPluginContent(
        LmCdl::I_VehicleCollectionApi& collectionApi, LmCdl::I_QmlApi& qmlApi);
    virtual ~SuavPluginContent();

private:
    LmCdl::I_VehicleCollectionApi& collectionApi_;
    LmCdl::I_QmlApi& qmlApi_;


    std::unique_ptr<Vehicle> vehicle_;
    std::unique_ptr<CasinoModule> casinoModule_;
    std::unique_ptr<ParameterModule> parameterModule_;
    std::unique_ptr<MavlinkConnection> mavlinkConnection_;
    std::unique_ptr<RtkModule> rtkModule_;
    std::unique_ptr<SuavView> mainView_;
};