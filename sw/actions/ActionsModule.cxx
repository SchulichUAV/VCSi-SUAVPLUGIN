#include <actions/ActionsModule.h>

#include <actions/ActionsView.h>
#include <vehicle/Vehicle.h>
#include <LmCdl/I_QmlApi.h>

ActionsModule::ActionsModule(LmCdl::I_QmlApi& qmlApi, LmCdl::I_VcsiApplicationApi& vcsiApplicationApi, Vehicle& vehicle)
    : qmlApi_(qmlApi)
    , vehicle_(vehicle)
    , actionsView_(std::make_unique<ActionsView>(qmlApi, vcsiApplicationApi, vehicle))
{
}

ActionsModule::~ActionsModule() = default;
