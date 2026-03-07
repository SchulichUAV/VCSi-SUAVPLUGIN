#include "ParameterModule.h"

#include <iostream>

ParameterModule::ParameterModule(QObject* parent)
    : QObject(parent)
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
    emit parameterSendRequested(id, value);
}