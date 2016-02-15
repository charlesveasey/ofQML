import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

Window {
    id: qmlWindow
    x: 250; y: 250
    width: 250; height: 200
    visible: true
    title: "QML Window"

    Button {
        objectName: "changeColorButton";
        x: 50; y: 40
        height: 25; width: 150
        text: "Change Color";
    }

    Text {
        x: 50; y: 100
        height: 25; width: 150
        text: "Change Position"
    }

    Slider {
        id: slider;
        objectName: "changePositionSlider";
        x: 50; y: 125
        height: 25; width: 150
        value: 0.0
        signal sliderSignal(var msg)
        onValueChanged: slider.sliderSignal(value)
    }

    function myQmlFunction(msg) {
        console.log("Got message:", msg)
        return "some return value"
    }
}

