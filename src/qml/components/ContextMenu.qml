import QtQuick 2.0

import "../constants.js" as Consts

Rectangle {
    id: contextMenu

    property bool showCompleteButton: true

    signal completeTaskClicked()
    signal editTaskClicked()
    signal deleteTaskClicked()

    width: Consts.ScreenWidth
    height: Consts.ScreenHeight / 10
    color: Consts.MainColorLight

    border.color: "white"
    border.width: Consts.ScreenWidth /96

    Row {
        anchors.fill: parent

        MouseArea {
            height: showCompleteButton ? contextMenu.height : 0
            width: showCompleteButton ? contextMenu.width / 3 : 0
            Image {
                anchors.centerIn: parent
                visible: showCompleteButton
                source: "qrc:/icons/resources/icons/checkmark_icon.png"
            }
            onClicked: { completeTaskClicked() }
        }

        MouseArea {
            height: contextMenu.height
            width: showCompleteButton ? contextMenu.width / 3 : contextMenu.width / 2
            Image {
                anchors.centerIn: parent
                source: "qrc:/icons/resources/icons/pencil_icon.png"
            }
            onClicked: { editTaskClicked() }
        }

        MouseArea {
            height: contextMenu.height
            width: showCompleteButton ? contextMenu.width / 3 : contextMenu.width / 2
            Image {
                anchors.centerIn: parent
                source: "qrc:/icons/resources/icons/delete_icon.png"
            }
            onClicked: { deleteTaskClicked() }
        }
    }
}

