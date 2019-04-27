import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4


    Column {
        id: mainview
        spacing: 10
        property string localTime: "..."
        property string localDate: "..."
        property string tila: "Poissa"

        function updateTime(time, date){
            mainview.localTime = time;
            mainview.localDate = date;
        }

        property int buttonTextSize: 10
        property string buttonTextColor: "#a7d129" //#ff7517
        property int buttonTextBottomMargin: 25
        property string buttonBackgroundColor: "#222222" //#3e3939
        property int buttonImageTopMargin: 25
        property int buttonSize: 125
        property int buttonRadius: 0
        property string buttonBorderColor: "#181818"
        property int buttonBorderWidth: 2

        Row {

            spacing: 10

            Rectangle {
                width: 250
                height: 125
                color: buttonBackgroundColor
                radius: buttonRadius
                border.color: buttonBorderColor
                border.width: buttonBorderWidth
                Text {
                    text: mainview.localTime
                    color: "#FFFFFF"
                    anchors.centerIn: parent
                    font { family: localFont.name; pixelSize: 30; capitalization: Font.Capitalize }
                }
            }

            SquareButton {
                buttonTitle: "Valaistus"
                buttonImage: "images/lights.png"
                MouseArea {
                    anchors.fill: parent; onClicked: {
                        changeViewSignal("lights")
                    }
                }
            }

            SquareButton {
                buttonTitle: "Lukot"
                buttonImage: "images/key.png"
                MouseArea {
                    anchors.fill: parent; onClicked: {
                        changeViewSignal("doors")
                    }
                }
            }

            SquareButton {
                buttonTitle: "Ilmanlaatu"
                buttonImage: "images/flower.png"
                MouseArea {
                    anchors.fill: parent; onClicked: {
                        changeViewSignal("airquality")
                    }
                }
            }

        }

        Row {

            spacing: 10

            Rectangle {

                width: 250;
                height: 125;
                color: buttonBackgroundColor
                radius: buttonRadius
                border.color: buttonBorderColor
                border.width: buttonBorderWidth

                Text {
                    text: mainview.localDate
                    horizontalAlignment: Text.AlignHCenter
                    color: "#616f39"
                    anchors.centerIn: parent
                    font { family: localFont.name; pixelSize: 30; capitalization: Font.Capitalize }
                }

            }

            SquareButton {
                width: 395
                Text {
                    anchors.centerIn: parent
                    color: "#ffffff"
                    font { family: localFont.name; pixelSize: 32; capitalization: Font.Capitalize }
                    text: "Tila: " + mainview.tila
                }
            }


        }
        Row {
            spacing: 10
            Rectangle { width: 250; height: 125; color: buttonBackgroundColor; radius: buttonRadius; border.color: buttonBorderColor; border.width: buttonBorderWidth; Text { text: serial.temperature.toFixed(2) + " °C"; color: "#FFFFFF"; anchors.centerIn: parent; font { family: localFont.name; pixelSize: 30; capitalization: Font.Capitalize } } }

            SquareButton {
                width: 192.5
                DelayButton {
                    anchors.centerIn: parent
                    id: homeStateButton1
                    property bool checked_: true
                    property bool enabled_: false
                    checked: homeStateButton1.checked_
                    enabled: homeStateButton1.enabled_
                    delay: 1000

                    function changeHomeState() {
                        homeStateButton1.checked_ = true;
                        homeStateButton1.enabled_ = false;
                        homeStateButton2.checked_ = false;
                        homeStateButton2.enabled_ = true;
                        mainview.tila = "Poissa";
                    }

                    contentItem: Text {
                        text: homeStateButton1.text
                        font: homeStateButton1.font
                        opacity: enabled ? 1.0 : 0.3
                        color: "white"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }

                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 100
                        opacity: enabled ? 1 : 0.3
                        color: homeStateButton1.down ? "#222222" : "#222222"
                        radius:0

                        Image {
                            source: "images/leave_home.png"
                            anchors.centerIn: parent
                        }

                        readonly property real size: Math.min(homeStateButton1.width, homeStateButton1.height)
                        width: size
                        height: size
                        anchors.centerIn: parent

                        Canvas {
                            id: canvas1
                            anchors.fill: parent

                            Connections {
                                target: homeStateButton1
                                onProgressChanged: canvas1.requestPaint()
                            }

                            onPaint: {
                                var ctx = getContext("2d")
                                ctx.clearRect(0, 0, width, height)
                                ctx.strokeStyle = "#ff392e"
                                ctx.lineWidth = parent.size / 20
                                ctx.beginPath()
                                var startAngle = Math.PI / 5 * 3
                                var endAngle = startAngle + homeStateButton1.progress * Math.PI / 5 * 9
                                ctx.arc(width / 2, height / 2, width / 2 - ctx.lineWidth / 2 - 2, startAngle, endAngle)
                                ctx.stroke()
                            }
                        }
                    }
                }
            }

            SquareButton {
                width: 192.5
                DelayButton {
                    property bool checked_: false
                    property bool enabled_: true
                    anchors.centerIn: parent
                    id: homeStateButton2
                    checked: homeStateButton2.checked_
                    enabled: homeStateButton2.enabled_
                    delay: 1000

                    function changeHomeState() {
                        homeStateButton2.checked_ = true;
                        homeStateButton2.enabled_ = false;
                        homeStateButton1.checked_ = false;
                        homeStateButton1.enabled_ = true;
                        mainview.tila = "Kotona";
                    }

                    contentItem: Text {
                        text: homeStateButton2.text
                        font: homeStateButton2.font
                        opacity: enabled ? 1.0 : 0.3
                        color: "white"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight

                    }

                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 100
                        opacity: enabled ? 1 : 0.3
                        color: homeStateButton2.down ? "#222222" : "#222222"
                        radius:0

                        Image {
                            source: "images/door.png"
                            anchors.centerIn: parent
                        }

                        readonly property real size: Math.min(homeStateButton2.width, homeStateButton2.height)
                        width: size
                        height: size
                        anchors.centerIn: parent

                        Canvas {
                            id: canvas2
                            anchors.fill: parent

                            Connections {
                                target: homeStateButton2
                                onProgressChanged: canvas2.requestPaint()
                            }

                            onPaint: {
                                var ctx = getContext("2d")
                                ctx.clearRect(0, 0, width, height)
                                ctx.strokeStyle = "#a7d129"
                                ctx.lineWidth = parent.size / 20
                                ctx.beginPath()
                                var startAngle = Math.PI / 5 * 3
                                var endAngle = startAngle + homeStateButton2.progress * Math.PI / 5 * 9
                                ctx.arc(width / 2, height / 2, width / 2 - ctx.lineWidth / 2 - 2, startAngle, endAngle)
                                ctx.stroke()
                            }
                        }
                    }
                }
            }

        }


        Timer {
                id: timer
                interval: 1000; running: true; repeat: true
                onTriggered: {
                    mainview.updateTime(
                    new Date().toLocaleTimeString(Qt.locale(), "hh:mm:ss"),
                    new Date().toLocaleDateString(Qt.locale() ,"d MMMM\nyyyy")
                    );

                }

            }

        Component.onCompleted: {
            timer.start()
            homeStateButton1.activated.connect(homeStateButton1.changeHomeState);
            homeStateButton2.activated.connect(homeStateButton2.changeHomeState);
        }

    }
