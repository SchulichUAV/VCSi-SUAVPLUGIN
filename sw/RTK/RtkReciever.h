#pragma once

#include <QObject>
#include <QUdpSocket>
#include <QElapsedTimer>
#include <QByteArray>
#include <QTimer>

class RtkReciever : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isActive READ isActive NOTIFY activeChanged)
public:
    explicit RtkReciever();
    virtual ~RtkReciever();

    void start();
    void stop();
    Q_INVOKABLE bool isActive();

signals:
    void rawMessageReceived(const QByteArray& msg);
    void activeChanged(bool active);

private slots:
    void onReadyRead();

private:
    QUdpSocket socket_; // Receives incoming UDP packets and emits readyRead() when data arrives
    QElapsedTimer lastPacketTime_; // Measures time since the last received packet and resets every time onReadyRead() runs
    QTimer activityTimer_; // checks if the receiver is still active
    bool active_ = false; // current state of the receiver
};
