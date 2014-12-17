#line 1 "SnowParticle"

#include "ofMain.h"
#include "BaseParticle.h"


#line 2 "SnowParticle"
#pragma once

class SnowParticle: public BaseParticle {
public:
	SnowParticle(): angle(ofRandom(360)){
	}	
	
	virtual ~SnowParticle()
	{
	}
	
    virtual void draw()
    {  
        angle += ofRandom(-.4, .4);
        
        ofFill();
        ofSetColor(255, 255, 255, 150);
        ofPushMatrix();
        ofTranslate(position.x, position.y);
        ofRotateZ(angle);
        ofCircle(0, 0, 20, 14);
        ofPopMatrix();
    }
    
    float angle;
};

