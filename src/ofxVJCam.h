//  ofVJCam.hpp
//  MediaArtPractice
//
//  Created by Sota Tanaka on 2022/01/18.
//
#pragma once
#include <stdio.h>
#include "ofMain.h"

class ofxVJCam : public ofEasyCam{
    public :
        void setRandomPosition();
    
        ofVec3f curPos;
        ofVec3f nextPos;
        ofVec3f vector;
    
};

