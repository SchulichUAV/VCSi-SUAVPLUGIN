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


    ColumnLayout {
        id: mainLayout
        anchors.fill: parent


        RowLayout {
            id: mavlinkConnectionLayout
            TextField {
                id: connectionUrlInput
                text: "udpin://127.0.0.1:14550"
                color: "white"
                placeholderText: "udpin://x.x.x.x:xxxx"
                Layout.fillWidth: true

            }
            Button {
                id: connectMavlinkButton

                Layout.fillWidth: true

                text: "Connect to Vehicle"
                onClicked: {
                    mavlinkConnection.connectAsync(connectionUrlInput.text)
                }
            }
        }

        Button {
            id: startRtkButton

            text: "Connect to RTK server"
            onClicked: {
                rtkModule.startRtkReciever()
            }
        }
        
        Row {
            Repeater {
                model: parameterModule.parameterListModel()
                delegate: Rectangle {

                }
            }
        }
    }

}
