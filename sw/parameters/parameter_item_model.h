// parameter_item_model.h
#pragma once

#include <QAbstractListModel>
#include <QVector>
#include <QString>
#include <vector>

#include "parameter.h"

class parameter_item_model : public QAbstractListModel {
    Q_OBJECT

public:
    enum Roles : int {
        IdRole = Qt::UserRole + 1,
        NameRole,
        ValueRole,
        ReadOnlyRole,
        UnitsRole
    };

    explicit parameter_item_model(std::vector<Parameter>& parameters, QObject* parent = nullptr);
    ~parameter_item_model() override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QHash<int, QByteArray> roleNames() const override;

    void reload();

    void setPendingValue(int row, float v);
    float pendingValueAt(int row) const;
    QString idAt(int row) const;

private:
    std::vector<Parameter>& parameters_;
    QVector<float> pendingValues_;
};