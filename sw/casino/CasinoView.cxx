#include <casino/CasinoView.h>

#include <vehicle/Vehicle.h>
#include <LmCdl/I_QmlApi.h>
#include <QQuickWidget>
#include <QQmlContext>

CasinoView::CasinoView(LmCdl::I_QmlApi& qmlApi, Vehicle& vehicle)
    : qmlApi_(qmlApi)
    , vehicle_(vehicle)
{
    QQuickWidget* widget = new QQuickWidget(&qmlApi_.qmlEngine(), nullptr);
    widget->rootContext()->setContextProperty("vehicle", &vehicle);
    widget->setSource(QUrl("qrc:/suav/casino/Casino.qml"));
    widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
}

CasinoView::~CasinoView() = default;