import QtQuick 2.0

import "constants.js" as Consts

Rectangle {
    id: sidebarRectangle
    // For designer (480 x 800)
    // Replace all applicationWindow vaules
    /*
    property int maxWidth: 480
    property int minWidth: 0

    height: 800
    width: minWidth
*/
    property int maxWidth: applicationWindow.width
    property int minWidth: 0

    height: applicationWindow.height
    width: minWidth

    state: "Hide"

    MouseArea {
        anchors.fill: parent
        onClicked: {
            parent.state = "Hide"
        }
    }

    SidebarHeader{ id: sidebarHeader }

    states: [
        State {
            name: "Show"
            PropertyChanges {
                target: sidebarRectangle
                width: maxWidth
            }
        },
        State {
            name: "Hide"
            PropertyChanges {
                target: sidebarRectangle
                width: minWidth
            }
        }
    ]

    transitions: [
        Transition {
            from: "Show"
            to: "Hide"
            PropertyAnimation {
                target: sidebarRectangle;
                property: "width";
                to: minWidth;
                duration: Consts.AnimationDuration
            }
        },
        Transition {
            from: "Hide"
            to: "Show"
            PropertyAnimation {
                target: sidebarRectangle;
                property: "width";
                to: maxWidth;
                duration: Consts.AnimationDuration
            }
        }
    ]
}

