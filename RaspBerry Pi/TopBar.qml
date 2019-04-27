import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4

Rectangle {
    id: topbar
    width: app.width
    height: 70
    color: "#1B1919"

    property string title: ""

    Button {
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 15
        width: 100
        height: 70
        background: Rectangle {
            color: "#1B1919" // 1B1919
        }

        Text {
            text: qsTr("Takaisin")
            color: "#a7d129"
            anchors.centerIn: parent
            font { family: localFont.name; pixelSize: 22; capitalization: Font.Capitalize }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                goBackViewSignal()
            }
        }
    }

    Text {
        text: qsTr(topbar.title)
        color: "#FFFFFF"
        anchors.centerIn: parent
        font { family: localFont.name; pixelSize: 30; capitalization: Font.Capitalize }
    }
}
