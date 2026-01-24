#pragma once

#include <QObject>
#include <QByteArray>

class MavlinkConnection;
class RtkReciever;

class RtkConverter : public QObject
{
    Q_OBJECT
public:
    explicit RtkConverter(RtkReciever &rtkReciever, MavlinkConnection &mavlinkConnection);
    virtual ~RtkConverter();

    void processRawMessage(const QByteArray &msg);
private:
    MavlinkConnection &mavlinkConnection_;
};
