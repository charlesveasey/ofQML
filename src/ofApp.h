#pragma once
#include "ofMain.h"
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlProperty>
#include <QQuickView>
#include <QObject>

class ofApp : public ofBaseApp {
public:
    // oF
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    int x;

    // qml
    void qmlButtonPressed();
    void qmlSliderChanged(float msg);
    QQmlApplicationEngine qmlEngine;
    QObject *qmlWindow;
    QObject *qmlButton;
    QObject *qmlSlider;
};

// qml signal to slot object
class QMLCallback : public QObject {
    Q_OBJECT
public:
    ofApp *ofAppInstance;

public slots:
    void buttonSlot() {
        ofAppInstance->qmlButtonPressed();
    }
    void sliderSlot(QVariant msg) {
        ofAppInstance->qmlSliderChanged(msg.toFloat());
    }
};
