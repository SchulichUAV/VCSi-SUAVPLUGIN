#include "parameter_filter_proxy.h"
#include "parameter_item_model.h"

ParameterFilterProxy::ParameterFilterProxy(QObject* parent)
    : QSortFilterProxyModel(parent)
{
    setFilterCaseSensitivity(Qt::CaseInsensitive);
}

void ParameterFilterProxy::setFilterText(const QString& text) {
    if (filterText_ == text) return;
    filterText_ = text;
    invalidateFilter();
    emit filterTextChanged();
}

int ParameterFilterProxy::sourceRow(int proxyRow) const {
    const QModelIndex proxyIndex = index(proxyRow, 0);
    const QModelIndex sourceIndex = mapToSource(proxyIndex);
    return sourceIndex.isValid() ? sourceIndex.row() : -1;
}

bool ParameterFilterProxy::filterAcceptsRow(int source_row, const QModelIndex& source_parent) const {
    if (filterText_.trimmed().isEmpty())
        return true;

    QAbstractItemModel* src = sourceModel();
    if (!src) return true;

    const QModelIndex rowIndex = src->index(source_row, 0, source_parent);
    const QString id = src->data(rowIndex, parameter_item_model::IdRole).toString();
    const QString name = src->data(rowIndex, parameter_item_model::NameRole).toString();
    const QString needle = filterText_.trimmed();

    return id.contains(needle, Qt::CaseInsensitive)
           || name.contains(needle, Qt::CaseInsensitive);
}
