#include <actions/ActionsModule.h>

#include <actions/ActionsView.h>
#include <vehicle/Vehicle.h>
#include <LmCdl/I_QmlApi.h>

ActionsModule::ActionsModule(LmCdl::I_QmlApi& qmlApi, LmCdl::I_VcsiApplicationApi& vcsiApplicationApi)
    : qmlApi_(qmlApi)
    , actionsView_(std::make_unique<ActionsView>(qmlApi, vcsiApplicationApi))
{
}

ActionsModule::~ActionsModule() = default;
