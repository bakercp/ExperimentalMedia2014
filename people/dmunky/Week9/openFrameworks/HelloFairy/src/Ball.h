#line 1 "Ball"

#include "ofMain.h"


#line 1 "Ball"
class Ball{
    
public:
ofVec2f position;
ofVec2f velocity; 

int radius;
    
float x; //particle position x.
float y; //particle position y;

float vx; //velocity in x direction
float vy; //velocity in y direction
float ax; //acceleration in the x direction
float ay; //Acceleration in the y direction

//float radius; //radius of our circle particle
float rebound;//bounciness
float drag; //drag factor
    
    ofColor color;
    
    Ball() {
   
        ax = 0;
        ay = .25;
        vx = 2;
        vy = 2;
        
        
        //Choose a random radius.
        radius = ofRandom(30,75);
        // Choose a random position.
        position = ofVec2f(ofRandom(radius, ofGetWidth() - radius), 
                           ofRandom(radius, ofGetHeight() - radius));
        
        // Choose a random velocity.
        velocity = ofVec2f(ofRandom(-5, 5), ofRandom(-5, 5));
      
        // Choose a random color between red and yellow.
        color = ofColor(255, ofRandom(255), 0, 255);
        
      
    
    }
    
    void update() {
        rebound = 0.9;
        drag = 0.99;
//          if (ofGetMousePressed())
//   {
//       x = ofGetMouseX();
//       y = ofGetMouseY();
//       vx = ofRandom(-5,5);
//       vy = ofRandom(-5,5);
//       return;
//   }
   
	    vx = vx + ax; //add the x acceleration component to the x velocity
	    vy = vy + ay; //add the y acceleration component to the y velocity
	    
	    vx = vx * drag; //take away a little bit of velocity based on drag
	    vy = vy * drag; //take away a little bit of velocity based on drag
	    
	    x = x + vx; // add the x velocity component
	    y = y + vy; // add the y velocity component
	
	
	//Left wall.
	if((x - radius) < 0)
	{
	    vx = vx * -rebound;
	    x = radius;
	}
    else if ((x + radius) > ofGetWidth()) 
    
    // Right wall
    {
        vx = vx * -rebound;
        x = ofGetWidth() - radius; //set the ball in the right place.
    }
    
    if ((y - radius) < 0) // Top wall.
    { 
        vy = vy * - rebound;
        y =ofGetHeight() - radius;
    }
    
    else if((y + radius) > ofGetHeight()) //Bottom wall
    {
        vy = vy * - rebound;
        y = ofGetHeight() - radius; // set the ball in the right place
    }

        
        // Update the x velocity.
        if (position.x + radius >= ofGetWidth() ||
            position.x - radius <= 0) {
            velocity.x *= -1;
        }
        
        // Update the y velocity.
        if (position.y + radius >= ofGetHeight() ||
            position.y - radius <= 0) {
            velocity.y *= -1;
        }
        
        // Update the position.
        position += velocity;
    
    }

    void draw(ofImage fairy) {
        
        fairy.draw(position,radius,radius);
        // ofFill();
    
        // // Set the fill color for this ball.
        // ofSetColor(color.r, color.g, color.b, 127);
        
        // // Draw the ball.
        // ofCircle(position, radius);
        
        // ofNoFill();
        
        // // Set the outline for this ball.
        // ofSetColor(color);
        
        // // Draw the ball.
        // ofCircle(position, radius); 
    
    }
    
//     void mouseDragged(int mouseX, int mouseY, int button)
// {
//     x = mouseX;
//     y = mouseY;
    
//     int lastMouseX = ofGetPreviousMouseX();
//     int lastMouseY = ofGetPreviousMouseY();
    
//     vx = mouseX - lastMouseX; //give the mouse's X velocity to the ball.
//     vy = mouseY - lastMouseY; //give the mouse's Y velocity to the ball.
    
// }

};

