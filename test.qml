import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible: true
    width: 800
    height: 600

    Row {
        anchors.centerIn: parent
        property var word: ['H','e','l','l','o','!']
        id: row
        Repeater {
            id: repeater
            model: row.word.length
            delegate: Rectangle {
                id: delegate;
                width: 100
                height: 100
                property int pos
                color: Qt.rgba(Math.random(),Math.random(),Math.random(),1);
                Text {
                    anchors.centerIn: parent
                    font.pixelSize: 36
                    color: "white"
                    text: row.word[index]
                }

                Behavior on x {
                    ParallelAnimation {
                        PropertyAnimation {
                            duration: 500
                            easing.type: Easing.InOutBack
                        }
                        SequentialAnimation {
                            PropertyAnimation {
                                target: delegate
                                property: "y"
                                from: 0
                                to: delegate.pos == 1 ? 20 : -20
                                duration: 250
                            }
                            PropertyAnimation {
                                target: delegate
                                property: "y"
                                from: delegate.pos == 1 ? 20 : -20
                                to: 0
                                duration: 250
                            }
                        }
                    }
                }
                Behavior on rotation {
                    RotationAnimation {
                        direction: RotationAnimation.Clockwise
                        duration: 300
                    }
                }
            }
        }
    }

    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: {
            var element1 = repeater.itemAt(Math.round(Math.random() * (repeater.count - 1)));
            var element2 = repeater.itemAt(Math.round(Math.random() * (repeater.count - 1)));
            if(element1 === element2) {
                element1.rotation = element1.rotation + 90;
            } else {
                element1.pos = 1;
                element2.pos = 2;
                var temp = element1.x;
                element1.x = element2.x;
                element2.x = temp;
            }
        }
    }
}