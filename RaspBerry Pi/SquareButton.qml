import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4

    Button {
        id: squareButton
        property int buttonTextSize: 10
        property string buttonTextColor: "#a7d129" //#ff7517
        property int buttonTextBottomMargin: 25
        property string buttonBackgroundColor: "#222222" //#3e3939
        property int buttonImageTopMargin: 25
        property int buttonSize: 125
        property int buttonRadius: 0
        property string buttonBorderColor: "#181818"
        property int buttonBorderWidth: 2

        property string buttonTitle
        property string buttonImage
        property bool lightsOn
        property bool doorLocked

        function lightSwitchToggle() {
            if(lightsOn){
                lightsOn = false;
                buttonImage = "images/switch_off.png";
            }
            else {
                lightsOn = true;
                buttonImage = "images/switch_on.png";
            }
        }

        function lockSwitchToggle() {
            if(doorLocked){
                doorLocked = false;
                buttonImage = "images/switch_on.png";
            }
            else {
                doorLocked = true;
                buttonImage = "images/switch_off.png";
            }
        }

        width: buttonSize
        height: 125
        background: Rectangle {
            color: parent.buttonBackgroundColor
            radius: parent.buttonRadius
            border.color: parent.buttonBorderColor
            border.width: parent.buttonBorderWidth
        }
        Text {
            text: parent.buttonTitle
            color: parent.buttonTextColor
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: 25
            font { family: localFont.name; pixelSize: 15; capitalization: Font.Capitalize }
        }
        Image {
            source: parent.buttonImage
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: parent.buttonImageTopMargin
        }

    }
