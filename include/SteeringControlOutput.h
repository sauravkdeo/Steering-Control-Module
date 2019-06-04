/**
 * @file      app/SteeringControl.cpp
 * @brief     Takes target coordinate and vehicle velocity as input and provides individual
 *            wheel speed, steering angle, new coordinates of the vehicle wheel endafter a dt time
 *            ,such that the vehicle movement shall be toward the target point.The standard time
 *            latency is considered to be 0.01 sec.
 * @author    Saurav Kumar
 * @copyright 2018
 *
 **BSD 3-Clause License
 *
 *Copyright (c) 2018, Saurav Kumar
 *All rights reserved.
 *
 *Redistribution and use in source and binary forms, with or without
 *modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 *  and/or other materials provided with the distribution.
 *
 * Neither the name of the copyright holder nor the names of its
 *  contributors may be used to endorse or promote products derived from
 *  this software without specific prior written permission.
 *
 *THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 *DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 *OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/**
  * @brief   class SteeringControlOutput is declared with its three data members namely
  *          LeftWheelSpeed, RightWheelSpeed and SteeringAngle
  *          and have six methods : get_left_wheel_speed
  *                                 set_left_wheel_speed
  *                                 get_right_wheel_speed
  *                                 set_right_wheel_speed
  *                                 get_steering_angle
  *                                 set_steering_angle
  */
#ifndef INCLUDE_STEERINGCONTROLOUTPUT_H_
#define INCLUDE_STEERINGCONTROLOUTPUT_H_
class SteeringControlOutput {
 private:
  double
    LeftWheelSpeed,
    RightWheelSpeed,
    SteeringAngle;

 public:
  /** constructor**/
  SteeringControlOutput();
      /** destructor**/
  ~SteeringControlOutput();
  /**
   * @brief   get_left_wheel_speed
   * @details returns the stored value of left wheel speed
   * @param   void
   * @return  double stored value of left wheel speed from "LeftWheelSpeed" is returned
   */
  double get_left_wheel_speed();

  /**
   * @brief   set_left_wheel_speed : stores the new  value for left wheel speed
   * @details stores the new  value of left wheel speed in "LeftWheelSpeed".
   * @param   double
   * @return  void
   */
  void set_left_wheel_speed(double);

  /**
   * @brief   get_left_wheel_speed : returns the stored value of right wheel speed
   * @details returns the stored value of right wheel speed
   * @param   void
   * @return  double stored value of right wheel speed from "RighttWheelSpeed" is returned.
   */
  double get_right_wheel_speed();

  /**
   * @brief   set_right_wheel_speed : stores the new  value for right wheel speed
   * @details stores the new  value of right wheel speed in "rightWheelSpeed".
   * @param   double
   * @return  void
   */
  void set_right_wheel_speed(double);

  /**
   * @brief   get_steering_angle
   * @details returns the stored value of steering angle in radians
   * @param   void
   * @return  double stored value of steering angle from "SteeringAngle" is returned
   */
  double get_steering_angle();

  /**
   * @brief   set_steering_angle : stores the new  value for steering angle
   * @details stores the new  value of steering angle in "SteeringAngle".
   * @param   double
   * @return  void
   */
  void set_steering_angle(double);
};
#endif  // INCLUDE_STEERINGCONTROLOUTPUT_H_
