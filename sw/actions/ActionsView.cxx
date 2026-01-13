#include <actions/ActionsView.h>
#include <LmCdl/I_VcsiApplicationApi.h>
#include <LmCdl/I_QmlApi.h>
#include <QQuickWidget>
#include <QQmlContext>

ActionsView::ActionsView(LmCdl::I_QmlApi& qmlApi, LmCdl::I_VcsiApplicationApi& vcsiApplicationApi)
    : qmlApi_(qmlApi), vcsiApplicationApi_(vcsiApplicationApi)
{
    QQuickWidget* widget = new QQuickWidget(&qmlApi_.qmlEngine(), nullptr);
    widget->setSource(QUrl("qrc:/suav/actions/Actions.qml"));
    widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
}

ActionsView::~ActionsView() = default;