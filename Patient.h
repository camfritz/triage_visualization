#pragma once
using namespace std;
#include "ofMain.h"
class Patient {
	public:
		int severity;
		int timeNeeded;
		int timeReceived;
		int remainingLife;

		int max_timeReceived;
		ofColor color = ofColor(ofRandom(0, 150), ofRandom(0, 150), ofRandom(0, 150));
		
		friend bool operator<(Patient left, Patient right);
		Patient();
		void treatPatient(int time);
		void update();
		void draw(int x, int y);
};