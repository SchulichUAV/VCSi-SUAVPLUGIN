#pragma once

#include <QObject>
#include <LmCdl/UniqueIdentifier.h>

class Vehicle;

namespace LmCdl {
class I_QmlApi;
}

class CasinoModule : public QObject {
    Q_OBJECT
public:
    explicit CasinoModule(
        LmCdl::I_QmlApi& qmlApi, Vehicle& vehicle);
    virtual ~CasinoModule();
    
private:
    LmCdl::I_QmlApi& qmlApi_;
    Vehicle& vehicle_;
};