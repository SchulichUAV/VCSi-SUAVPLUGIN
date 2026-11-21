#include <SuavPluginContent.h>

#include <LmCdl/I_QmlApi.h>
#include <LmCdl/I_VehicleCollectionApi.h>
#include <actions/ActionsView.h>
#include <casino/CasinoModule.h>
#include <parameters/ParameterModule.h>
#include <vehicle/Vehicle.h>
#include <SuavView.h>
#include <messaging/MavlinkConnection.h>
#include <RTK/RtkModule.h>

#include "SuavCrashDiag.h"
#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QDebug>


SuavPluginContent::SuavPluginContent(
    LmCdl::I_VehicleCollectionApi& collectionApi, LmCdl::I_QmlApi& qmlApi,
    LmCdl::I_VcsiApplicationApi& vcsiApplicationApi)
    : collectionApi_(collectionApi)
    , qmlApi_(qmlApi)
    , vehicle_(std::make_unique<Vehicle>(collectionApi_))
    , casinoModule_(std::make_unique<CasinoModule>(qmlApi_, *vehicle_))
    , mavlinkConnection_(std::make_unique<MavlinkConnection>())
    , parameterModule_(std::make_unique<ParameterModule>(*mavlinkConnection_))
    , rtkModule_(std::make_unique<RtkModule>(*mavlinkConnection_))
    , mainView_(std::make_unique<SuavView>(qmlApi_, *rtkModule_, *mavlinkConnection_, *parameterModule_))
    , actionsView_(std::make_unique<ActionsView>(qmlApi_, vcsiApplicationApi, collectionApi_))
{
    installSuavFileLogger();
    installSuavCrashHandlers();

    qInfo() << "==== SuavPluginContent ctor START ====";
    qInfo() << "AppDir:" << QCoreApplication::applicationDirPath();
    qInfo() << "WorkingDir:" << QDir::currentPath();

    qInfo() << "Resource JSON exists?"
            << QFileInfo(":/suav/parameters/apm.pdef.json").exists();
    qInfo() << "==== SuavPluginContent ctor END ====";
}

SuavPluginContent::~SuavPluginContent() = default;
