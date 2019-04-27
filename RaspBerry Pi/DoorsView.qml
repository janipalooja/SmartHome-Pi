import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4

Item {

    TopBar {
        title: "Ovien lukitus"
    }

    Column {

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 75
        spacing: 10

        Row {
            spacing: 10
            SquareButton {
                doorLocked: true
                buttonTitle: "Etuovi"
                buttonImage: "images/switch_off.png"
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        parent.lockSwitchToggle();
                    }
                }
            }
            SquareButton {
                doorLocked: true
                buttonTitle: "Takaovi"
                buttonImage: "images/switch_off.png"
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        parent.lockSwitchToggle();
                    }
                }
            }
            }

        }

    }


