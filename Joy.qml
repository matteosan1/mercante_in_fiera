import QtQuick 2.0

Video {
    id: video
    width : 800
    height : 600
    source: "video.avi"

    MouseArea {
        anchors.fill: parent
        onClicked: {
            video.play()
        }
    }

    focus: true
    Keys.onSpacePressed: video.playbackState == MediaPlayer.PlayingState ? video.pause() : video.play()
    Keys.onLeftPressed: video.seek(video.position - 5000)
    Keys.onRightPressed: video.seek(video.position + 5000)
}