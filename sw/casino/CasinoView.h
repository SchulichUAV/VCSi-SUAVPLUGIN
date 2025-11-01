#pragma once

#include <QObject>
#include <LmCdl/UniqueIdentifier.h>

class Vehicle;

namespace LmCdl {
class I_QmlApi;
}

class CasinoView : public QObject {
    Q_OBJECT
public:
    explicit CasinoView(
        LmCdl::I_QmlApi& qmlApi, Vehicle& vehicle);
    virtual ~CasinoView();
    
private:
    LmCdl::I_QmlApi& qmlApi_;
    Vehicle& vehicle_;
};