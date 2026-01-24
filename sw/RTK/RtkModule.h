#pragma once

#include <QObject>

class RtkReciever;
class RtkConverter;
class MavlinkConnection;

class RtkModule : public QObject
{
    Q_OBJECT
public:
    explicit RtkModule(MavlinkConnection &mavlinkConnection);
    virtual ~RtkModule();

    Q_INVOKABLE void startRtkReciever();

private:
    std::unique_ptr<RtkReciever> rtkReciever_;
    std::unique_ptr<RtkConverter> rtkConverter_;
};