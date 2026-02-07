#include "ParameterModule.h"

#include <iostream>

ParameterModule::ParameterModule(QObject* parent)
    : QObject(parent)
    , parameterManager_(std::make_unique<ParameterManager>(":/suav/parameters/apm.pdef.json"))
    , parameterItemModel_(std::make_unique<parameter_item_model>(parameterManager_->get_parameters()))
{
}

void ParameterModule::loadParameters()
{
    if (!parameterManager_->load()) {
        std::cerr << "[ParameterModule] Failed to load parameters (file missing or invalid)." << std::endl;
    } else {
        std::cout << "[ParameterModule] Parameters loaded successfully." << std::endl;
    }
    parameterItemModel_->reload();
}

ParameterModule::~ParameterModule() = default;

QAbstractItemModel* ParameterModule::parameterModel() const {
    return parameterItemModel_.get();
}

void ParameterModule::setValue(int index, double value) {
    parameterItemModel_->setPendingValue(index, static_cast<float>(value));
}

void ParameterModule::send(int index) {
    const QString id = parameterItemModel_->idAt(index);
    const double value = static_cast<double>(parameterItemModel_->pendingValueAt(index));
    emit parameterSendRequested(id, value);
}