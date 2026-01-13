import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QmlExtension 1.0

ApplicationWindow {
    id: window
    width: 400
    height: 300
    visible: true
    title: "actions"

    function handleAction(btn) {
        if (btn === loiterButton) {
            console.log("do loiter")
        } else if (btn === returnToLaunch) {
            console.log("do RTL")
        } else if (btn === preflightCalibration) {
            console.log("do preflight calibration")
        } else if (btn === preflightRebootShutdown) {
            console.log("do reboot/shutdown")
        } else if (btn === batteryReset) {
            console.log("do battery reset")
        }
    }

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 10

        Button {
            id: loiterButton
            text: "Loiter_Unlim"
            onClicked: handleAction(loiterButton)
        }

        Button {
            id: returnToLaunch
            text: "Return_To_Launch"
            onClicked: handleAction(returnToLaunch)
        }

        Button {
            id: preflightCalibration
            text: "Preflight_Calibration"
            onClicked: handleAction(preflightCalibration)
        }

        Button {
            id: preflightRebootShutdown
            text: "Preflight_Reboot_shutdown"
            onClicked: handleAction(preflightRebootShutdown)
        }

        Button {
            id: batteryReset
            text: "Battery_Reset"
            onClicked: handleAction(batteryReset)
        }
    }
}
