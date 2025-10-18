#ifndef PARAMETER_HXX
#define PARAMETER_HXX

#include <string>
#include <optional>
#include <unordered_map>

struct Range {
    float low{};
    float high{};
    bool contains(float x) const noexcept { return x >= low && x <= high; }
};

enum class ParameterType : int {
    UNKNOWN = 0,
    MAV_PARAM_TYPE_UINT8 = 1,
    MAV_PARAM_TYPE_INT8 = 2,
    MAV_PARAM_TYPE_UINT16 = 3,
    MAV_PARAM_TYPE_INT16 = 4,
    MAV_PARAM_TYPE_UINT32 = 5,
    MAV_PARAM_TYPE_INT32 = 6,
    MAV_PARAM_TYPE_UINT64 = 7,
    MAV_PARAM_TYPE_INT64 = 8,
    MAV_PARAM_TYPE_REAL32 = 9,
    MAV_PARAM_TYPE_REAL64 = 10,
};

class Parameter {
public:
    Parameter(
        std::string id,
        float value,
        ParameterType type,
        std::string description,
        std::string displayName,
        std::optional<std::string> user = std::nullopt,
        std::optional<std::string> units = std::nullopt,
        std::optional<bool> rebootRequired = std::nullopt,
        std::optional<float> increment = std::nullopt,
        std::optional<bool> readOnly = std::nullopt,
        std::optional<int> calibration = std::nullopt,
        std::optional<std::unordered_map<int, std::string>> values = std::nullopt,
        std::optional<std::unordered_map<int, std::string>> bitmask = std::nullopt,
        std::optional<Range> range = std::nullopt
    );

    [[nodiscard]] const std::string& getId() const noexcept;
    [[nodiscard]] float getValue() const noexcept;
    [[nodiscard]] ParameterType getType() const noexcept;
    [[nodiscard]] const std::string& getDescription() const noexcept;
    [[nodiscard]] const std::string& getDisplayName() const noexcept;

    [[nodiscard]] const std::optional<std::string>& getUser() const noexcept;
    [[nodiscard]] const std::optional<std::string>& getUnits() const noexcept;
    [[nodiscard]] const std::optional<bool>& isRebootRequired() const noexcept;
    [[nodiscard]] const std::optional<float>& getIncrement() const noexcept;
    [[nodiscard]] const std::optional<bool>& isReadOnly() const noexcept;
    [[nodiscard]] const std::optional<int>& getCalibration() const noexcept;
    [[nodiscard]] const std::optional<std::unordered_map<int, std::string>>& getValues() const noexcept;
    [[nodiscard]] const std::optional<std::unordered_map<int, std::string>>& getBitmask() const noexcept;
    [[nodiscard]] const std::optional<Range>& getRange() const noexcept;
    
private:
    std::string id_;
    float value_{};
    ParameterType type_{ParameterType::UNKNOWN};
    std::string description_;
    std::string displayName_;

    std::optional<std::string> user_;
    std::optional<std::string> units_;
    std::optional<bool> rebootRequired_;
    std::optional<float> increment_;
    std::optional<bool> readOnly_;
    std::optional<int> calibration_;
    std::optional<std::unordered_map<int, std::string>> values_;
    std::optional<std::unordered_map<int, std::string>> bitmask_;
    std::optional<Range> range_;
};

#endif