/**
 * @file RTXMotorController.cpp
 * @brief UT robotex robot movement controller implementation
 *
 * @author Meelik Kiik
 * @date April, 2015
 * @version 0.1
 */

#include <iostream>
#include "RTXMotorController.hpp"

//TODO: Implement direction modes to allow the full usage of rtxrobots' structur

RTXMotorController::RTXMotorController() {

}

RTXMotorController::~RTXMotorController() {

}

uint8_t RTXMotorController::init() {
  m_motorCount = 3;
  m_Motors = new RTXMotor[m_motorCount];
  //TODO: error checking
  //TODO: dynamic motor location assignment
  m_Motors[0].init("/dev/ttyACM7");
  m_Motors[1].init("/dev/ttyACM8");
  m_Motors[2].init("/dev/ttyACM9");

  string id;
  for(uint8_t i=0; i < m_motorCount; i++) {
    id = m_Motors[i].getID();

    // Motor mapping
    if(id.find("id:1") != -1) {
      frw_ixs[0] = i;
    } else if(id.find("id:2") != -1) {
      frw_ixs[1] = i;
    } else if(id.find("id:3") != -1) {
      bck_ix = i;
    } else {
      cout << "Unmapped motor id " << id << endl;
    }
  }
}

void RTXMotorController::setSpeed(int8_t val) {
  m_Motors[frw_ixs[0]].setSpeed(-1*val);
  m_Motors[frw_ixs[1]].setSpeed(val);
}

void RTXMotorController::turn(int8_t val) {
  m_Motors[bck_ix].setSpeed(val);
  m_Motors[frw_ixs[0]].setSpeed(val);
  m_Motors[frw_ixs[1]].setSpeed(val);
}

void RTXMotorController::stop() {
  for(uint8_t i=0; i < m_motorCount; i++) {
    m_Motors[i].stop();
  }
}

void RTXMotorController::runTests() {
  for(uint8_t i=0; i < m_motorCount; i++) {
    m_Motors[i].runTest();
  }
}
