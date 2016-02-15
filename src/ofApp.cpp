#include "ofApp.h"

// global qml signal to slot object instance
QMLCallback qmlCallback;

//--------------------------------------------------------------
void ofApp::setup(){
    // oF
    x = 0;

    // qml
    QQmlComponent component(&qmlEngine,
          QUrl(QStringLiteral("qrc:/main.qml")) );

    qmlWindow = component.create();
    qmlButton = qmlWindow->findChild<QObject*>("changeColorButton");
    qmlSlider = qmlWindow->findChild<QObject*>("changePositionSlider");

    // connect qml signals and slots
    qmlCallback.ofAppInstance = this;

    QObject::connect(qmlButton, SIGNAL( clicked() ),
                     &qmlCallback, SLOT( buttonSlot() ));
    QObject::connect(qmlSlider, SIGNAL( sliderSignal(QVariant) ),
                     &qmlCallback, SLOT( sliderSlot(QVariant) ));
}

//--------------------------------------------------------------
void ofApp::update(){}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawCircle(x, ofGetHeight()/2, 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // call a qml function
    QVariant returnedValue;
    QVariant msg = "Hello from C++";
    QMetaObject::invokeMethod(qmlWindow, "myQmlFunction",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, msg));

    QString returnedValueString = returnedValue.toString();
    cout << "QML function returned: " << returnedValueString.toStdString() << endl;
}

//--------------------------------------------------------------
void ofApp::qmlButtonPressed(){
    ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
}

//--------------------------------------------------------------
void ofApp::qmlSliderChanged(float msg){
    x = ofMap(msg, 0, 1, 0, ofGetWidth());
}
