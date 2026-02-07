#pragma once

#include <QSortFilterProxyModel>
#include <QString>

class parameter_item_model;

class ParameterFilterProxy : public QSortFilterProxyModel {
    Q_OBJECT
    Q_PROPERTY(QString filterText READ filterText WRITE setFilterText NOTIFY filterTextChanged)

public:
    explicit ParameterFilterProxy(QObject* parent = nullptr);

    QString filterText() const { return filterText_; }
    void setFilterText(const QString& text);

    Q_INVOKABLE int sourceRow(int proxyRow) const;

signals:
    void filterTextChanged();

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex& source_parent) const override;

private:
    QString filterText_;
};
