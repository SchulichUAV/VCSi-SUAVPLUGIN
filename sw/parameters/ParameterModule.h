#pragma once

#include <QObject>
#include <QAbstractItemModel>
#include <QString>
#include <memory>

#include "param_utils.h"
#include "parameter_filter_proxy.h"
#include "parameter_item_model.h"
#include <messaging/MavlinkConnection.h>

class ParameterModule : public QObject {
    Q_OBJECT
    Q_PROPERTY(QAbstractItemModel* parameterModel READ parameterModel CONSTANT)
    Q_PROPERTY(QString parameterFilter READ parameterFilter WRITE setParameterFilter NOTIFY parameterFilterChanged)

public:
    explicit ParameterModule(MavlinkConnection& mavlinkConnection, QObject* parent = nullptr);
    ~ParameterModule() override;
    QAbstractItemModel* parameterModel() const;
    QString parameterFilter() const;
    void setParameterFilter(const QString& text);

    Q_INVOKABLE void setValue(int index, double value);
    Q_INVOKABLE void send(int index);

signals:
    void parameterSendRequested(QString id, double value);
    void parameterFilterChanged();

private:
    std::unique_ptr<ParameterManager> parameterManager_;
    std::unique_ptr<parameter_item_model> parameterItemModel_;
    std::unique_ptr<ParameterFilterProxy> parameterFilterProxy_;
    MavlinkConnection& mavlinkConnection_;
};