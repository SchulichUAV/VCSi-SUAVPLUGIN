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

        Button {
            id: startRtkButton

            text: "Connect to RTK server"
            onClicked: {
                rtkModule.startRtkReciever()
            }
        }
    }

}
