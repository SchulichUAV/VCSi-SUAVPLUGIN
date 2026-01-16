#pragma once

#include <QObject>
#include <memory>
#include <QString>

#include <mavsdk/mavsdk.h>
#include <plugins/telemetry/telemetry.h>
#include <plugins/action/action.h>

class MavlinkConnection : public QObject
{
    Q_OBJECT
public:
    explicit MavlinkConnection();
    virtual ~MavlinkConnection();

    void connect_async(const QString& connectionUrl = "udpin://0.0.0.0:14550");

    std::shared_ptr<mavsdk::System> system() const { return system_; }
    std::shared_ptr<mavsdk::Telemetry> telemetry() { return telemetry_; }
    std::shared_ptr<mavsdk::Action> action() { return action_; }

private:    
    std::shared_ptr<mavsdk::Mavsdk> mavsdk_;
    std::shared_ptr<mavsdk::System> system_;
    
    std::shared_ptr<mavsdk::Telemetry> telemetry_;
    std::shared_ptr<mavsdk::Action> action_;
};