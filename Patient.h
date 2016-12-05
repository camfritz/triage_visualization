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
		ofColor color;
		
		friend bool operator<(Patient left, Patient right);
		Patient();
		void treatPatient(int time);
		void update();
		void adjustSeverity();
		void adjustColor();
		void draw(int x, int y);
};