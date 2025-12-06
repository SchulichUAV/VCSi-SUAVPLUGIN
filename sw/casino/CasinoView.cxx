#include <casino/CasinoView.h>

#include <vehicle/Vehicle.h>
#include <LmCdl/I_QmlApi.h>
#include <QQuickWidget>
#include <QQmlContext>

#include <mavsdk/mavsdk.h>
#include <iostream>

CasinoView::CasinoView(LmCdl::I_QmlApi& qmlApi, Vehicle& vehicle)
    : qmlApi_(qmlApi)
    , vehicle_(vehicle)
{
    QQuickWidget* widget = new QQuickWidget(&qmlApi_.qmlEngine(), nullptr);
    widget->rootContext()->setContextProperty("vehicle", &vehicle);
    widget->setSource(QUrl("qrc:/suav/casino/Casino.qml"));
    widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
}

// void CasionView::SendMessage()
// {
//     mavsdk::Mavsdk mavsdk{mavsdk::Mavsdk::Configuration{mavsdk::Mavsdk::ComponentType::GroundStation}};
    
//     // Connect to vehicle
//     mavsdk::ConnectionResult connection_result = mavsdk.add_any_connection("udp://:14540");
    
//     if (connection_result != mavsdk::ConnectionResult::Success) {
//         std::cerr << "Connection failed!" << std::endl;
//         return;
//     }
    
//     // Wait for system to connect
//     auto system = mavsdk.first_autopilot(3.0);
//     if (!system) {
//         std::cerr << "Timed out waiting for system" << std::endl;
//         return;
//     }
    
//     // Create action plugin
//     auto action = mavsdk::Action{system.value()};
    
//     // Send arm command
//     const mavsdk::Action::Result arm_result = action.arm();
    
//     if (arm_result == mavsdk::Action::Result::Success) {
//         std::cout << "Armed successfully!" << std::endl;
//     } else {
//         std::cerr << "Arming failed: " << arm_result << std::endl;
//     }
// }

CasinoView::~CasinoView() = default;