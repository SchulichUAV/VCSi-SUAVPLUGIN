import QtQuick
import QtQuick.Controls
import QmlExtension 1.0



import QtQuick 2.15
import QtQuick.Controls 2.15

ListView {
    width: 400
    height: 600

    model: parameters.list

    delegate: Rectangle {
        width: parent.width
        height: 70
        color: "#222"
        radius: 6
        border.color: "#444"

        Column {
            anchors.fill: parent
            anchors.margins: 8
            spacing: 4

            Row {
                spacing: 10
                Text {
                    text: displayName
                    font.bold: true
                    color: "white"
                }
                Text {
                    text: units
                    color: "#aaa"
                }
            }

            Slider {
                from: 0
                to: 100
                value: value
                onValueChanged: value = this.value
            }
        }

        ToolTip.visible: hovered
        ToolTip.text: description
    }
}
