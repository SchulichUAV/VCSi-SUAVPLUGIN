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
        anchors.margins: 10
        spacing: 10

        RowLayout {
            id: mavlinkConnectionLayout
            Layout.fillWidth: true
            spacing: 8

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

        Rectangle {
            id: paramsContainer
            Layout.fillWidth: true
            Layout.fillHeight: true
            radius: 10
            border.width: 1
            border.color: "#2a2a2a"
            color: "transparent"

            property int pad: 10
            property int scrollGutter: 18

            ListView {
                id: paramsList
                anchors.fill: parent
                anchors.leftMargin: paramsContainer.pad
                anchors.topMargin: paramsContainer.pad
                anchors.bottomMargin: paramsContainer.pad
                anchors.rightMargin: paramsContainer.pad + paramsContainer.scrollGutter
                clip: true
                spacing: 8

                model: parameterModule.parameterModel

                ScrollBar.vertical: ScrollBar {
                    width: paramsContainer.scrollGutter
                    x: paramsList.width + paramsContainer.pad
                    y: 0
                    height: paramsList.height
                    policy: ScrollBar.AlwaysOn
                }

                delegate: Rectangle {
                    width: paramsList.width
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

            Text {
                anchors.centerIn: parent
                text: "No parameters loaded."
                color: "white"
                visible: paramsList.count === 0
            }
        }
    }
}