// parameter_item_model.cxx
#include "parameter_item_model.h"

parameter_item_model::parameter_item_model(std::vector<Parameter>& parameters, QObject* parent)
    : QAbstractListModel(parent)
    , parameters_(parameters)
{
    reload();
}

parameter_item_model::~parameter_item_model() = default;

void parameter_item_model::reload() {
    beginResetModel();

    pendingValues_.clear();
    pendingValues_.reserve(static_cast<int>(parameters_.size()));
    for (const auto& p : parameters_) {
        pendingValues_.push_back(p.getValue());
    }

    endResetModel();
}

int parameter_item_model::rowCount(const QModelIndex& parent) const {
    if (parent.isValid()) return 0;
    return static_cast<int>(parameters_.size());
}

QVariant parameter_item_model::data(const QModelIndex& index, int role) const {
    if (!index.isValid()) return {};
    const int row = index.row();
    if (row < 0 || row >= rowCount()) return {};

    const auto& p = parameters_[static_cast<size_t>(row)];

    switch (role) {
        case IdRole:
            return QString::fromStdString(p.getId());
        case NameRole: {
            const auto& dn = p.getDisplayName();
            return QString::fromStdString(dn.empty() ? p.getId() : dn);
        }
        case ValueRole:
            return pendingValues_[row];
        case ReadOnlyRole:
            return p.isReadOnly().value_or(false);
        case UnitsRole:
            return p.getUnits().has_value() ? QString::fromStdString(*p.getUnits()) : QString();
        default:
            return {};
    }
}

bool parameter_item_model::setData(const QModelIndex& index, const QVariant& value, int role) {
    if (!index.isValid()) return false;
    const int row = index.row();
    if (row < 0 || row >= rowCount()) return false;

    if (role == ValueRole) {
        bool ok = false;
        const float v = value.toFloat(&ok);
        if (!ok) return false;

        pendingValues_[row] = v;
        emit dataChanged(index, index, {ValueRole});
        return true;
    }

    return false;
}

Qt::ItemFlags parameter_item_model::flags(const QModelIndex& index) const {
    if (!index.isValid()) return Qt::NoItemFlags;

    const bool readOnly = data(index, ReadOnlyRole).toBool();
    auto f = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    if (!readOnly) f |= Qt::ItemIsEditable;
    return f;
}

QHash<int, QByteArray> parameter_item_model::roleNames() const {
    return {
        {IdRole, "id"},
        {NameRole, "name"},
        {ValueRole, "value"},
        {ReadOnlyRole, "readOnly"},
        {UnitsRole, "units"}
    };
}

void parameter_item_model::setPendingValue(int row, float v) {
    if (row < 0 || row >= rowCount()) return;
    pendingValues_[row] = v;
    const QModelIndex idx = index(row, 0);
    emit dataChanged(idx, idx, {ValueRole});
}

float parameter_item_model::pendingValueAt(int row) const {
    if (row < 0 || row >= rowCount()) return 0.0f;
    return pendingValues_[row];
}

QString parameter_item_model::idAt(int row) const {
    if (row < 0 || row >= rowCount()) return {};
    return QString::fromStdString(parameters_[static_cast<size_t>(row)].getId());
}