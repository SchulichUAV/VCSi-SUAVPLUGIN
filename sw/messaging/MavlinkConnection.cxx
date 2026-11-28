#include "MavlinkConnection.h"

#include <iostream>
#include <string>
#include <memory>

#include <QDebug>
#include <QString>

using namespace mavsdk;

MavlinkConnection::MavlinkConnection()
    : mavsdk_(nullptr)
{
    heartbeatTimeout_.setSingleShot(true);
    heartbeatTimeout_.setInterval(3000);
    connect(&heartbeatTimeout_, &QTimer::timeout, this, [this]() {
        vehicleConnected_ = false;
        connectionStatus_ = QStringLiteral("Heartbeat lost");
    });
}

MavlinkConnection::~MavlinkConnection() = default;

bool MavlinkConnection::isConnected() {
    return system_->is_connected();
}

bool MavlinkConnection::vehicleConnected() const {
    return vehicleConnected_.value();
}

QBindable<bool> MavlinkConnection::bindableVehicleConnected() {
    return QBindable<bool>(&vehicleConnected_);
}

QString MavlinkConnection::connectionStatus() const {
    return connectionStatus_.value();
}

QBindable<QString> MavlinkConnection::bindableConnectionStatus() {
    return QBindable<QString>(&connectionStatus_);
}

void MavlinkConnection::connectAsync(const QString& connectionUrl)
{
    qDebug() << "Initializing MAVSDK Connection...";
    connectionStatus_ = QStringLiteral("Starting connection...");

    if (!mavsdk_) {
        Mavsdk::Configuration config{255, 190, true};
        mavsdk_ = std::make_shared<Mavsdk>(config);
    }

    std::string url = connectionUrl.isEmpty() ? "udpin://0.0.0.0:14550" : connectionUrl.toStdString();
    
    qDebug() << "Listening for MAVLink traffic on:" << QString::fromStdString(url);

    auto connection_result = mavsdk_->add_any_connection(url);

    if (connection_result != ConnectionResult::Success) {
        qDebug() << "Connection failed code:" << static_cast<int>(connection_result);
        connectionStatus_ = QStringLiteral("Connection failed (code %1)")
                                .arg(static_cast<int>(connection_result));
        return;
    }

    else if (connection_result == ConnectionResult::Success)
    {
        qDebug() << "Connection success!";
        connectionStatus_ = QStringLiteral("Waiting for heartbeat...");
    }

    mavsdk_->subscribe_on_new_system([this]() {
        if (mavsdk_->systems().empty()) {
            return;
        }

        auto sys = mavsdk_->systems().back();
        
        if (!sys->is_connected()) {
            return;
        }

        if (system_ && system_->get_system_id() == sys->get_system_id()) {
            return; 
        }

        qDebug() << "New System Discovered! ID:" << sys->get_system_id();
        system_ = sys;

        telemetry_ = std::make_shared<Telemetry>(system_);
        action_ = std::make_shared<Action>(system_);

        subscribeToHeartbeat();

        telemetry_->subscribe_position([](Telemetry::Position position) {
             qDebug() << "Altitude:" << position.relative_altitude_m << "m";
        });
    });
}

void MavlinkConnection::subscribeToHeartbeat()
{
    mavlink_passthrough_ = std::make_shared<mavsdk::MavlinkPassthrough>(system_);

    mavlink_passthrough_->subscribe_message(
        MAVLINK_MSG_ID_HEARTBEAT,
        [this](const mavlink_message_t& message) {
            mavlink_heartbeat_t heartbeat{};
            mavlink_msg_heartbeat_decode(&message, &heartbeat);

            QMetaObject::invokeMethod(this, [this]() {
                vehicleConnected_ = true;
                connectionStatus_ = QStringLiteral("Heartbeat active");
                heartbeatTimeout_.start();
            }, Qt::QueuedConnection);

            qDebug() << "Heartbeat:"
                     << "system=" << message.sysid
                     << "component=" << message.compid
                     << "type=" << heartbeat.type
                     << "armed=" << ((heartbeat.base_mode &
                                      MAV_MODE_FLAG_SAFETY_ARMED) != 0);
        });
}