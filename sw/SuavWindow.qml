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
                text: "udpin://0.0.0.0:14550"
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
                Layout.fillWidth: true
                text: mavlinkConnection.vehicleConnected
                    ? "Vehicle Connected"
                    : mavlinkConnection.connectionStatus === "Not connected"
                        || mavlinkConnection.connectionStatus.startsWith("Connection failed")
                        ? "Connect to Vehicle"
                        : "Listening for Vehicle"

                contentItem: Text {
                    text: connectMavlinkButton.text
                    color: "#E8EAFF"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                background: Rectangle {
                    color: mavlinkConnection.vehicleConnected
                        ? "#22C55E"
                        : mavlinkConnection.connectionStatus.startsWith("Waiting")
                            || mavlinkConnection.connectionStatus.startsWith("Starting")
                            ? "#D97706"
                            : "#EF4444"
                    radius: 12
                }

                onClicked: {
                    mavlinkConnection.connectAsync(connectionUrlInput.text)
                }
            }
        }
        Text {
            Layout.fillWidth: true
            text: mavlinkConnection.connectionStatus
            color: mavlinkConnection.vehicleConnected
                ? "#22C55E"
                : mavlinkConnection.connectionStatus.startsWith("Waiting")
                    || mavlinkConnection.connectionStatus.startsWith("Starting")
                    ? "#D97706"
                    : "#EF4444"
        }
        TextField {
                id: parameterSearch
                Layout.fillWidth: true
                Layout.preferredHeight: 40
                placeholderText: "Search by ID or display name..."
                color: "white"
                text: parameterModule.parameterFilter
                onTextChanged: parameterModule.parameterFilter = text
            }
        RowLayout {
            spacing: 8

            Item {
                Layout.fillWidth: true
                Layout.preferredHeight: 40

                Button {
                    id: startRtkButton
                    text: "Connect to RTK server"
                    enabled: mavlinkConnection.vehicleConnected
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
        TextField {
                id: parameterSearch
                Layout.fillWidth: true
                Layout.preferredHeight: 40
                placeholderText: "Search by ID or display name..."
                color: "white"
                text: parameterModule.parameterFilter
                onTextChanged: parameterModule.parameterFilter = text
            }
        ListView {
                id: paramsList
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.minimumHeight: 200
                clip: true
                spacing: 4
                model: parameterModule.parameterModel

                delegate: Rectangle {
                    width: paramsList.width
                    height: 48
                    radius: 6
                    border.width: 1
                    border.color: "#2a2a2a"
                    color: "transparent"

                    RowLayout {
                        anchors.fill: parent
                        anchors.margins: 6
                        spacing: 8

                        Text {
                            text: name
                            color: "white"
                            elide: Text.ElideRight
                            Layout.preferredWidth: 260
                            verticalAlignment: Text.AlignVCenter
                        }

                        TextField {
                            id: valueField
                            text: String(value)
                            enabled: !readOnly
                            Layout.fillWidth: true
                            Layout.preferredHeight: 36
                        }

                        Button {
                            text: "Send"
                            enabled: !readOnly
                            Layout.preferredWidth: 90
                            Layout.preferredHeight: 36
                            onClicked: {
                                parameterModule.setValue(index, Number(valueField.text))
                                parameterModule.send(index)
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
            } /// end
    }
}

