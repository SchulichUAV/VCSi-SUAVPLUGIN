#pragma once

#include <QObject>

class CasinoView;
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

    std::unique_ptr<CasinoView> casinoView_; 
};