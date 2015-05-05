
/**
 * @file test.c
 * @brief Robotex wheelmod firmware motors controller tests
 *
 * @author Meelik Kiik
 * @date April, 2015
 * @version 0.1
 */


#include <chrono>
#include <thread>

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <iostream>

#include "RTXMotorController.hpp"

using namespace std;
using namespace LibSerial;

RTXMotorController motor;

void test_delay() {
  std::this_thread::sleep_for(std::chrono::milliseconds(1400));
}

void accel_test() {
  // Warning: momentary 6amp draws may occur
  cout << "Accel test" << endl;
  uint16_t i;
  uint16_t last_point = 0;
  uint16_t step = 100;

  uint8_t spd_step = 1;
  uint8_t spd_dir = 1;
  uint8_t spd = 10;

  for(i=0; i < 20000; i++) {
    if(i - last_point > step) {
      spd += spd_step*spd_dir;
      last_point = i;

      if(spd_dir == 1 && i > 14000) {
        spd_dir = -1;
      } else if(spd_dir == -1 && spd <= 10) {
        spd_step = 0;
      }
    }

    motor.setSpeed(spd);
  }
}

void turn_test() {
  cout << "Turn test" << endl;
  motor.turn(0);
  test_delay();
  motor.turn(10);
  test_delay();
  motor.turn(-12);
  test_delay();
}

void move_test() {
  cout << "Move test" << endl;
  motor.setSpeed(0);
  test_delay();
  motor.setSpeed(10);
  test_delay();
  motor.setSpeed(-12);
  test_delay();
}

int main() {
  motor.init();
  //motor.runTests();

  turn_test();
  move_test();
  motor.stop();
  return 0;
}
