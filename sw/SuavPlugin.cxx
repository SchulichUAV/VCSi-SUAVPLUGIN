#include <SuavPlugin.h>

#include <LmCdl/I_VehicleCollectionApi.h>
#include <LmCdl/I_QmlApi.h>
#include <LmCdl/I_VcsiWidgetExtensionApi.h>
#include <LmCdl/I_VcsiApplicationApi.h>
#include <LmCdl/PluginCapabilityIdentifier.h>
#include <LmCdl/PluginRequirement.h>
#include <SuavPluginContent.h>
#include <QList>

SuavPlugin::SuavPlugin()
    : collectionApi_(nullptr)
    , qmlApi_(nullptr)
    , vcsiApplicationApi_(nullptr)
{
}

SuavPlugin::~SuavPlugin() = default;

QList<LmCdl::PluginRequirement> SuavPlugin::requiredApis() const
{
    return {LmCdl::PluginRequirement(VEHICLE_COLLECTION_API_CAPABILITY_NAME, 1, 0, 0),
            LmCdl::PluginRequirement(QML_API_CAPABILITY_NAME, 1, 0, 0),
            LmCdl::PluginRequirement(VCSI_APPLICATION_API_CAPABILITY_NAME, 1, 0, 0)};
}

LmCdl::PluginCapabilityIdentifier SuavPlugin::providedApi() const
{
    return LmCdl::PluginCapabilityIdentifier::noCapability();
}

bool SuavPlugin::setRequiredApi(LmCdl::PluginCapabilityIdentifier id, QObject *api)
{
    bool capabilityFound = false;
    if (id.capabilityName() == VEHICLE_COLLECTION_API_CAPABILITY_NAME)
    {
        collectionApi_ = dynamic_cast<LmCdl::I_VehicleCollectionApi *>(api);
        capabilityFound = true;
    }
    if (id.capabilityName() == QML_API_CAPABILITY_NAME)
    {
        qmlApi_ = dynamic_cast<LmCdl::I_QmlApi *>(api);
        capabilityFound = true;
    }
    if (id.capabilityName() == VCSI_APPLICATION_API_CAPABILITY_NAME)
    {
        vcsiApplicationApi_ = dynamic_cast<LmCdl::I_VcsiApplicationApi *>(api);
        capabilityFound = true;
    }

    startPluginIfInitialized();
    return capabilityFound;
}

QObject *SuavPlugin::getProvidedApi() { return nullptr; }

bool SuavPlugin::isFullyInitialized() const { return (collectionApi_ && qmlApi_ && vcsiApplicationApi_); }

void SuavPlugin::startPluginIfInitialized()
{
    if (isFullyInitialized())
    {
        content_ = std::make_unique<SuavPluginContent>(*collectionApi_, *qmlApi_, *vcsiApplicationApi_);
    }
}
