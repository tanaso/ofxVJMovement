//  WireCube.cpp
//  MediaArtPractice
//
//  Created by Sota Tanaka on 2022/01/17.
//

#include "ofxWireBox.h"

ofxWireBox::ofxWireBox(){
//    line setting
//    int edgeLength;
//    edgeLength = _edgeLength;
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                box_vertex[i][j][k] = ofVec3f(i*50 -25, j*50 -25, k*50 -25);
            }
        }
    }
    
//    ball settings
    ball.set(1,8);
    ball.setPosition(0,0,0);
    ballVec = ofVec3f(ofRandom(0.3,0.6), ofRandom(0.3,0.6), ofRandom(0.3,0.6));
    
    shutterBall.set(1,8);
    shutterBall.setPosition(10, 10, 10);
    shutterBallVec  = ofVec3f(ofRandom(0.3,0.6), ofRandom(0.3,0.6), ofRandom(0.3,0.6));
    

}

void ofxWireBox::drawWireBox(string text)
{
//    X
    ofDrawLine(box_vertex[0][0][0], box_vertex[1][0][0]);
    ofDrawLine(box_vertex[0][1][0], box_vertex[1][1][0]);
    ofDrawLine(box_vertex[0][0][1], box_vertex[1][0][1]);
    ofDrawLine(box_vertex[0][1][1], box_vertex[1][1][1]);
//    Y
    ofDrawLine(box_vertex[0][0][0], box_vertex[0][1][0]);
    ofDrawLine(box_vertex[1][0][0], box_vertex[1][1][0]);
    ofDrawLine(box_vertex[0][0][1], box_vertex[0][1][1]);
    ofDrawLine(box_vertex[1][0][1], box_vertex[1][1][1]);
//    Z
    ofDrawLine(box_vertex[0][0][0], box_vertex[0][0][1]);
    ofDrawLine(box_vertex[1][0][0], box_vertex[1][0][1]);
    ofDrawLine(box_vertex[0][1][0], box_vertex[0][1][1]);
    ofDrawLine(box_vertex[1][1][0], box_vertex[1][1][1]);

//    additional text
//    ofDrawBitmapString(text, box_vertex[1][0][0]);
//    ofDrawBitmapString("Smile", box_vertex[0][1][0]);
}

void ofxWireBox::ballBounce()
{
//    ball
    ballPos = ball.getPosition();
    if(ballPos.x >= 23 || ballPos.x <= -23){
        ballVec.x = -ballVec.x;
    }
    if(ballPos.y >= 23 || ballPos.y <= -23){
        ballVec.y = -ballVec.y;
    }
    if(ballPos.z >= 23 || ballPos.z <= -23){
        ballVec.z = -ballVec.z;
    }
    ball.setPosition(ofVec3f(ballPos.x + ballVec.x, ballPos.y + ballVec.y, ballPos.z + ballVec.z));
    ball.draw();
    
//    shutterBall
    ofSetColor(100, 100, 100);
    shutterBallPos = shutterBall.getPosition();
    if(shutterBallPos.x >= 23 || shutterBallPos.x <= -23){
        shutterBallVec.x = -shutterBallVec.x;
    }
    if(shutterBallPos.y >= 23 || shutterBallPos.y <= -23){
        shutterBallVec.y = -shutterBallVec.y;
    }
    if(shutterBallPos.z >= 23 || shutterBallPos.z <= -23){
        shutterBallVec.z = -shutterBallVec.z;
    }
    shutterBall.setPosition(ofVec3f(shutterBallPos.x + shutterBallVec.x, shutterBallPos.y + shutterBallVec.y, shutterBallPos.z + shutterBallVec.z));
    shutterBall.draw();
}

bool ofxWireBox::checkBallContacts()
{
    if(abs(ballPos.x - shutterBallPos.x) <= 4 && abs(ballPos.y - shutterBallPos.y) <= 4 && abs(ballPos.z - shutterBallPos.z) <= 4){
        return true;
    }
}

void ofxWireBox::resetVector()
{
    ballVec = ofVec3f(ofRandom(0.3,0.6), ofRandom(0.3,0.6), ofRandom(0.3,0.6));
}

