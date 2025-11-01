#include <casino/CasinoModule.h>

#include <casino/CasinoView.h>
#include <vehicle/Vehicle.h>
#include <LmCdl/I_QmlApi.h>

CasinoModule::CasinoModule(LmCdl::I_QmlApi& qmlApi, Vehicle& vehicle)
    : qmlApi_(qmlApi)
    , vehicle_(vehicle)
    // add domain in here, pass into the view
    , casinoView_(std::make_unique<CasinoView>(qmlApi, vehicle))
{
}

CasinoModule::~CasinoModule() = default;