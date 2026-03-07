import QtQuick
import QtQuick.Controls
import QmlExtension 1.0
import QtQuick.Layouts

ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    title: "Suav"
    color: "#0F1117"

    ColumnLayout {
        id: mainLayout
        anchors.fill: parent
        anchors.margins: 16
        spacing: 12

        RowLayout {
            id: mavlinkConnectionLayout
            spacing: 8

            TextField {
                id: connectionUrlInput
                text: "udpin://127.0.0.1:14550"
                color: "#E8EAFF"
                placeholderText: "udpin://x.x.x.x:xxxx"
                placeholderTextColor: "#6B7299"
                Layout.fillWidth: true

                background: Rectangle {
                    color: "#1E2130"
                    border.color: connectionUrlInput.activeFocus ? "#6366F1" : "#3D4466"
                    border.width: 1
                    radius: 8
                }
            }

            Button {
                id: connectMavlinkButton
                property bool connected: false
                Layout.fillWidth: true
                text: "Connect to Vehicle"

                contentItem: Text {
                    text: connectMavlinkButton.text
                    color: "#E8EAFF"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                background: Rectangle {
                    color: connectMavlinkButton.connected ? "#22C55E" : "#EF4444"
                    radius: 12
                }

                onClicked: {
                    mavlinkConnection.connectAsync(connectionUrlInput.text)
                    connected = true
                }
            }
        }

        RowLayout {
            spacing: 8

            Item {
                Layout.fillWidth: true
                Layout.preferredHeight: 40

                Button {
                    id: startRtkButton
                    text: "Connect to RTK server"
                    enabled: connectMavlinkButton.connected
                    property bool startServer: false

                    contentItem: Text {
                        text: startRtkButton.text
                        color: startRtkButton.enabled ? "#E8EAFF" : "#6B7299"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        color: !startRtkButton.enabled
                            ? "#2D3155"
                            : startRtkButton.startServer ? "#22C55E" : "#EF4444"
                        radius: 12
                    }

                    onClicked: {
                        rtkModule.startRtkReciever()
                        startRtkButton.startServer = true
                    }
                }
            }
        }
    }
}