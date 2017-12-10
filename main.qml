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
            model : carte
            delegate:
                Carta {
                id: delegate
                    source: modelData.name
                    backSource: retro.string
                    angle: 180
                    yAxis: 1
                    xPos: parent.width/3.
                    yPos: 20
                    zPos: modelData.index
                    onScopri: {
                       root.carteScoperte++
                        if (root.carteScoperte == ncarte.integer) {
                            for (var i=0; i<nvincenti.integer; i++)
                                repeater2.itemAt(i).blocked = false
                        }
                    }
                    onCopri:  {
                        root.carteScoperte--
                        if (root.carteScoperte != ncarte.integer) {
                            for (var i=0; i<nvincenti.integer; i++)
                                repeater2.itemAt(i).blocked = true
                        }
                    }
            }
        }

        Grid {
            id: row1
            horizontalItemAlignment: Grid.AlignHCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter

            columns: nvincenti.integer
            spacing: 50
            Repeater {
                id: repeater2
                model : vincenti
                delegate:
                        CartaVincente {
                            id: delegate1
                            source: modelData.name
                            backSource: retro.string
                            angle: 180
                            yAxis: 1
                            xPos: 0
                            yPos: 0
                        }
            }

            focus: true
            Keys.onPressed: {
                if (event.key == Qt.Key_Return) {
                    MyScript.createVideoObject();
//                    for (var i=0; i<nvincenti.integer; i++) {
//                        console.log(repeater2.itemAt(i).x)
//                        repeater2.itemAt(i).x = 1000
//                    }
//                }
//                else if (event.key == Qt.Key_Space) {
//                    for (var i=0; i<nvincenti.integer; i++) {
//                        repeater2.itemAt(i).x = 0
//                    }
                }
            }

            Repeater {
                id: repeater3
                model: etichette
                delegate:
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

