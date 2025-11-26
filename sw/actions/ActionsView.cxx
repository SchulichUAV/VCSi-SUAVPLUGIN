#include <actions/ActionsView.h>

#include <LmCdl/I_QmlApi.h>
#include <QQuickWidget>
#include <QQmlContext>

CasinoView::CasinoView(LmCdl::I_QmlApi& qmlApi, Vehicle& vehicle)
    : qmlApi_(qmlApi)
{
    QQuickWidget* widget = new QQuickWidget(&qmlApi_.qmlEngine(), nullptr);
    widget->setSource(QUrl("qrc:/suav/actions/Actions.qml"));
    widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
}

CasinoView::~CasinoView() = default;