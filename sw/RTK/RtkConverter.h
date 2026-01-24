#pragma once

#include <QObject>
#include <QByteArray>

class RtkConverter : public QObject
{
    Q_OBJECT
public:
    explicit RtkConverter();
    virtual ~RtkConverter();

};
