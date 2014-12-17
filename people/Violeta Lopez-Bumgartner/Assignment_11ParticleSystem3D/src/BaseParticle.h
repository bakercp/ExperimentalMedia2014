#line 1 "BaseParticle"

#include "ofMain.h"


#line 1 "BaseParticle"
#pragma once

class BaseParticle
{
public:
	BaseParticle(): 
	    drag(10.99),
	    bounciness(0.8),
	    width(20),
	    height(20),
	    depth(20)
	{
	}

    virtual ~BaseParticle()
    {
    }

    virtual void update() 
    {
        velocity += acceleration;   
        velocity *= drag;
        position += velocity; 
        acceleration *= position;
    }
    
    virtual void draw()
    {  
        ofPushStyle();
        ofFill();
        ofSetColor(color);
        ofCircle(position, (width + height + depth) / 30);
        ofPopStyle();
    }
    
    ofVec3f position;
    ofVec3f velocity;
    ofVec3f acceleration;
    
    float drag;
    float bounciness;

    float width;
    float height;
    float depth;
    
    ofColor color;
};

