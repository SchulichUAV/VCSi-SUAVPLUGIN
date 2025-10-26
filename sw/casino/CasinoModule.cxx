#include <casino/CasinoModule.h>
#include <vehicle/Vehicle.h>
#include <LmCdl/I_QmlApi.h>
#include <LmCdl/I_VehicleCollectionApi.h>
#include <QQuickWidget>
#include <QQmlContext>
#include <QDebug>
#include <QDirIterator>
#include <QFile>

CasinoModule::CasinoModule(LmCdl::I_QmlApi& qmlApi, Vehicle& vehicle)
    : qmlApi_(qmlApi)
    , vehicle_(vehicle)
{

    QQuickWidget* widget = new QQuickWidget(&qmlApi_.qmlEngine(), nullptr);
    widget->rootContext()->setContextProperty("vehicle", &vehicle);
    widget->setSource(QUrl("qrc:/suav/casino/Casino.qml"));
    widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
}

CasinoModule::~CasinoModule() = default;