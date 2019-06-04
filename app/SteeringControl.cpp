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
#include <math.h>
#include <algorithm>
#include <iostream>
#include "../include/SteeringControl.h"

#define g 9.80665

using std::cout;
using std::endl;
using std::cin;


/**
 *@brief  Constructor for class SteeringControl
 */
SteeringControl::SteeringControl(virtualPoint & vpoint,
                                 double vehiclevelocityvalue)
: Target(vpoint), vehicleVelocity(vehiclevelocityvalue) {
  wheelbase = 3;
  trackwidth = 2;
  cgz = 0.5;
  vehicleVelocity = 0;
  VehFront.set_x(0);
  VehFront.set_y(wheelbase);
  VehRight.set_x(trackwidth/2);
  VehRight.set_y(0);
  VehLeft.set_x(-trackwidth/2);
  VehLeft.set_y(0);
}

/**
 *@brief  Destructor for class SteeringControl
 */
SteeringControl::~SteeringControl() {
}


SteeringControlOutput SteeringControl::compute_and_update_coordinate() {
  SteeringControlOutput MyOutput;

/**
 *@brief  VehOrientAngle and ApproachAngle is calculated
 */
  double const dt = 0.01;
  Point  VehAxleCenter;
  VehAxleCenter.set_x((VehLeft.get_x()+VehRight.get_x())/2);
  VehAxleCenter.set_y((VehLeft.get_y()+VehRight.get_y())/2);
  double XFrontVelUnitComp = (Target.get_x() - VehFront.get_x())/
        get_distance(Target, VehFront);
  double YFrontVelUnitComp = (Target.get_y() - VehFront.get_y())/
        get_distance(Target, VehFront);
  double XVehOrientComp = (VehFront.get_x()-VehAxleCenter.get_x())/
        get_distance(VehFront, VehAxleCenter);
  double YVehOrientComp = (VehFront.get_y()-VehAxleCenter.get_y())/
        get_distance(VehFront, VehAxleCenter);
  double VehOrientAngle = atan2(YVehOrientComp, XVehOrientComp);
  double ApproachAngle = atan2(YFrontVelUnitComp, XFrontVelUnitComp);

/**
 *@brief  SteeringAngleConstraint is calculated and implemented
 */
  double SteeringAngleConstraint =
        std::min(M_PI/6, asin(g*trackwidth*wheelbase/
                            (2*cgz*vehicleVelocity*vehicleVelocity)));
    MyOutput.set_steering_angle(ApproachAngle-VehOrientAngle);
  if (MyOutput.get_steering_angle()> M_PI) {
    MyOutput.set_steering_angle(-(2*M_PI-(MyOutput.get_steering_angle())));
    }
  if (MyOutput.get_steering_angle()< (-M_PI)) {
     MyOutput.set_steering_angle((2*M_PI-(MyOutput.get_steering_angle())));
     }
  if (MyOutput.get_steering_angle() > SteeringAngleConstraint) {
    MyOutput.set_steering_angle(SteeringAngleConstraint);
    }
  if (MyOutput.get_steering_angle() < 0 &&
      MyOutput.get_steering_angle() < -SteeringAngleConstraint) {
    MyOutput.set_steering_angle(-SteeringAngleConstraint);
       }
/**
  *@brief  vehicleFrontVelocity is calculated from vehicleVelocity,SteeringAngle and wheelbase
  */
  double vehicleFrontVelocity =
       ((wheelbase*cos(M_PI-MyOutput.get_steering_angle()))+
       (pow((pow(wheelbase*cos(M_PI-MyOutput.get_steering_angle()), 2))+
       (pow((vehicleVelocity*dt), 2)+2*vehicleVelocity*wheelbase*dt), 0.5)))/dt;
  double AngularVelocity =
        vehicleFrontVelocity * sin(MyOutput.get_steering_angle())/wheelbase;
  MyOutput.set_left_wheel_speed(
        vehicleVelocity - (trackwidth*AngularVelocity/2));
  MyOutput.set_right_wheel_speed(
        vehicleVelocity + (trackwidth*AngularVelocity/2));

/**
  * Updates the coordinates of VehFront ,VehAxleCenter,VehLeft,VehLeft and VehRight based on the
  * vehiclevelocity,steering angle,orientaion angle
  */

  VehFront.set_x(VehFront.get_x()+ vehicleFrontVelocity*dt*
        cos(VehOrientAngle+MyOutput.get_steering_angle()));
  VehFront.set_y(VehFront.get_y() + vehicleFrontVelocity*dt *
        sin(VehOrientAngle+MyOutput.get_steering_angle()));
  VehAxleCenter.set_x(VehAxleCenter.get_x() +
            vehicleVelocity * dt * cos(VehOrientAngle+AngularVelocity*dt));
  VehAxleCenter.set_y(VehAxleCenter.get_y() +
           vehicleVelocity * dt * sin(VehOrientAngle+AngularVelocity*dt));
  VehLeft.set_x(VehAxleCenter.get_x()
      -trackwidth/2 * sin(VehOrientAngle+AngularVelocity*dt));
  VehLeft.set_y(VehAxleCenter.get_y()
      +trackwidth/2 * cos(VehOrientAngle+AngularVelocity*dt));
  VehRight.set_x(VehAxleCenter.get_x()
      +trackwidth/2* sin(VehOrientAngle+AngularVelocity*dt));
  VehRight.set_y(VehAxleCenter.get_y()
      -trackwidth/2* cos(VehOrientAngle+AngularVelocity*dt));
  return MyOutput;
}

void SteeringControl::set_vehicle_dimension(double WheelbaseValue,
 double TrackwidthValue, double cgzValue) {
  wheelbase = WheelbaseValue;
  trackwidth = TrackwidthValue;
  cgz = cgzValue;
}


bool SteeringControl::has_reached_target() {
  return((Target.get_x()-VehFront.get_x())
      *(Target.get_x()-VehFront.get_x())+
      (Target.get_y()-VehFront.get_y())*
      (Target.get_y()-VehFront.get_y()) <= 1);
}

double SteeringControl::get_distance(virtualPoint & a, virtualPoint & b) {
  return sqrt(pow((a.get_x()-b.get_x()), 2)+pow((a.get_y()-b.get_y()), 2));
}

Point SteeringControl::get_front_coordinate() {
  return VehFront;
}

Point SteeringControl::get_left_coordinate() {
  return VehLeft;
}

Point SteeringControl::get_right_coordinate() {
  return VehRight;
}
