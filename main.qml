// main.qml
import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Person List")

    ListView {
        anchors.fill: parent
        model: personModel
        delegate: Rectangle {
            width: parent.width
            height: 50
            color: index % 2 == 0 ? "lightgray" : "white"

            Text {
                anchors.centerIn: parent
                text: name + ", " + age + " years old"
            }
        }
    }
}

