#include "ofApp.h"
#include <iostream>

//build treatment list
void ofApp::build_treatmentList() {
	while (treatmentList.size() < 3) {
		if (waitingRoom.size() > 0) {
			treatmentList.push_back(waitingRoom.top());
			waitingRoom.pop();
		}
		if (waitingRoom.size() == 0) {
			break;
		}
	}
	if (treatmentList.size() == 3 && !waitingRoom.empty()) {
		nextWaiting = waitingRoom.top();
		for (int bump = 0; bump < 3; bump++) {
			if (waitingRoom.top().severity > treatmentList[bump].severity) {
				waitingRoom.push(treatmentList[bump]);
				treatmentList[bump] = waitingRoom.top();
				waitingRoom.pop();
				nextWaiting = waitingRoom.top();
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
	/*
	for (int u = 0; u < treatmentList.size(); u++) {
		treatmentList[u].update();
	}
	*/

	for (int treat = 0; treat < treatmentList.size(); treat++) {
		if (treat == 0) {
			first.treatPatient(treatmentList[treat], 1);
		}
		else if (treat == 1) {
			second.treatPatient(treatmentList[treat], 1);
		}
		else if (treat == 2) {
			third.treatPatient(treatmentList[treat], 1);
		}
	}

	for (int u = 0; u < treatmentList.size(); u++) {
		treatmentList[u].update();
	}
	nextWaiting.update();
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
	if ((ofGetFrameNum() % 500) == 0) {
		waitingRoom.push(Patient());
		for (int check = 0; check < treatmentList.size(); check++) {
			if (waitingRoom.top().severity == treatmentList[check].severity) {
				waitingRoom.pop();
				waitingRoom.push(Patient());
			}
		}
	}
	build_treatmentList();
	update_treatmentList();
	/*
	bool second_drawn = false;
	bool third_drawn = false;
	if ((ofGetFrameNum() % 3000) == 0) {
		if (updateList.size() < 3) {
			updateList.push_back(Patient());
			waitingRoom.push(updateList.back());
		}
	}

	if (first.severity != waitingRoom.top().severity) {
		first = waitingRoom.top();
	}
	first.update();

	for (int i = 0; i < updateList.size(); i++) {
		waitingRoom.pop();
		if (second_drawn == false) {
			second = waitingRoom.top();
			second_drawn = true;
		}
		if ((second_drawn == true) && (third_drawn == false)) {
			waitingRoom.pop();
			third = waitingRoom.top();
			third_drawn = true;
		}
	}
	for (int i = 0; i < updateList.size(); i++) {
		waitingRoom.push(updateList[i]);
	}
	second.update();
	third.update();

	if (first.remainingLife == 0 || first.timeNeeded == 0) {
		updateList.clear();
		waitingRoom.pop();
		for (int i = 0; i < waitingRoom.size(); i++) {
			updateList.push_back(waitingRoom.top());
			waitingRoom.pop();
		}
		for (int i = 0; i < updateList.size(); i++) {
			waitingRoom.push(updateList[i]);
		}
	}*/
}

//--------------------------------------------------------------
void ofApp::draw() {
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

	first.draw(800, 100);
	second.draw(800, 300);
	third.draw(800, 500);
	if ((!waitingRoom.empty())) {
		if (waitingRoom.top().severity == nextWaiting.severity) {
			nextWaiting.draw(250, 650);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	treatmentList[0].remainingLife = 0;
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
