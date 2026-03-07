#include <SuavView.h>

#include <RTK/RtkModule.h>
#include <messaging/MavlinkConnection.h>
#include <LmCdl/I_QmlApi.h>
#include <QQuickWidget>
#include <QQmlContext>
#include "parameters/ParameterModule.h"

#include <QQmlEngine>
#include <QQmlError>
#include <QDebug>

#include <iostream>

SuavView::SuavView(LmCdl::I_QmlApi &qmlApi, RtkModule &rtkModule, MavlinkConnection &mavlinkConnection, ParameterModule &parameterModule)
    : qmlApi_(qmlApi)
{
    QQuickWidget *widget = new QQuickWidget(&qmlApi_.qmlEngine(), nullptr);
    QObject::connect(
    widget->engine(),
    &QQmlEngine::warnings,
    widget,
    [](const QList<QQmlError>& warnings)
    {
        for (const auto& w : warnings)
            qWarning().noquote() << w.toString();
    });

    widget->rootContext()->setContextProperty("mavlinkConnection", &mavlinkConnection);
    widget->rootContext()->setContextProperty("parameterModule", &parameterModule);
    widget->rootContext()->setContextProperty("rtkModule", &rtkModule);
    widget->setSource(QUrl("qrc:/suav/SuavWindow.qml"));
    if (widget->status() == QQuickWidget::Error)
    {
        qCritical() << "QML FAILED TO LOAD";
        for (const auto& e : widget->errors())
            qCritical().noquote() << e.toString();
    }
    widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
}

SuavView::~SuavView() = default;