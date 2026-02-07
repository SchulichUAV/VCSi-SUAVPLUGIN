#pragma once

#include <QObject>
#include <QAbstractItemModel>
#include <memory>

#include "param_utils.h"
#include "parameter_item_model.h"

class ParameterModule : public QObject {
    Q_OBJECT
    Q_PROPERTY(QAbstractItemModel* parameterModel READ parameterModel CONSTANT)

public:
    explicit ParameterModule(QObject* parent = nullptr);
    ~ParameterModule() override;

    QAbstractItemModel* parameterModel() const;

    Q_INVOKABLE void setValue(int index, double value);
    Q_INVOKABLE void send(int index);

signals:
    void parameterSendRequested(QString id, double value);

private:
    std::unique_ptr<ParameterManager> parameterManager_;
    std::unique_ptr<parameter_item_model> parameterItemModel_;
};