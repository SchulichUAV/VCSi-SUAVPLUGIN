import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: actionsPanel
    implicitWidth: 400
    implicitHeight: 300

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
            onClicked: actionsPanel.handleAction(loiterButton)
        }

        Button {
            id: returnToLaunch
            text: "Return_To_Launch"
            onClicked: actionsPanel.handleAction(returnToLaunch)
        }

        Button {
            id: preflightCalibration
            text: "Preflight_Calibration"
            onClicked: actionsPanel.handleAction(preflightCalibration)
        }

        Button {
            id: preflightRebootShutdown
            text: "Preflight_Reboot_shutdown"
            onClicked: actionsPanel.handleAction(preflightRebootShutdown)
        }

        Button {
            id: batteryReset
            text: "Battery_Reset"
            onClicked: actionsPanel.handleAction(batteryReset)
        }
    }
}
