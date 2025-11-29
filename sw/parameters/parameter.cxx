#include "parameter.h"
#include <utility>
#include <unordered_map>  

Parameter::Parameter(
    std::string id,
    float value,
    ParameterType type,
    std::string description,
    std::string displayName,
    std::optional<std::string> user,
    std::optional<std::string> units,
    std::optional<bool> rebootRequired,
    std::optional<float> increment,
    std::optional<bool> readOnly,
    std::optional<int> calibration,
    std::optional<std::unordered_map<std::string, std::string>> values,
    std::optional<std::unordered_map<int, std::string>> bitmask,
    std::optional<Range> range
)
    : id_(std::move(id)),
      value_(value),
      type_(type),
      description_(std::move(description)),
      displayName_(std::move(displayName)),
      user_(std::move(user)),
      units_(std::move(units)),
      rebootRequired_(rebootRequired),
      increment_(increment),
      readOnly_(readOnly),
      calibration_(calibration),
      values_(std::move(values)),
      bitmask_(std::move(bitmask)),
      range_(range)
{}
 

Parameter::~Parameter() = default;

const std::string& Parameter::getId() const noexcept {
    return id_;
}

float Parameter::getValue() const noexcept {
    return value_;
}

ParameterType Parameter::getType() const noexcept {
    return type_;
}

const std::string& Parameter::getDescription() const noexcept {
    return description_;
}

const std::string& Parameter::getDisplayName() const noexcept {
    return displayName_;
}

const std::optional<std::string>& Parameter::getUser() const noexcept {
    return user_;
}

const std::optional<std::string>& Parameter::getUnits() const noexcept {
    return units_;
}

const std::optional<bool>& Parameter::isRebootRequired() const noexcept {
    return rebootRequired_;
}

const std::optional<float>& Parameter::getIncrement() const noexcept {
    return increment_;
}

const std::optional<bool>& Parameter::isReadOnly() const noexcept {
    return readOnly_;
}

const std::optional<int>& Parameter::getCalibration() const noexcept {
    return calibration_;
}

const std::optional<std::unordered_map<std::string, std::string>>& Parameter::getValues() const noexcept {
    return values_;
}

const std::optional<std::unordered_map<int, std::string>>& Parameter::getBitmask() const noexcept {
    return bitmask_;
}

const std::optional<Range>& Parameter::getRange() const noexcept {
    return range_;
}
