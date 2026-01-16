// #pragma once

// #include <QObject>
// #include <QByteArray>
// #include <QTimer>

// class RtkReciever : public QObject
// {
//     Q_OBJECT
// public:
//     explicit RtkReciever(QObject* parent = nullptr);
//     ~RtkReciever();

//     void start();
//     void stop();
//     bool isActive();

// signals: // A signal is automatically emitted when the value of a QML property changes
//     void rawMessageReceived(const QByteArray& msg);
//     void activeChanged(bool active); // used to notify if the receiver’s active state has changed

// private slots: // Slots are used to trigger C++ code from QML
//     void onReadyRead(); // used to react to incoming UDP data when it arrives on the socket

// private:
//     QUdpSocket socket_; // Receives incoming UDP packets and emits readyRead() when data arrives
//     QElapsedTimer lastPacketTime_; // Measures time since the last received packet and resets every time onReadyRead() runs
//     QTimer activityTimer_; // checks if the receiver is still active
//     bool active_ = false; // current state of the receiver
// };
