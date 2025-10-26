#pragma once

#include <QBindable>
#include <QProperty>
#include <QObject>
#include <LmCdl/UniqueIdentifier.h>


namespace LmCdl {
class I_VehicleCollectionApi;
class UniqueIdentifier;
}

class Vehicle : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString vehicleId READ vehicleId BINDABLE bindableVehicleId)

public:
    explicit Vehicle(
        LmCdl::I_VehicleCollectionApi& collectionApi);
    virtual ~Vehicle();

    QString vehicleId() const;
    QBindable<QString> bindableVehicleId();

private slots:
    void makeVehicleContent(LmCdl::UniqueIdentifier vehicleId);

private:
    LmCdl::I_VehicleCollectionApi& collectionApi_;

    QProperty<QString> vehicleId_;
};