// #include "RtkReciever.h"

// RtkReciever::RtkReciever(QObject* parent)
//     : QObject(parent)
// {
//     connect(&socket_, &QUdpSocket::readyRead,
//             this, &RtkReciever::onReadyRead);

//     // Check activity every 500 ms
//     connect(&activityTimer_, &QTimer::timeout, this, [this]() {
//         if (active_ && !isActive()) {
//             active_ = false;
//             emit activeChanged(false);
//         }
//     });

//     activityTimer_.start(500);
// }
// void RtkReciever::start()
// {
//     quint16 port = 2101; 

//     if (socket_.bind(QHostAddress::localhost, port, QUdpSocket::ShareAddress))
//     {
//         lastPacketTime_.invalidate();
//         active_ = false;
//         emit activeChanged(false);
//     }
// }

// void RtkReciever::stop()
// {
//     socket_.close();
// }

// bool RtkReciever::isActive() 
// {
//     if (!lastPacketTime_.isValid())
//         return false;

//     // Consider dead if no packet in 2 seconds
//     return lastPacketTime_.elapsed() < 2000;
// }

// void RtkReciever::onReadyRead()
// {
//     // Mark receiver as active when data arrives
//     lastPacketTime_.start();

//     if (!active_) {
//         active_ = true;
//         emit activeChanged(true);
//     }

//     while (socket_.hasPendingDatagrams()) { // Returns true if at least one datagram is waiting to be read
//         QByteArray datagram; //represents the full information contained in a UDP datagram
//         datagram.resize(socket_.pendingDatagramSize());
//         socket_.readDatagram(datagram.data(), datagram.size());
//         emit rawMessageReceived(datagram);
//     }
// }
