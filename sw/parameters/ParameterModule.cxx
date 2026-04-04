#include "ParameterModule.h"

#include <iostream>

ParameterModule::ParameterModule(MavlinkConnection& mavlinkConnection, QObject* parent)
    : QObject(parent)
    , mavlinkConnection_(mavlinkConnection)
    , parameterManager_(std::make_unique<ParameterManager>(":/suav/parameters/apm.pdef.json"))
    , parameterItemModel_(std::make_unique<parameter_item_model>(parameterManager_->get_parameters()))
    , parameterFilterProxy_(std::make_unique<ParameterFilterProxy>(this))
{
    if (!parameterManager_->load()) {
        std::cerr << "[ParameterModule] Failed to load parameters (file missing or invalid)." << std::endl;
    } else {
        std::cout << "[ParameterModule] Parameters loaded successfully." << std::endl;
    }
    parameterItemModel_->reload();
    parameterFilterProxy_->setSourceModel(parameterItemModel_.get());
}

ParameterModule::~ParameterModule() = default;

QAbstractItemModel* ParameterModule::parameterModel() const {
    return parameterFilterProxy_.get();
}

QString ParameterModule::parameterFilter() const {
    return parameterFilterProxy_->filterText();
}

void ParameterModule::setParameterFilter(const QString& text) {
    if (parameterFilterProxy_->filterText() == text) return;
    parameterFilterProxy_->setFilterText(text);
    emit parameterFilterChanged();
}

void ParameterModule::setValue(int index, double value) {
    const int sourceRow = parameterFilterProxy_->sourceRow(index);
    if (sourceRow >= 0)
        parameterItemModel_->setPendingValue(sourceRow, static_cast<float>(value));
}

void ParameterModule::send(int index) {
    const int sourceRow = parameterFilterProxy_->sourceRow(index);
    if (sourceRow < 0) return;

    const QString id = parameterItemModel_->idAt(sourceRow);
    const double value = static_cast<double>(parameterItemModel_->pendingValueAt(sourceRow));

    auto passthrough = mavlinkConnection_.mavlinkPassthrough();
    if (!passthrough) {
        qWarning() << "ParameterModule: Cannot send. Drone not connected.";
        return;
    }

    char param_id[16] = {0};
    const QByteArray idBytes = id.toUtf8();
    std::strncpy(param_id, idBytes.constData(), sizeof(param_id) - 1);

    const uint8_t param_type = MAV_PARAM_TYPE_REAL32; //change if mavlink model already contains type info

    mavlink_message_t msg;

    const uint8_t target_system = 1; //assuming mavlink vehicle ID is 1
    const uint8_t target_component = 1; //assuming flight controller ID is 1
    const uint8_t src_system = 255; //assuming GCS ID is 255
    const uint8_t src_component = 190; //assuming sender ID is 190

    mavlink_msg_param_set_pack(
        src_system, src_component, &msg,
        target_system, target_component,
        param_id,
        value,
        param_type
    );

    qDebug() << "Sending PARAM_SET"
        << "id:" << id
        << "value:" << value
        << "type:" << param_type;

    passthrough->send_message(msg);

    emit parameterSendRequested(id, value);
}