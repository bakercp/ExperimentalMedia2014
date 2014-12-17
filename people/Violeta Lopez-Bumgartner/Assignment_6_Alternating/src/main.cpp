#line 1 "Assignment_6"

#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:

#line 1 "Assignment_6"
// What is a std::vector?
// What is does an if - else - statement do?
// What does a switch statement do?
// What does a for loop do and how does it differ from a while loop?
// What is a modulo operator (%) and how do you use it?
// In Arduino, what is the difference between Serial.write() and Serial.print().
// What is “Object-Oriented” Programming?

void setup() {
	// put your setup code here, to run once:
		ofSetWindowShape(400, 400);
		
}


void draw() {
    ofBackground(255);
    
	
	for(int x = 0; x < 255; x+=3) {
	    int r = 0;
	    int g = 0;
	    int b = 255;
	    
        if (( x % 10) == 0) {
            r = 0;
            g = 0;
            b = 0;
        }
	    
	    ofSetColor(r, g, b);
        ofLine(x, 0, x, 400);   
	}
	
}


void update() {

}

};

int main()
{
    ofSetupOpenGL(320, 240, OF_WINDOW);
    ofRunApp(new ofApp());
}
