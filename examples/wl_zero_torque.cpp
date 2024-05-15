/**
 * @file wheel_legged_zero_torque.cpp
 *
 * @brief This file contains the implementation of the WheelLeggedZeroTorque class, which sets the torque of wheel-legged robots to zero.
 *
 * © [2023] LimX Dynamics Technology Co., Ltd. All rights reserved.
 */

#include "wl_controller_base.h"

/**
 * @brief The WheelLeggedZeroTorque class sets the torque of wheel-legged robots to zero.
 */
class WheelLeggedZeroTorque : public ControllerBase
{
public:
  /**
   * @brief Initiates the setting of torque to zero.
   */
  void starting()
  {
    zeroTorque(); // Set torque to zero
  }

private:
  /**
   * @brief Overrides the update function to do nothing, as setting torque to zero does not require continuous updates.
   */
  void update() override
  {
    // No update needed for setting torque to zero
  }
};

/**
 * @brief The main function initializes the WheelLegged instance, creates an instance of WheelLeggedZeroTorque, and sets the torque of the robot to zero.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return int Program exit status.
 */
int main(int argc, char *argv[])
{
  limxsdk::Wheellegged *wl = limxsdk::Wheellegged::getInstance();

  std::string robot_ip = "127.0.0.1";
  if (argc > 1)
  {
    robot_ip = argv[1];
  }
  if (!wl->init(robot_ip))
  {
    exit(1); // Exit if initialization fails
  }

  WheelLeggedZeroTorque ctl;
  ctl.starting(); // Start setting torque to zero

  // Main loop
  while (true)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;
}
