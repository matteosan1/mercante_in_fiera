import QtQuick 2.0
import QtGraphicalEffects 1.0

Flipable {
  id: container

  property alias source: frontImage.source
  property alias backSource: backImage.source
  property bool flipped: true
  property int direction: -1
  property int xAxis: 0
  property int yAxis: 0
  property int angle: 0
  property int xPos:  0
  property int yPos:  0
  property int zPos:  0
  property bool blocked: true

  x: xPos; y: yPos; z: zPos
  width: front.width; height: front.height

  front: Image { id: frontImage }
  back: Image { id: backImage }

  state: "back"

  MouseArea { anchors.fill: parent
      onClicked: {
          if (!blocked) {
              container.direction = -container.direction
              container.flipped = !container.flipped
          }
      }
  }

  transform: Rotation {
      id: rotation; origin.x: container.width / 2.; origin.y: container.height / 2.
      axis.x: container.xAxis; axis.y: container.yAxis; axis.z: 0
  }

  states: [
    State {
      name: "back"; when: container.flipped
      PropertyChanges { target: rotation; angle: container.angle}
    }
  ]

  transitions: [
      Transition {
        ParallelAnimation {
          NumberAnimation { target: rotation; properties: "angle"; duration: 600 }
          SequentialAnimation {
              NumberAnimation { target: container; property: "scale"; to: 1.25; duration: 300 }
              NumberAnimation { target: container; property: "scale"; to: 1.0; duration: 300 }
          }
        }
      }
  ]
}

