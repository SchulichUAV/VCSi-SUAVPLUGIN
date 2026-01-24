#include <RTK/RtkReciever.h>
#include <QHostAddress>

RtkReciever::RtkReciever()
{
    connect(&socket_, &QUdpSocket::readyRead,
            this, &RtkReciever::onReadyRead);

    connect(&activityTimer_, &QTimer::timeout, this, [this]() {
        if (active_ && !isActive()) {
            active_ = false;
            emit activeChanged(false);
        }
    });

    activityTimer_.start(500);
}

RtkReciever::~RtkReciever() = default;

void RtkReciever::start()
{
    quint16 port = 2101;
 
    if (socket_.bind(QHostAddress::LocalHost, port, QUdpSocket::ShareAddress))
    {
        lastPacketTime_.invalidate();
        active_ = false;
        emit activeChanged(false);
    }
}

void RtkReciever::stop()
{
    socket_.close();
}

bool RtkReciever::isActive() 
{
    if (!lastPacketTime_.isValid())
        return false;

    return lastPacketTime_.elapsed() < 2000;
}

void RtkReciever::onReadyRead()
{
    lastPacketTime_.start();

    if (!active_) {
        active_ = true;
        emit activeChanged(true);
    }

    while (socket_.hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(socket_.pendingDatagramSize());
        socket_.readDatagram(datagram.data(), datagram.size());
        emit rawMessageReceived(datagram);
    }
}
