#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate(60);
    ofBackgroundHex(0xEFDC9E);
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){
    
    ofSetWindowTitle("fps="+ofToString(ofGetFrameRate()));
    
    for(int i=0; i<particles.size(); i++)
    {
        particles[i].updateMe();
        
        if(particles[i].color.a < 10) {
            particles.erase( particles.begin() + i );
        }
    }
    
    
    mouse.set(mouseX, mouseY);
    mouseVel = mouse-mousePrev;
    mousePrev = mouse;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for(int i=0; i<particles.size(); i++)
    {
        particles[i].drawMe();
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    Particle p;
    p.initialize(x, y, mouseVel.x*5, mouseVel.y*5);
    particles.push_back(p);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
