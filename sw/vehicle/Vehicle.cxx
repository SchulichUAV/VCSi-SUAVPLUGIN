#include <vehicle/Vehicle.h>

#include <LmCdl/I_Vehicle.h>
#include <LmCdl/I_VehicleCollectionApi.h>
#include <LmCdl/I_VehicleIdentification.h>

Vehicle::Vehicle(LmCdl::I_VehicleCollectionApi& collectionApi)
    : collectionApi_(collectionApi)
{
    vehicleId_.setValue("");
    connect(&collectionApi_,
        &LmCdl::I_VehicleCollectionApi::vehicleAdded,
        this,
        &Vehicle::makeVehicleContent);
}

Vehicle::~Vehicle() = default;

QString Vehicle::vehicleId() const {
    return vehicleId_.value();
}

QBindable<QString> Vehicle::bindableVehicleId() {
    return QBindable<QString>(&vehicleId_);
}

void Vehicle::makeVehicleContent(LmCdl::UniqueIdentifier vehicleId) {
    vehicleId_.setValue(collectionApi_.vehicle(vehicleId).identification().tailNumber());
}
