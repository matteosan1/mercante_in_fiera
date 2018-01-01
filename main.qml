import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtMultimedia 5.8
import QtQuick.Window 2.2 // Window.FullScreen
import QtQuick.Controls 1.3 // ApplicationWindow

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 1000
    height: 800
    title: qsTr("Mercante in fiera")
    visibility: Window.FullScreen

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
                xPos: parent.width/carteVincentiModel.rowCount()
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
        }

        Grid {
            id: row1
            horizontalItemAlignment: Grid.AlignHCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter

            columns: carteVincentiModel.rowCount()
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
            }
        }

        Grid {
            id: row2
            horizontalItemAlignment: Grid.AlignHCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter

            columns: carteVincentiModel.rowCount()
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

