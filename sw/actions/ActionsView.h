#pragma once

#include <LmCdl/UniqueIdentifier.h>
#include <QObject>
#include <QPointer>
#include <map>

class QQuickWidget;

namespace LmCdl {
class I_QmlApi;
class I_VcsiApplicationApi;
class I_VcsiVehicleExtensionApi;
class I_VehicleCollectionApi;
}

class ActionsView : public QObject {
public:
    ActionsView(LmCdl::I_QmlApi& qmlApi,
                LmCdl::I_VcsiApplicationApi& applicationApi,
                LmCdl::I_VehicleCollectionApi& collectionApi);
    ~ActionsView() override;

private:
    void addVehicle(LmCdl::UniqueIdentifier vehicleId);
    void removeVehicle(LmCdl::UniqueIdentifier vehicleId);

    LmCdl::I_QmlApi& qmlApi_;
    LmCdl::I_VcsiVehicleExtensionApi& vehicleApi_;
    std::map<LmCdl::UniqueIdentifier, QPointer<QQuickWidget>> widgets_;
};
