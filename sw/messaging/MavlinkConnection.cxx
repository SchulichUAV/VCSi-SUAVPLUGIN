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

void MavlinkConnection::connectAsync(const QString& connectionUrl)
{
    qDebug() << "Initializing MAVSDK Connection...";

    if (!mavsdk_) {
        Mavsdk::Configuration config{255, 190, true};
        mavsdk_ = std::make_shared<Mavsdk>(config);
    }

    std::string url = connectionUrl.isEmpty() ? "udpin://0.0.0.0:14550" : connectionUrl.toStdString();

    qDebug() << "Listening for MAVLink traffic on:" << QString::fromStdString(url);

    auto connection_result = mavsdk_->add_any_connection(url);

    if (connection_result != ConnectionResult::Success) {
        qDebug() << "Connection failed code:" << static_cast<int>(connection_result);
        return;
    }

    else if (connection_result == ConnectionResult::Success)
    {
        qDebug() << "Connection success!";
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
        mavlink_passthrough_ = std::make_shared<MavlinkPassthrough>(system_);

        qDebug() << "MavlinkPassthrough initialized. Sending is now available.";

        telemetry_->subscribe_position([](Telemetry::Position position) {
             qDebug() << "Altitude:" << position.relative_altitude_m << "m";
        });

        QMetaObject::invokeMethod(this, [this]() {
            vehicleConnected_ = true;
        }, Qt::QueuedConnection);
    });
}
