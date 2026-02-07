import QtQuick
import QtQuick.Controls
import QmlExtension 1.0
import QtQuick.Layouts

ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    title: "SUAV Plugin"

    ColumnLayout {
        id: mainLayout
        anchors.fill: parent
        spacing: 10

        RowLayout {
            id: mavlinkConnectionLayout
            Layout.fillWidth: true

            TextField {
                id: connectionUrlInput
                text: "udpin://127.0.0.1:14550"
                color: "white"
                placeholderText: "udpin://x.x.x.x:xxxx"
                Layout.fillWidth: true
                Layout.preferredHeight: 34
            }

            Button {
                id: connectMavlinkButton
                text: "Connect to Vehicle"
                Layout.preferredHeight: 34
                Layout.preferredWidth: 180
                onClicked: mavlinkConnection.connectAsync(connectionUrlInput.text)
            }
        }

        Button {
            id: startRtkButton
            text: "Connect to RTK server"
            Layout.preferredHeight: 34
            Layout.preferredWidth: 200
            onClicked: rtkModule.startRtkReciever()
        }

        ScrollView {
            id: paramsScroll
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumHeight: 200
            clip: true

            Column {
                id: paramsColumn
                width: paramsScroll.availableWidth
                spacing: 8

                Text {
                    text: "No parameters loaded yet."
                    color: "white"
                    visible: paramsRepeater.count === 0
                }

                Repeater {
                    model: parameterModule.parameterModel

                    delegate: Rectangle {
                        width: paramsColumn.width
                        height: 44
                        radius: 6
                        border.width: 1
                        border.color: "#2a2a2a"
                        color: "transparent"

                        RowLayout {
                            anchors.fill: parent
                            anchors.margins: 8
                            spacing: 10

                            Text {
                                text: name
                                color: "white"
                                elide: Text.ElideRight
                                Layout.preferredWidth: 260
                                Layout.fillHeight: true
                                verticalAlignment: Text.AlignVCenter
                            }

                            TextField {
                                id: valueField
                                text: String(value)
                                enabled: !readOnly
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                            }

                            Button {
                                text: "Send"
                                enabled: !readOnly
                                Layout.preferredWidth: 90
                                Layout.fillHeight: true
                                onClicked: {
                                    parameterModule.setValue(index, Number(valueField.text))
                                    parameterModule.send(index)
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}