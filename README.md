# openFrameworksQML
Example project demonstrating an openFrameworks and QML project

**Note**  
There is a conflict between:  

**qnamespace.h**   
line 112: 
```SHIFT         = Qt::ShiftModifier,```

***and***  

**ofArduino.h***  
line 62:
```#define SHIFT                                           0x05 // shiftIn/shiftOut mode```

**To Fix**  
Comment out one of these lines of code. I suggest the line in 
**ofArduino.h*** unless of course you are using the Arduino.  

**More Information**  
http://openframeworks.cc/setup/qtcreator/  
http://doc.qt.io/qt-5/qtqml-cppintegration-interactqmlfromcpp.html
