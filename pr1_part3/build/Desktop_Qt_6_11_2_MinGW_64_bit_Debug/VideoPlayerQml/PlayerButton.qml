import QtQuick
import QtQuick.Controls

Button {
    id: control

    property url imageSource
    property string tooltipText: ""

    implicitWidth: 32
    implicitHeight: 28

    width: 32
    height: 28

    padding: 0

    topInset: 0
    bottomInset: 0
    leftInset: 0
    rightInset: 0

    hoverEnabled: true
    focusPolicy: Qt.NoFocus

    contentItem: Item {
        Image {
            anchors.centerIn: parent

            width: 18
            height: 18

            source: control.imageSource
            sourceSize: Qt.size(18, 18)

            fillMode: Image.PreserveAspectFit
            smooth: true
        }
    }

    ToolTip.visible: hovered && tooltipText.length > 0
    ToolTip.text: tooltipText
    ToolTip.delay: 500
}