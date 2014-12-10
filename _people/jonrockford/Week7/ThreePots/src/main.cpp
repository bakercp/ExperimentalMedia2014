#line 1 "ThreePots"

#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:

#line 1 "ThreePots"
# define points 256

bool space;
ofSerial serial;
float data = 0;
int r, g, b, ra, ga, ba, String;
void setup() {
	// put your setup code here, to run once:
	serial.setup(0, 9600);
	ofSetWindowShape(1024, 768);
	ofBackground(125,125,125);
	ofSetFrameRate(30);
	
	
    
        r = 255;
        g = 0;
        b = 0;
        
        ra = 225;
        ga = 225;
        ba = 0;

	
}
void draw() {
	// put your main code here, to run once each frame:
		//---------------------------  lines
	// a bunch of red lines, make them smooth if the flag is set
	if (serial.available()) {
	       data = serial.readByte();
	       serial.flush();
    }
        
      
        // int ofToInt (data);
        // vector<float> pots;
        // pots.push_back(data);
        
         string data = "a,,b,,c";
         vector<string> splitItems = ofSplitString(data, ",");
         cout << splitItems.size() << endl;
        //vector< string > ofSplitString(const string &data, const string &delimiter, bool ignoreEmpty=false, bool trim=false);
        //cout << data[0] << end;
        // vector< string >::iterator it = data.begin();
        // for( int i = 0; i < data.size(); i++){
        //     cout << data[i] << endl;
        int ofToInt (const string &data);
	    for (int i = 0; i <points; i++){
		
		ofSetColor(r, g, b);
		    if ( i % 2 == 0 ){
		    ofSetColor(ra, ga, ba);
		        
		   }
	    
		   ofLine(i*5, data*3, i*5, 700);
	    }
}
	    r = 255;
        g = 0;
        b = 0;
        
        ra = 225;
        ga = 225;
        ba = 0;
        
        if (space){
        r = 0;
        g = 0;
        b = 0;
        
        ra = 255;
        ga = 255;
        ba = 255;
       
	}
}
	
void keyPressed(int key)
{
      
       if (' ' == key) {
           space = true;
           
        }
       }
	





};

int main()
{
    ofSetupOpenGL(320, 240, OF_WINDOW);
    ofRunApp(new ofApp());
}
