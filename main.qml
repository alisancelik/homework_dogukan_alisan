import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: qsTr("DSA_Homework")

   // function calculation() {
     //   panelLoader.setSource("qrc:/Price.qml")
    //}
    function rooms() {
        panelLoader.setSource("qrc:/Price.qml")
    }
    function reservation() {
        panelLoader.setSource("qrc:/HotelRoom.qml")
    }
    SwipeView {
        id: swipeView
        anchors.rightMargin: 0
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Hotelroom {
            anchors.centerIn: parent
        }


    }
    Loader {
        id: panelLoader
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        function setSource(source, vehicleComponent) {
            panelLoader.vehicleComponent = vehicleComponent
            panelLoader.source = source
        }

        function setSourceComponent(sourceComponent, vehicleComponent) {
            panelLoader.vehicleComponent = vehicleComponent
            panelLoader.sourceComponent = sourceComponent
        }

        property var vehicleComponent
    }
    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("Reservation")
            onClicked: {
                reservation()
            }
        }
        TabButton {
            text: qsTr("Rooms")
            onClicked: {
                rooms()
            }

        }
        /*TabButton {
            text: qsTr("Calculate")
            onClicked: {
                calculation()
            }

        }*/
    }
}
