import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Text {
        id: pingLabel
        y: 100
        text: qsTr("Enter a name:")
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 20
    }

    TextInput {
        id: pingText
        y: 130
        text: "Command"
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 24
    }

    Button {
        id: sendButton
        y: 220
        text: "Send command to Service"
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked:
        {
            amneziaService.sendToService("nme123")
        }
    }

    Text {
        id: pongLabel
        y: 300
        text: qsTr("Android Service replied:")
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 20
    }

    Text {
        id: messageFromService
        y: 330
        text: qsTr("")
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 24
    }

    Connections {
        target: amneziaService
        function onMessageFromService(message) {
            messageFromService.text = message
        }
    }
}
