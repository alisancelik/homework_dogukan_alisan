import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtCharts 2.2
import Hotel 0.0



ColumnLayout {
    id: columnLayout
    width: 640
    height: 480
    Frame {
        ListView {
            width: 624
            height: 350
            implicitWidth: 700
            implicitHeight: 350
            clip: true           
            header: Label {
                text: qsTr("Reservation Page")
                font.pixelSize: 30
                wrapMode: Text.NoWrap
                fontSizeMode: Text.HorizontalFit
                textFormat: Text.Raised
                //verticalAlignment:  Text.AlignVCenter
                anchors.horizontalCenter: parent.horizontalCenter
                color: "red"
                //horizontalAlignment: Text.AlignHCenter
                padding: 10
            }


            Image {
                    id: image
                    x: 279
                    y: 275
                    width: 66
                    height: 55

                    // anchors.horizontalCenter: parent.horizontalCenter
                    source: "reception.png"
                    visible: true
                }


            // anchors.fill: parent
            model: HotelModel {
                list: Hotel
            }

            delegate: RowLayout {
                width: parent.width
                CheckBox {
                    checked: model.done
                    onClicked: model.done = checked
                }
                TextField {
                    text: model.description //will be stored in the model in textfield
                    onEditingFinished: model.desription = text
                    Layout.fillWidth: true // make the TextField as wide as possible
                }
            }
        }
    }







    Column {
        x: 0
        y: 300
        width: 355
        height: 300
        anchors.horizontalCenter: parent.horizontalCenter
        Text {
            font.pointSize: 18
            style: Text.Raised
            text: "2019-12-01 - 2019-12-31"
        }

    }



    RowLayout {
        Button {
            text: qsTr("New reservation   ")
            background: color("#510051")
            onClicked: Hotel.appendItem()
            Layout.fillWidth: true
            visible:true

        }

        Button {
            text: qsTr("Cancel reservation   ")
            onClicked: Hotel.removeCompletedItems()
            Layout.fillWidth: true

        }

        // }

    }


}




/*##^##
Designer {
    D{i:5;anchors_height:50;anchors_width:50;anchors_x:148;anchors_y:0}D{i:4;anchors_height:50;anchors_width:50;anchors_x:148;anchors_y:0}
}
##^##*/
