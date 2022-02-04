//
//  WireCube.hpp
//  MediaArtPractice
//
//  Created by Sota Tanaka on 2022/01/17.
//

#pragma once
#include <stdio.h>
#include "ofMain.h"

class ofxWireBox: public ofNode
{
    public :
        ofVec3f box_vertex[2][2][2];
        ofxWireBox();
        void drawWireBox(string text);
        void ballBounce();
        bool checkBallContacts();
        void resetVector();
    
        ofSpherePrimitive ball;
        ofSpherePrimitive shutterBall;
        
        ofVec3f ballPos;
        ofVec3f ballVec;
        
        ofVec3f shutterBallPos;
        ofVec3f shutterBallVec;
        
        ofVec3f mappedPos;
};
