import QtQuick
import QtQuick.Controls
import QmlExtension 1.0

ApplicationWindow {
    id: window
    width: 400
    height: 300
    visible: true
    title: "actions"

    function idHandler(id){
        if(id == loiterButton){
            //pass
        }
        elif(id == returnToLaunch){
            //pass
        }
        elif(id == preflightCalibration){
            //pass
        }
        elif(id == prefligthRebootShutdown){
            //pass
        }
        elif(id == batteryReset){
            //pass
        }
    }

    RowLayout {
        anchors.fill: parent // Make the RowLayout fill the parent window
        spacing: 10 // Add 10 pixels of spacing between buttons
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter // Center the buttons horizontally and vertically within the layout

        Button {
            id: loiterButton
            text: "Loiter_Unlim"
            onClicked: console.log("Loiter_Unlim clicked")
            // Optional: Set specific size constraints for the button
            // Layout.preferredWidth: 100
            // Layout.preferredHeight: 40
        }

        Button {
            id: returnToLaunch
            text: "Return_To_Launch"
            onClicked: console.log("Return_To_Launch clicked")
        }

        Button {
            id: preflightCalibration
            text: "Preflight_Calibration"
            onClicked: console.log("Preflight_Calibration clicked")
        }
        Button {
            id: prefligthRebootShutdown
            text: "Preflight_Reboot_shutdown"
            onClicked: console.log("Preflight_Reboot_shutdown clicked")
        }
        Button {
            id: batteryReset
            text: "Battery_Reset"
            onClicked: console.log("Battery_Reset clicked")
        }

    }



      
} 