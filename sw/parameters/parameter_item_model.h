#pragma once

#include <QAbstractItemModel>
#include <QVariant>
#include <QModelIndex>
#include "parameter.h"

class parameter_item_model : public QAbstractItemModel {
    Q_OBJECT
public:
    explicit parameter_item_model(std::vector<Parameter> &parameters);
    virtual ~parameter_item_model();
    

    // Required overrides
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Optional overrides
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

private:
    // You can add a data structure here to hold your parameters
    std::vector<Parameter> &parameters_;

};
