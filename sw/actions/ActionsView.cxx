#include <actions/ActionsView.h>
#include <LmCdl/I_VcsiApplicationApi.h>
#include <LmCdl/I_QmlApi.h>
#include <QQuickWidget>
#include <QQmlContext>
#include <vehicle/Vehicle.h>
#include <LmCdl/TabWidgetMetadata.h>
#include <LmCdl/I_VcsiWidgetExtensionApi.h>
#include <LmCdl/I_VcsiVehicleExtensionApi.h>

ActionsView::ActionsView(LmCdl::I_QmlApi& qmlApi, LmCdl::I_VcsiApplicationApi& vcsiApplicationApi, Vehicle& vehicle)
    : qmlApi_(qmlApi), vcsiApplicationApi_(vcsiApplicationApi), vehicle_(vehicle)
{
    LmCdl::TabWidgetMetadata metadata("Actions");
    LmCdl::UniqueIdentifier id(1);
    QQuickWidget* widget = new QQuickWidget(&qmlApi_.qmlEngine(), nullptr);
    widget->setSource(QUrl("qrc:/suav/actions/Actions.qml"));
    widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    vcsiApplicationApi_.widgetExtensionApi().vehicleApi().addSettingsMenu(id, metadata, widget);
}

ActionsView::~ActionsView() = default;