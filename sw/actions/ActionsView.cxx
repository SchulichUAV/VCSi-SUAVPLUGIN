#include <actions/ActionsView.h>

#include <LmCdl/I_QmlApi.h>
#include <LmCdl/I_VcsiApplicationApi.h>
#include <LmCdl/I_VcsiVehicleExtensionApi.h>
#include <LmCdl/I_VcsiWidgetExtensionApi.h>
#include <LmCdl/I_VehicleCollectionApi.h>
#include <LmCdl/TabWidgetMetadata.h>
#include <QQuickWidget>

ActionsView::ActionsView(LmCdl::I_QmlApi& qmlApi,
                         LmCdl::I_VcsiApplicationApi& applicationApi,
                         LmCdl::I_VehicleCollectionApi& collectionApi)
    : qmlApi_(qmlApi)
    , vehicleApi_(applicationApi.widgetExtensionApi().vehicleApi())
{
    connect(&collectionApi, &LmCdl::I_VehicleCollectionApi::vehicleAdded,
            this, &ActionsView::addVehicle);
    connect(&collectionApi, &LmCdl::I_VehicleCollectionApi::vehicleAboutToBeRemoved,
            this, &ActionsView::removeVehicle);

    const auto vehicleIds = collectionApi.allDiscoveredVehicleIds();
    for (const auto& vehicleId : vehicleIds)
        addVehicle(vehicleId);
}

ActionsView::~ActionsView()
{
    while (!widgets_.empty())
        removeVehicle(widgets_.begin()->first);
}

void ActionsView::addVehicle(LmCdl::UniqueIdentifier vehicleId)
{
    if (widgets_.contains(vehicleId))
        return;

    auto* widget = new QQuickWidget(&qmlApi_.qmlEngine(), nullptr);
    widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    widget->setSource(QUrl("qrc:/suav/actions/Actions.qml"));
    widgets_.emplace(vehicleId, widget);
    vehicleApi_.addSettingsMenu(vehicleId, LmCdl::TabWidgetMetadata("Actions"), widget);
}

void ActionsView::removeVehicle(LmCdl::UniqueIdentifier vehicleId)
{
    auto entry = widgets_.extract(vehicleId);
    if (!entry.empty() && entry.mapped()) {
        auto widget = entry.mapped();
        vehicleApi_.removeSettingsMenu(vehicleId, *widget);
        delete widget.data();
    }
}
