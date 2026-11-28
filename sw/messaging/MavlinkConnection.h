#pragma once

#include <QObject>
#include <QBindable>
#include <QProperty>
#include <QTimer>
#include <memory>
#include <QString>

#include <mavsdk/mavsdk.h>
#include <plugins/telemetry/telemetry.h>
#include <plugins/action/action.h>
#include <plugins/mavlink_passthrough/mavlink_passthrough.h>

class MavlinkConnection : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool vehicleConnected 
               READ vehicleConnected 
               BINDABLE bindableVehicleConnected)
    Q_PROPERTY(QString connectionStatus
               READ connectionStatus
               BINDABLE bindableConnectionStatus)

public:
    explicit MavlinkConnection();
    virtual ~MavlinkConnection();

    Q_INVOKABLE void connectAsync(const QString& connectionUrl = "udpin://0.0.0.0:14550");
    Q_INVOKABLE bool isConnected();
    
    bool vehicleConnected() const;
    QBindable<bool> bindableVehicleConnected();
    QString connectionStatus() const;
    QBindable<QString> bindableConnectionStatus();

    std::shared_ptr<mavsdk::MavlinkPassthrough> mavlinkPassthrough() { return mavlink_passthrough_; }
    std::shared_ptr<mavsdk::System> system() const { return system_; }
    std::shared_ptr<mavsdk::Telemetry> telemetry() { return telemetry_; }
    std::shared_ptr<mavsdk::Action> action() { return action_; }

private:    
    void subscribeToHeartbeat();
    std::shared_ptr<mavsdk::Mavsdk> mavsdk_;
    std::shared_ptr<mavsdk::System> system_;
    
    std::shared_ptr<mavsdk::Telemetry> telemetry_;
    std::shared_ptr<mavsdk::Action> action_;
    std::shared_ptr<mavsdk::MavlinkPassthrough> mavlink_passthrough_;
    QTimer heartbeatTimeout_;
    QProperty<bool> vehicleConnected_{false};
    QProperty<QString> connectionStatus_{QStringLiteral("Not connected")};
};