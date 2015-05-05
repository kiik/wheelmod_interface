/**
 * @file RTXMotor.cpp
 * @brief Robotex wheelmod firmware communication interface implementation
 *
 * @author Meelik Kiik
 * @date April, 2015
 * @version 0.1
 */

#include <thread>
#include <iostream>

#include "RTXMotor.hpp"


RTXMotor::RTXMotor() {

}

RTXMotor::RTXMotor(std::string deviceID) {
  //TODO: User true motor id and search its device from usb bus
  init(deviceID);
}

RTXMotor::~RTXMotor() {

}

void RTXMotor::init(std::string _deviceID) {
  deviceID = _deviceID;
  ID = "X";

  serial.SetBaudRate(SerialStreamBuf::BAUD_115200);
  serial.SetCharSize(SerialStreamBuf::CHAR_SIZE_8);
  serial.SetNumOfStopBits(1);
  serial.Open(deviceID, std::ios::in|std::ios::out);


  readID();
}

void RTXMotor::readID() {
  serial << '?' << endl;
  
  ID = "";
  char c;
  for(uint8_t i=0; c != '\n'; i++) {
    if(i > 0) ID += c;
    serial.get(c);
  }

}

string RTXMotor::getID() {
  return ID;
}

void RTXMotor::setSpeed(int8_t v) {
  serial << RTXWheelmod::setSpeedCMD << std::to_string(v) << endl;
}

void RTXMotor::stop() {
  serial << RTXWheelmod::setSpeedCMD << "0" << endl;
}

void RTXMotor::runTest() {
  cout << "Testing " << ID << " ('" << deviceID << "')" << endl;
  setSpeed(20);
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  setSpeed(-20);
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  stop();
}
