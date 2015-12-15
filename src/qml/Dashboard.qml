import QtQuick 2.0

import "constants.js" as Consts
import "components"

Item {
    id: dashboard

    width: Consts.ScreenWidth
    height: Consts.ScreenHeight

    property alias model: dashboardView.model

    state: "Default"

    states: [
        State {
            name: "Default"
            PropertyChanges { target: addButton; visible: true }
            PropertyChanges { target: taskContext; visible: false }
        },
        State {
            name: "Context"
            PropertyChanges { target: addButton; visible: false }
            PropertyChanges { target: taskContext; visible: true }
        }
    ]

    ListView {
        id: dashboardView

        anchors.fill: parent

        header: Rectangle {
            width: dashboardView.width
            height: dashboardView.height / 6

            color: Consts.MainColorDark

            Rectangle {
                id: rectangle1
                width: dashboard.width / 10
                height: width
                color: "#00000000"
                anchors.left: parent.left
                anchors.leftMargin: 30
                anchors.verticalCenter: parent.verticalCenter

                Image {
                    width: dashboard.width / 25
                    height: width

                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter

                    source: "qrc:/icons/resources/icons/align_just_icon.png"
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: { sidebarRectangle.state = "Show" }
                }
            }

            Rectangle {
                width: parent.width / 25
                height: width
                color: "#00000000"
                anchors.right: parent.right
                anchors.rightMargin: 50
                anchors.verticalCenter: parent.verticalCenter

                Image {
                    anchors.fill: parent
                    source: "qrc:/icons/resources/icons/zoom_icon.png"
                }
            }

            Text {
                id: text2
                color: "#f1eeee"
                text: qsTr("BEST Category")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.left: parent.left
                anchors.leftMargin: 100
                anchors.verticalCenter: parent.verticalCenter
                font.bold: true
                font.family: "Arial"
                font.pixelSize: 39
            }

        }

        delegate: Component {
            TaskDelegate {
                id : taskDelegate
                width: dashboard.width
                showContantHeight: dashboard.height / 2.3
                hideContantHeight: dashboard.height / 8

                onTaskClicked: {
                    if(dashboard.state != "Default")
                        dashboard.state = "Default"

                }

                onTaskPressedAndHold: {
                    dashboard.state = "Context"
                }
            }
        }
    }

    AddButton {
        id: addButton
        diameter: dashboard.width / 4.8

        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 20;
        anchors.right: parent.right;
        anchors.rightMargin: 20

        onClicked: {
            coreEngine.addTask("NewTask", 1, "yesterday", "lol :D");
        }
    }

    ContextMenu {
        id: taskContext

        width: dashboard.width
        height: dashboard.height / 8

        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 20;

        onEditTaskClicked: {
            taskEditWindow.visible = true
        }

        onDeleteTaskClicked: {
            coreEngine.removeTask(0)
            dashboard.state = "Default"
        }
    }

}
