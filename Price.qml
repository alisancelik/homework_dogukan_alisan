import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    id: price
    width: 640
    height: 850
    implicitWidth: 640
    implicitHeight: 800
    header: Label {
        text: qsTr("Room Prices for December")
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 30
        wrapMode: Text.NoWrap
        fontSizeMode: Text.HorizontalFit
        textFormat: Text.AutoText
        horizontalAlignment: Text.AlignHCenter
        padding: 10
    }


    Column {
        x: 0
        y: 410
        width: 355
        height: 156
        anchors.horizontalCenter: parent.horizontalCenter
        Text {
            font.pointSize: 24
            style: Text.Raised
            text: "Standard     =200€"
            styleColor: "red"
        }
        Text {
            font.pointSize: 24
            text: "Suit            =500€"
            style: Text.Raised
            styleColor: "blue"
        }
        Text {
            font.pointSize: 24
            text: "Family        =300€"
            style: Text.Raised
            styleColor: "green"

        }
        Text {
            font.pointSize: 24
            text: "Honeymoon =420€"
            style: Text.Raised
        }
    }
}
