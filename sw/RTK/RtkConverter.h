#pragma once

#include <QObject>
#include <QByteArray>

class RtkConverter : public QObject
{
    Q_OBJECT
public:
    explicit RtkConverter(QObject* parent = nullptr);
    ~RtkConverter();

signals:
    void positionUpdated(double lat, double lon, double alt);

public slots:
    void processRawMessage(const QByteArray& msg);
};
