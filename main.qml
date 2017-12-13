import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtMultimedia 5.8

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 1000
    height: 800
    title: qsTr("Mercante in fiera")

    Rectangle {
        anchors.fill: parent
        id: root
        property int carteScoperte: 0

        Image {
            anchors.fill: parent
            fillMode: Image.Tile
            source: "panno1.jpeg"
        }
//        //color: "#00AA00"

        Clock {}

        Repeater {
            anchors.top: parent.top
            id: repeater
            model : carteModel
            Carta {
            id: delegate
                source: fronte
                backSource: retro
                angle: 180
                yAxis: 1
                xPos: parent.width/3.
                yPos: 20
                zPos: index
                onScopri: {
                   root.carteScoperte++
                    if (root.carteScoperte == carteModel.rowCount()) {
                        for (var i=0; i<carteVincentiModel.rowCount(); i++)
                            repeater2.itemAt(i).blocked = false
                    }
                }
                onCopri:  {
                    root.carteScoperte--
                    if (root.carteScoperte != carteModel.rowCount()) {
                        for (var i=0; i<carteVincentiModel.rowCount(); i++)
                            repeater2.itemAt(i).blocked = true
                    }
                }
            }
            Text {
                id: label1
                text: "PUPPA"
            }
        }

        focus: true
        Keys.onPressed: {
            if (event.key == Qt.Key_Space) {
                carteVincentiModel.smazza()
                carteModel.smazza()
            }
        }

        Grid {
            id: row1
            horizontalItemAlignment: Grid.AlignHCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter

            columns: 3//carteVincentiModel.rowCount()
            spacing: 50
            Repeater {
                id: repeater2
                model : carteVincentiModel
                CartaVincente {
                    id: delegate1
                    source: fronte
                    backSource: retro
                    angle: 180
                    yAxis: 1
                    xPos: 0
                    yPos: 0
                }
//                carteVincentiModel.onDone: {
//                    repeater3.visible = true
//                }
            }

//            focus: true
//            Keys.onPressed: {
//                if (event.key == Qt.Key_Return) {
//                    MyScript.createVideoObject();
////                    for (var i=0; i<nvincenti.integer; i++) {
////                        console.log(repeater2.itemAt(i).x)
////                        repeater2.itemAt(i).x = 1000
////                    }
////                }
////                else if (event.key == Qt.Key_Space) {
////                    for (var i=0; i<nvincenti.integer; i++) {
////                        repeater2.itemAt(i).x = 0
////                    }
//                }
//            }
        }

        Grid {
            id: row2
            horizontalItemAlignment: Grid.AlignHCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter

            columns: 3//carteVincentiModel.rowCount()
            spacing: 150

            Repeater {
                id: repeater3
                model: etichette
                Rectangle {
                    id: label
                    width: 120
                    height: 30
                    color: "transparent"
                    Text {
                        anchors.horizontalCenter: label.horizontalCenter
                        anchors.verticalCenter: label.verticalCenter
                        text: modelData.name + " PREMIO"
                        font.bold: true
                        color: "gold"
                    }
                }
            }

        }
    }
}
// aggiungere ombra

