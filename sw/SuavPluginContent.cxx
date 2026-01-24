#include <SuavPluginContent.h>

#include <LmCdl/I_QmlApi.h>
#include <LmCdl/I_VehicleCollectionApi.h>
#include <casino/CasinoModule.h>
#include <vehicle/Vehicle.h>
#include <SuavView.h>
#include <messaging/MavlinkConnection.h>
#include <QQuickWidget>

SuavPluginContent::SuavPluginContent(LmCdl::I_VehicleCollectionApi& collectionApi, LmCdl::I_QmlApi& qmlApi)
    // instantiate feature modules in this file
    : collectionApi_(collectionApi)
    , qmlApi_(qmlApi)
    , mainView_(std::make_unique<SuavView>(qmlApi_))
    , vehicle_(std::make_unique<Vehicle>(collectionApi_))
    , casinoModule_(std::make_unique<CasinoModule>(qmlApi_, *vehicle_))
    , mavlinkConnection_(std::make_unique<MavlinkConnection>())
{
    mavlinkConnection_->connect_async("udpin://0.0.0.0:14550");
}

SuavPluginContent::~SuavPluginContent() = default;
