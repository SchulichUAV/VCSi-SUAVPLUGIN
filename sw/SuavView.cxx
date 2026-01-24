#include <SuavView.h>

#include <RTK/RtkModule.h>
#include <LmCdl/I_QmlApi.h>
#include <QQuickWidget>
#include <QQmlContext>

#include <iostream>

SuavView::SuavView(LmCdl::I_QmlApi &qmlApi, RtkModule &rtkModule)
    : qmlApi_(qmlApi)
{
    QQuickWidget *widget = new QQuickWidget(&qmlApi_.qmlEngine(), nullptr);
    widget->rootContext()->setContextProperty("rtkModule", &rtkModule);
    widget->setSource(QUrl("qrc:/suav/SuavWindow.qml"));
    widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
}

SuavView::~SuavView() = default;