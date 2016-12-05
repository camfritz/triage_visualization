#pragma once
#include "ofMain.h"
#include "Patient.h"
using namespace std;

Patient::Patient() {
	severity = ofRandom(1, 50);
	remainingLife = ofRandom(300, 20000);
	timeNeeded = ofRandom(500, 20000);
	timeReceived = 0;

	max_timeReceived = timeNeeded;
}

bool operator<(Patient left, Patient right) {
	return left.severity < right.severity;
}
/*
void Patient::treatPatient(int time) {
	timeReceived += time;
	timeNeeded -= time;

	if (timeNeeded <= 0 && timeReceived >= max_timeReceived) {
		timeNeeded = 0;
		timeReceived = max_timeReceived;
	}
}
*/

void Patient::update() {
	if (remainingLife != 0) {
		remainingLife -= 1;
	}
}

void Patient::draw(int x, int y) {
	ofSetColor(color);
	ofDrawEllipse(x, y, 175, 175);
	ofSetColor(255, 255, 255);
	ofDrawBitmapString("Life Remaining: ", (x-150), (y-50));
	if (remainingLife == 0) {
		ofDrawBitmapString("DEAD", x, (y-50));
	}
	else { 
		ofDrawBitmapString(ofToString(remainingLife), x, (y-50)); 
	}
	ofDrawBitmapString("Treatment Time Needed: ", (x-200), (y-30));
	ofDrawBitmapString(ofToString(timeNeeded), x, (y-30));
	ofDrawBitmapString("Treatment Time Received: ", (x-200), (y-10));
	ofDrawBitmapString(ofToString(timeReceived), x, (y-10));
	ofDrawBitmapString("Severity: ", (x - 130), (y + 10));
	ofDrawBitmapString(ofToString(severity), x, (y+10));
}