#include "ofMain.h"
#include "ofApp.h"
#include <QGuiApplication>

//========================================================================
int main( int argc, char *argv[] ){
    ofSetupOpenGL(500,250,OF_WINDOW);
    ofSetWindowTitle("oF Window");

    QGuiApplication app(argc, argv);

    ofRunApp(new ofApp);
}

