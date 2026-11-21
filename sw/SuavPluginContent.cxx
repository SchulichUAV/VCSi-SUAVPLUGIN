#include <SuavPluginContent.h>

#include <LmCdl/I_QmlApi.h>
#include <LmCdl/I_VehicleCollectionApi.h>
#include <actions/ActionsView.h>
#include <parameters/ParameterModule.h>
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
    : mavlinkConnection_(std::make_unique<MavlinkConnection>())
    , parameterModule_(std::make_unique<ParameterModule>(*mavlinkConnection_))
    , rtkModule_(std::make_unique<RtkModule>(*mavlinkConnection_))
    , mainView_(std::make_unique<SuavView>(qmlApi, *rtkModule_, *mavlinkConnection_, *parameterModule_))
    , actionsView_(std::make_unique<ActionsView>(qmlApi, vcsiApplicationApi, collectionApi))
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
