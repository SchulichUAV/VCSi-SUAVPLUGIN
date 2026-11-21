#pragma once

#include <LmCdl/I_Plugin.h>
#include <LmCdl/UniqueIdentifier.h>
#include <QObject>
#include <memory>


class SuavPluginContent;
namespace LmCdl
{
    class I_QmlApi;
    class I_VehicleCollectionApi;
    class I_VcsiApplicationApi;
}

class SuavPlugin : public QObject, public LmCdl::I_Plugin
{
    Q_OBJECT
    Q_INTERFACES(LmCdl::I_Plugin)
    Q_PLUGIN_METADATA(IID "LMCDL.Plugin.I_Plugin/1.0")

public:
    explicit SuavPlugin();
    ~SuavPlugin();

    QList<LmCdl::PluginRequirement> requiredApis() const override;
    LmCdl::PluginCapabilityIdentifier providedApi() const override;
    bool setRequiredApi(LmCdl::PluginCapabilityIdentifier id, QObject *api) override;
    QObject *getProvidedApi() override;
    bool isFullyInitialized() const override;

private:
    void startPluginIfInitialized();

private:
    LmCdl::I_VehicleCollectionApi* collectionApi_;
    LmCdl::I_QmlApi* qmlApi_;
    LmCdl::I_VcsiApplicationApi* vcsiApplicationApi_;

    std::unique_ptr<SuavPluginContent> content_; 
};
