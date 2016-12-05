#pragma once

#include "ofMain.h"
#include "Patient.h"
#include "Doctor.h"
#include <queue>
#include <vector>

class ofApp : public ofBaseApp{
	public:
		Patient nextWaiting;
		Doctor first;
		Doctor second;
		Doctor third;
		std::vector<Patient> treatmentList;
		std::priority_queue<Patient> waitingRoom;
		void setup();
		void update();
		void draw();
		void update_treatmentList();
		void build_treatmentList();
		void insertPatient();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
