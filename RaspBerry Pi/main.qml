import QtQuick 2.12
import QtQuick.Controls 2.12
import io.qt.examples.serial 1.0

ApplicationWindow {
    id: app
    visible: true
    width: 800
    height: 480
    color: "#1B1919" //#2c2727
    title: qsTr("SmartHome Pi")

    FontLoader { id: localFont; source: "fonts/Roboto-Regular.ttf" }
    font { family: localFont.name; pixelSize: 20; capitalization: Font.Capitalize }

    Serial {
        id: serial
    }

    signal changeViewSignal(string viewName)
    signal goBackViewSignal()

    function changeViewSlot(viewName) {
        if(viewName === "lights") {
            stack.push("LightsView.qml")
        }
        if(viewName === "heating") {
            stack.push("HeatingView.qml")
        }
        if(viewName === "airquality") {
            stack.push("AirQualityView.qml")
        }
        if(viewName === "doors") {
            stack.push("DoorsView.qml")
        }
        if(viewName === "homestate") {
            stack.push("HomeStateView.qml")
        }
    }

    function goBackViewSlot() {
        stack.pop()
    }

    StackView {
        anchors.fill: parent
            id: stack
            initialItem: Item {
                MainView {
                    anchors.centerIn: parent
                }
            }
        }

    Component.onCompleted: {
        app.changeViewSignal.connect(app.changeViewSlot);
        app.goBackViewSignal.connect(app.goBackViewSlot);
        serial.readSerial();
    }

}
