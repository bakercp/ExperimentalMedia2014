#line 1 "image_rotation"

#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:

#line 1 "image_rotation"

void setup() {
    ofSetWindowShape(1600, 1200);
}

void draw() {
    ofBackground(0);

    int numX = 100;
    int numY = 80;

    float spaceX = ofGetWidth() / (numX + 1);
    float spaceY = ofGetHeight() / (numY + 1);

    float cursorX = ofGetMouseX();
    float cursorY = ofGetMouseY();

    for (int y = 0; y < numY; y++) 
    {
        for (int x = 0; x < numX; x++)
        {
            float xPosition = (x + 1) * spaceX;
            float yPosition = (y + 1) * spaceY;
            
            float adjustedX = cursorX - xPosition;
            float adjustedY = cursorY - yPosition;
            
            float angleRadians = atan2(adjustedY, adjustedX);
            
            float deltaX = cursorX - xPosition;
            float deltaY = cursorY - yPosition;
            float distance = sqrt((deltaX * deltaX) + (deltaY * deltaY));
            float maxDistance = sqrt((ofGetWindowWidth() * ofGetWindowWidth()) + (ofGetWindowHeight() * ofGetWindowHeight()));
            float lineDistance = ofMap (distance, 0, maxDistance, 10, 50);
            float colorDistance = ofMap (distance, 0, maxDistance/2, 0, 255);
            float colorHeight = ofMap (yPosition, 0, ofGetWindowHeight(), 0, 255);
            float colorWidth = ofMap (xPosition, 0, ofGetWindowWidth(), 0, 255);
            
            ofPushMatrix();
            ofTranslate(xPosition, yPosition);
            ofRotateZ(ofRadToDeg(angleRadians));
            
            ofSetColor (colorWidth, colorHeight, colorDistance);
            ofEllipse(0, 0, lineDistance, 10);            
            // ofEllipse(0, 0, 80, 80);
            
            ofPopMatrix();
        }   
    }
}


};

int main()
{
    ofSetupOpenGL(320, 240, OF_WINDOW);
    ofRunApp(new ofApp());
}

