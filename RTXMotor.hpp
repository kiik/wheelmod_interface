/**
 * @file RTXMotor.hpp
 * @brief Robotex wheelmod firmware communication interface declaration
 *
 * @author Meelik Kiik
 * @date April, 2015
 * @version 0.1
 */

#ifndef RTXMOTOR_H_
#define RTXMOTOR_H_

#include <stdint.h>
#include <SerialStream.h>

using namespace std;
using namespace LibSerial;


namespace RTXWheelmod {
 const std::string setSpeedCMD = "sd"; //sdX - X = speed
}

class RTXMotor {
public:
  // Constructors & Destructors
  RTXMotor();
  RTXMotor(string);
  ~RTXMotor();

  // Methods
  void init(string);
  string getID();
  void readID();
  void setSpeed(int8_t);
  void stop();

  void runTest();
private:
  string ID;
  string deviceID;
  SerialStream serial;
};

#endif // RTXMOTOR_H_
