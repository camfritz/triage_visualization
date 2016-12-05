#include "Doctor.h"
#include "ofMain.h"

Doctor::Doctor() {
	
}

void Doctor::treatPatient(Patient &p, int time) {
		p.timeReceived += time;
		p.timeNeeded -= time;

		if (p.timeNeeded <= 0 && p.timeReceived >= p.max_timeReceived) {
			p.timeNeeded = 0;
			p.timeReceived = p.max_timeReceived;
		}
}

void Doctor::draw(int x, int y) {
	ofSetColor(color);
	ofDrawEllipse(x, y, 175, 175);
	ofSetColor(255, 255, 255);
	ofDrawBitmapString("Doctor ", (x-50), y);
	ofDrawBitmapString(ofToString(doctorNumber), (x + 10), y);
}