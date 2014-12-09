#line 1 "A_8"

#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:

#line 1 "A_8"
ofVideoGrabber grabber;ofPixels pixels;ofImage image;int xPosition = 0;void setup() {ofSetWindowShape(1280, 720);grabber.initGrabber(1280, 720);pixels.allocate(720, 720, OF_PIXELS_RGBA); //make it clear}void update() {grabber.update();    if (grabber.isFrameNew()){for (int y = 0; y < grabber.getHeight(); y++){ofColor pixelFromGrabber = grabber.getPixelsRef().getColor(ofGetMouseX(), y);pixels.setColor(xPosition, y, pixelFromGrabber);}image.setFromPixels(pixels);xPosition++;if (xPosition > pixels.getWidth()){xPosition = 0;   }}}void draw() {image.draw(0, 0);}

};

int main()
{
    ofSetupOpenGL(320, 240, OF_WINDOW);
    ofRunApp(new ofApp());
}

