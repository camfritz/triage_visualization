#include "ofApp.h"
#include <iostream>


//insert new patient
void ofApp::insertPatient() {
	waitingRoom.push(Patient());
	for (int check = 0; check < treatmentList.size(); check++) {
		if (waitingRoom.top().severity == treatmentList[check].severity) {
			waitingRoom.pop();
			waitingRoom.push(Patient());
		}
	}
}

//build treatment list
void ofApp::build_treatmentList() {
	while (treatmentList.size() < 3) {	//max # of patients to be treated at one time
		if (waitingRoom.size() > 0) {
			treatmentList.push_back(waitingRoom.top());	//push waiting room into treatment list
			waitingRoom.pop();
		}
		if (waitingRoom.size() == 0) {	//break if waiting room is empty
			break;
		}
	}
	if (treatmentList.size() == 3 && !waitingRoom.empty()) {	//handle patients not being treated in waiting room
		nextWaiting = waitingRoom.top();
		for (int bump = 0; bump < 3; bump++) {
			if (waitingRoom.top().severity > treatmentList[bump].severity) {
				waitingRoom.push(treatmentList[bump]);
				treatmentList[bump] = waitingRoom.top();
				waitingRoom.pop();
				nextWaiting = waitingRoom.top(); //nextWaiting is highest priority patient in waiting room
			}
		}
	}
}

//update treatment list 
void ofApp::update_treatmentList() {
	for (int i = 0; i < treatmentList.size(); i++) {
		if ((treatmentList[i].remainingLife == 0) || treatmentList[i].timeNeeded == 0) {
			treatmentList.erase(treatmentList.begin() + i);
			for (int r = 0; r < treatmentList.size(); r++) {
				waitingRoom.push(treatmentList[r]);
			}
			treatmentList.clear();
			build_treatmentList();
		}
	}

	for (int patientIndex = 0; patientIndex < treatmentList.size(); patientIndex++) {	//treat current patients
		if (patientIndex == 0) {
			if (treatmentList[patientIndex].severity >= 45) {
				first.treatPatient(treatmentList[patientIndex], 10);
			}
			else {
				first.treatPatient(treatmentList[patientIndex], 5);
			}
		}
		else if (patientIndex == 1) {
			second.treatPatient(treatmentList[patientIndex], 2);
		}
		else if (patientIndex == 2) {
			third.treatPatient(treatmentList[patientIndex], 1);
		}
	}

	for (int u = 0; u < treatmentList.size(); u++) {
		treatmentList[u].update();
	}
	nextWaiting.update();
	waitingRoom.push(nextWaiting);
	nextWaiting = waitingRoom.top();
	waitingRoom.pop();
}
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(0, 0, 0);
	first.doctorNumber = 1;
	second.doctorNumber = 2;
	third.doctorNumber = 3;
}

//--------------------------------------------------------------
void ofApp::update() {
	double newPatient_chance = ofRandom(0, 1);
	if ((ofGetFrameNum() % 1000) == 0 && newPatient_chance <= 0.80) {
		insertPatient();
	}
	build_treatmentList();
	update_treatmentList();
}

//--------------------------------------------------------------
void ofApp::draw() {	//draw all current patients
	for (int i = 0; i < treatmentList.size(); i++) {
		if (i == 0) {
			treatmentList[i].draw(500, 100);
		}
		else if (i == 1) {
			treatmentList[i].draw(500, 300);
		}
		else if (i == 2)
			treatmentList[i].draw(500, 500);
	}

	//draw doctors
	first.draw(800, 100);
	second.draw(800, 300);
	third.draw(800, 500);

	//draw next waiting patient
	if ((!waitingRoom.empty())) {
		ofDrawBitmapString("Next Waiting Patient: ", 100, 550);
		nextWaiting.draw(250, 650);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	insertPatient();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	treatmentList[0].remainingLife = 0;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
