//  ofVJCam.cpp
//  MediaArtPractice
//
//  Created by Sota Tanaka on 2022/01/18.
//

#include "ofxVJCam.h"

void ofxVJCam::setRandomPosition(){
    curPos = this->getPosition();
    nextPos = ofVec3f(ofRandom(-100, 100), ofRandom(-100, 100), ofRandom(-100, 100));
    this->setPosition(nextPos);
}

