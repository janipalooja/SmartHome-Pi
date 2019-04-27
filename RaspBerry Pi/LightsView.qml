import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4

Item {

    TopBar {
        title: "Valaistus"
    }

    Column {
        id: col
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 115
        spacing: 10

        Row {
            spacing: 10
            SquareButton {
                id: lightswitch1
                lightsOn: false
                buttonTitle: "Eteinen"
                buttonImage: "images/switch_off.png"
                function serialToggle(){
                    if(serial.lightswitch1_state === 0){
                        lightsOn = false;
                        buttonImage = "images/switch_off.png";
                    }
                    else {
                        lightsOn = true;
                        buttonImage = "images/switch_on.png";
                    }
                }
                MouseArea {
                    id: mouse
                    anchors.fill: parent
                    onClicked: {
                        parent.lightSwitchToggle();
                        console.log("1;1;"+lightswitch1.lightsOn);
                        serial.writeSerial(1); // Eteinen, keltainen
                    }
                }

                Component.onCompleted: {
                    lightswitch1.serialToggle();
                }

            }
            SquareButton {
                id: lightswitch2
                lightsOn: false
                buttonTitle: "Keittiö"
                buttonImage: "images/switch_off.png"
                function serialToggle(){
                    if(serial.lightswitch2_state === 0){
                        lightsOn = false;
                        buttonImage = "images/switch_off.png";
                    }
                    else {
                        lightsOn = true;
                        buttonImage = "images/switch_on.png";
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        parent.lightSwitchToggle();
                        serial.writeSerial(2); // Keittiö, sininen
                    }
                }
                Component.onCompleted: {
                    lightswitch2.serialToggle();
                }
            }
            }
        Row {
            spacing: 10
            SquareButton {
                id: lightswitch3
                lightsOn: false
                buttonTitle: "Makuuhuone"
                buttonImage: "images/switch_off.png"
                function serialToggle(){
                    if(serial.lightswitch3_state === 0){
                        lightsOn = false;
                        buttonImage = "images/switch_off.png";
                    }
                    else {
                        lightsOn = true;
                        buttonImage = "images/switch_on.png";
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        parent.lightSwitchToggle();
                        serial.writeSerial(3); // Makuuhuone, vihreä
                    }
                }
                Component.onCompleted: {
                    lightswitch3.serialToggle();
                }
            }
            SquareButton {
                id: lightswitch4
                lightsOn: false
                buttonTitle: "Olohuone"
                buttonImage: "images/switch_off.png"
                function serialToggle(){
                    if(serial.lightswitch4_state === 0){
                        lightsOn = false;
                        buttonImage = "images/switch_off.png";
                    }
                    else {
                        lightsOn = true;
                        buttonImage = "images/switch_on.png";
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        parent.lightSwitchToggle();
                        serial.writeSerial(4); // Olohuone, punainen
                    }
                }
                Component.onCompleted: {
                    lightswitch4.serialToggle();
                }
            }

            }

        }

        Column {
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 115
            SquareButton {
                height: 260
                width: 300

                Text {
                    text: "Ulkovalaistus"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    anchors.topMargin: 10
                    color: "#a7d129"
                    font { family: localFont.name; pixelSize: 20; capitalization: Font.Capitalize }
                }

                Dial {
                    id: outdoorlightControl
                    width: 175
                    height: 175
                    value: outdoorlightControl.currentValue
                    from: 0
                    to: 5
                    stepSize: 1
                    anchors.centerIn: parent

                    property int currentValue: 3
                    function joku() {
                        if(value.toFixed(0) != currentValue) {
                            if(value.toFixed(0) == 1)
                            serial.writeSerial(5);
                            if(value.toFixed(0) == 2)
                            serial.writeSerial(6);
                            if(value.toFixed(0) == 3)
                            serial.writeSerial(7);
                            if(value.toFixed(0) == 4)
                            serial.writeSerial(8);
                            if(value.toFixed(0) == 5)
                            serial.writeSerial(9);
                        }
                        outdoorlightControl.currentValue = value.toFixed(0);
                    }

                    background: Rectangle {
                        x: outdoorlightControl.width / 2 - width / 2
                        y: outdoorlightControl.height / 2 - height / 2
                        width: Math.max(64, Math.min(outdoorlightControl.width, outdoorlightControl.height))
                        height: width
                        color: "transparent"
                        radius: width / 2
                        border.color: outdoorlightControl.pressed ? "#616f39" : "#616f39"
                        border.width: 5
                        opacity: outdoorlightControl.enabled ? 1 : 0.3

                        Text {
                            anchors.centerIn: parent
                            text: (outdoorlightControl.value/5*100).toFixed(0) + " %"
                            color: "white"
                            font { family: localFont.name; pixelSize: 30; capitalization: Font.Capitalize }
                        }

                    }

                    handle: Rectangle {
                        id: handleItem
                        x: outdoorlightControl.background.x + outdoorlightControl.background.width / 2 - width / 2
                        y: outdoorlightControl.background.y + outdoorlightControl.background.height / 2 - height / 2
                        width: 25
                        height: 25
                        color: outdoorlightControl.pressed ? "#a7d129" : "#a7d129"
                        radius: 25
                        antialiasing: true
                        opacity: outdoorlightControl.enabled ? 1 : 0.3
                        transform: [
                            Translate {
                                y: -Math.min(outdoorlightControl.background.width, outdoorlightControl.background.height) * 0.4 + handleItem.height / 2
                            },
                            Rotation {
                                angle: outdoorlightControl.angle
                                origin.x: handleItem.width / 2
                                origin.y: handleItem.height / 2
                            }
                        ]
                    }
                }
                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 15
                    color: "#ffffff"
                    text: "Päivänvalon määrä " + (serial.daylight/65536*100).toFixed(0) + "%"
                    font { family: localFont.name; pixelSize: 15; }
                }
            }
        }

    Component.onCompleted: {
        serial.lightswitch1StateChanged.connect(lightswitch1.serialToggle);
        serial.lightswitch2StateChanged.connect(lightswitch2.serialToggle);
        serial.lightswitch3StateChanged.connect(lightswitch3.serialToggle);
        serial.lightswitch4StateChanged.connect(lightswitch4.serialToggle);
        outdoorlightControl.moved.connect(outdoorlightControl.joku);
    }
    }


