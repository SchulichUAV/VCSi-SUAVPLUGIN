#include "parameter_item_model.h"


parameter_item_model::parameter_item_model(std::vector<Parameter> &parameters)
    : parameters_(parameters)  // initialize reference
{}
// Constructor
// parameter_item_model::parameter_item_model(std::vector<Parameter> &parameters){
//     // Initialize your data here if needed
//     parameters_ = parameters;
// }
// parameter_item_model::parameter_item_model(std::vector<Parameter>& parameters) 
//     : QAbstractItemModel(nullptr) {
//     // Store the reference or copy the data as needed
//     // For example, you can copy into a member variable:
//     this->parameters_ = parameters; // assuming you have a member variable
// }
// Destructor
parameter_item_model::~parameter_item_model() = default;

// Return the index for the given row and column under the given parent
QModelIndex parameter_item_model::index(int row, int column, const QModelIndex &parent) const {
    if (parent.isValid()) {
        // Flat list: no children
        return QModelIndex();
    }

    // Create a valid index for the given row and column
    return createIndex(row, column);
}

// Return the parent of a given index
QModelIndex parameter_item_model::parent(const QModelIndex &child) const {
    Q_UNUSED(child);
    // Flat list: all items are top-level, so no parent
    return QModelIndex();
}

// Return the number of rows under the given parent
int parameter_item_model::rowCount(const QModelIndex &parent) const {
    if (parent.isValid()) {
        // Flat list: no children
        return 0;
    }

    // Replace 0 with the actual number of parameters you have
    return 0;
}

// Return the number of columns for the given parent
int parameter_item_model::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    // For simplicity, 1 column
    return 2;
}

// Return the data for a given index and role
QVariant parameter_item_model::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) {
        return QVariant();
    }

    if (role == Qt::DisplayRole) {
        // Replace with actual parameter data
        return QString("Parameter %1").arg(index.row());
    }

    return QVariant();
}

// Return the header data for columns or rows
QVariant parameter_item_model::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    if (orientation == Qt::Horizontal) {
        if (orientation == 0) {
            return QString("ParameterName");
    }
        if (orientation == 1){
            return QString("Value");
    }
    }
    

    return QVariant();
}
