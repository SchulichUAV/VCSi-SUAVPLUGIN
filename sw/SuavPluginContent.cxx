#include <SuavPluginContent.h>

#include <LmCdl/I_QmlApi.h>
#include <LmCdl/I_VehicleCollectionApi.h>
#include <LmCdl/I_VcsiApplicationApi.h>
#include <casino/CasinoModule.h>
#include <vehicle/Vehicle.h>
#include <QQuickWidget>
#include <actions/ActionsModule.h>

// instantiate feature modules in this file
SuavPluginContent::SuavPluginContent(LmCdl::I_VehicleCollectionApi& collectionApi, LmCdl::I_QmlApi& qmlApi, LmCdl::I_VcsiApplicationApi& vcsiApplicationApi)
    : collectionApi_(collectionApi)
    , qmlApi_(qmlApi)
    , vehicle_(std::make_unique<Vehicle>(collectionApi_))
    , casinoModule_(std::make_unique<CasinoModule>(qmlApi_, *vehicle_))
    , actionsModule_(std::make_unique<ActionsModule>(qmlApi_, vcsiApplicationApi, *vehicle_))
{
}

SuavPluginContent::~SuavPluginContent() = default;
