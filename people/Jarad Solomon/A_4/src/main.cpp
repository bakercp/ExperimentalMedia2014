#line 1 "A_4"

#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:

#line 1 "A_4"
ofSerial mySerial; 

};

int main()
{
    ofSetupOpenGL(320, 240, OF_WINDOW);
    ofRunApp(new ofApp());
}
