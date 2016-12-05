#pragma once
#include "Patient.h"

class Doctor {
	public:
		int doctorNumber;
		ofColor color = ofColor(ofRandom(0, 150), ofRandom(0, 150), ofRandom(0, 150));
		void treatPatient(Patient &p, int time);
		Doctor();
		void draw(int x, int y);
};