#include <actions/ActionsModule.h>

#include <actions/ActionsView.h>
#include <vehicle/Vehicle.h>
#include <LmCdl/I_QmlApi.h>

ActionsModule::ActionsModule(LmCdl::I_QmlApi& qmlApi)
    : qmlApi_(qmlApi)
    , actionsView_(std::make_unique<ActionsView>(qmlApi))
{
}

ActionsModule::~ActionsModule() = default;
