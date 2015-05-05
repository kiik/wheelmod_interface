/**
 * @file RTXMotorController.hpp
 * @brief UT robotex robot movement controller declaration
 *
 * @author Meelik Kiik
 * @date April, 2015
 * @version 0.1
 */

#ifndef RTXMOTOR_CONTROLLER_H_
#define RTXMOTOR_CONTROLLER_H_

#include "RTXMotor.hpp"

class RTXMotorController
{
public:
  // Controllers & Destructors
  RTXMotorController();
  ~RTXMotorController();

  // Methods
  uint8_t init();
  void setSpeed(int8_t);
  void turn(int8_t);
  void stop();

  void runTests();
private:
  RTXMotor* m_Motors;
  uint8_t m_motorCount;

  uint8_t frw_ixs[2]; // Forward motor indexes
  uint8_t bck_ix; // Third motor index
};

#endif // RTXMOTOR_CONTROLLER_H_
