#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);

	ofSetCircleResolution(60);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_MULTIPLY);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	vector<ofColor> color_list = { ofColor(255, 0, 0), ofColor(0, 255, 0), ofColor(0, 0, 255) };

	for (int x = -280; x <= 280; x += 80) {

		for (int y = -280; y <= 280; y += 80) {

			for (int i = 0; i < color_list.size(); i++) {

				auto noise_value = glm::vec2(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005), ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005));
			
				float noise_x = 0;
				if (noise_value.x < 0.25) {
				
					noise_x = ofMap(noise_value.x, 0, 0.25, -20, 0);
				}
				else if (noise_value.x > 0.75) {

					noise_x = ofMap(noise_value.x, 0.75, 1.0, 0, 20);
				}
				float noise_y = 0;
				if (noise_value.y < 0.25) {

					noise_y = ofMap(noise_value.y, 0, 0.25, -20, 0);
				}
				else if (noise_value.y > 0.75) {

					noise_y = ofMap(noise_value.y, 0.75, 1.0, 0, 20);
				}

				ofSetColor(color_list[i]);
				ofDrawCircle(glm::vec2(x + noise_x, y + noise_y), 15);
			}
		}
	}
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}