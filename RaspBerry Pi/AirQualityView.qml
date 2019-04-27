import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls 2.12

Item {

    TopBar {
        title: "Ilmanlaatu"
    }

    Item {

        width: 450
        height: 300
        anchors.centerIn: parent

        Item {
            id: co2
            width: 150
            height: 300
            anchors.left: parent.left
            property int value: serial.CO2.toFixed(2)

                Rectangle {
                    width: 85
                    height: parent.height / 1500 * co2.value
                    color: {
                        if(co2.value < 600)
                            return "#a7d129";
                        if(co2.value > 600 && co2.value < 1200)
                            return "#fcfc4b";
                        else if(co2.value > 1200)
                            return "#ff392e";
                    }
                    radius: 10
                    border.color: "#181818"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 25

                    Text {
                        text: co2.value + " ppm"
                        color: "#1B1919"
                        anchors.top: parent.top
                        anchors.topMargin: 10
                        anchors.horizontalCenter: parent.horizontalCenter
                        font { family: localFont.name; pixelSize: 15; }
                    }
                }

                Text {
                    color: "#FFFFFF"
                    text: qsTr("Hiilidioksidi")
                    anchors.bottom: parent.bottom
                    anchors.horizontalCenter: parent.horizontalCenter
                    font { family: localFont.name; pixelSize: 15; }
                }

        }

        Item {
            id: humidity
            width: 150
            height: 300
            anchors.horizontalCenter: parent.horizontalCenter
            property int value: serial.humidity.toFixed(2)
                Rectangle {
                    width: 85
                    height: parent.height / 90 * humidity.value
                    color: {
                        if(humidity.value < 45)
                            return "#a7d129";
                        if(humidity.value > 45 && humidity.value < 60)
                            return "#fcfc4b";
                        else if(humidity.value > 60)
                            return "#ff392e";
                    }
                    radius: 10
                    border.color: "#181818"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 25

                    Text {
                        text: serial.humidity.toFixed(2) + "RH%"
                        color: "#1B1919"
                        anchors.top: parent.top
                        anchors.topMargin: 10
                        anchors.horizontalCenter: parent.horizontalCenter
                        font { family: localFont.name; pixelSize: 15; }
                    }
                }

                Text {
                    color: "#FFFFFF"
                    text: qsTr("Ilmankosteus")
                    anchors.bottom: parent.bottom
                    anchors.horizontalCenter: parent.horizontalCenter
                    font { family: localFont.name; pixelSize: 15; }
                }

        }

        Item {
            id: temperature
            width: 150
            height: 300
            anchors.right: parent.right
            property var value: serial.temperature.toFixed(2)

                Rectangle {
                    width: 85
                    height: parent.height / 50 * temperature.value
                    color: {
                        if(temperature.value < 20)
                            return "#81dafc";
                        if(temperature.value > 20 && temperature.value < 25)
                            return "#a7d129";
                        else if(temperature.value > 25 && temperature.value < 30)
                            return "#fcfc4b";
                        else if(temperature.value > 30)
                            return "#ff392e";
                    }
                    //color: (temperature.value < 25) ? "#a7d129" : "#fcfc4b" // pun #ff392e
                    radius: 10
                    border.color: "#181818"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 25

                    Text {
                        text: temperature.value + " °C"
                        color: "#1B1919"
                        anchors.top: parent.top
                        anchors.topMargin: 10
                        anchors.horizontalCenter: parent.horizontalCenter
                        font { family: localFont.name; pixelSize: 15; }
                    }
                }

                Text {
                    color: "#FFFFFF"
                    text: qsTr("Lämpötila")
                    anchors.bottom: parent.bottom
                    anchors.horizontalCenter: parent.horizontalCenter
                    font { family: localFont.name; pixelSize: 15; }
                }

        }
    }



}
