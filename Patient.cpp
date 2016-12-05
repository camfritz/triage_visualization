#pragma once
#include "ofMain.h"
#include "Patient.h"
using namespace std;

Patient::Patient() {
	severity = 0;
	remainingLife = ofRandom(2000, 20000);
	timeNeeded = ofRandom(1000, 20000);
	timeReceived = 0;
	max_timeReceived = timeNeeded;
	adjustSeverity();
	adjustColor();
}

bool operator<(Patient left, Patient right) {
	return left.severity < right.severity;
}

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

void Patient::adjustSeverity() {
	if (remainingLife <= 5000) {
		severity = 50;
	}
	else if (remainingLife > 5000 && remainingLife <= 15000) {
		severity = ofRandom(25, 49);
	}

	else {
		severity = ofRandom(1, 24);
	}
}

void Patient::adjustColor() {
	if (severity >= 45) {
		color = ofColor(255, 0, 0);
	}
	else if (severity >= 35 && severity < 45) {
		color = ofColor(248, 178, 48);
	}

	else if (severity >= 25 && severity < 35) {
		color = ofColor(248, 205, 48);
	}

	else if (severity >= 15 && severity < 25) {
		color = ofColor(116, 214, 0);
	}

	else if (severity >= 0 && severity < 15) {
		color = ofColor(0, 230, 50);
	}
}