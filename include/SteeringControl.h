 /**
  * @file      include/SteeringControl.h
  * @brief     Header file for declaring the class SteeringControl,its attributes and its methods
  *            along with class SteeringControlOutput, class Point and their data members
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

#ifndef INCLUDE_STEERINGCONTROL_H_
#define INCLUDE_STEERINGCONTROL_H_
#include<iostream>
#include "../include/SteeringControlOutput.h"
#include "../include/Point.h"
#include "../include/virtualPoint.h"
using std::cout;
using std::endl;
using std::cin;


 /**
  * @brief   class SteeringControl is declared with its four double type private data members
  *          (wheelbase, trackwidth, cgz, vehicleVelocity) and
  *          four Point(class)type data members (Target, VehFront, VehRight, VehLeft)
  *          class SteeringControl has seven methods :  compute_and_update_coordinate
  *                                                     set_target_and_veh_velocity
  *                                                     get_distance
  *                                                     has_reached_target,
  *                                                     get_front_coordinate,
  *                                                     get_left_coordinate,
  *                                                     get_right_coordinate
  */
class SteeringControl {
 private:
  virtualPoint
  &Target;
    double
      vehicleVelocity,
      wheelbase,
      trackwidth,
      cgz;
    Point
      VehFront,
      VehRight,
      VehLeft;

 public:
    /** constructor**/
    SteeringControl(virtualPoint &, double);
    /** destructor**/
    ~SteeringControl();
   /**
    * @brief   method of the class SteeringControl to return the individual drive wheels velocities,
    *          steering angle and the coordinate position of the wheels after dt time period,
    *          based upon the user input of target coordinate and vehicle velocity
    *          and vehicle velocity.
    * @details The method considers a real time latency of 0.01 sec.The first statement averages the
    *          of the left wheel coordinate and the right wheel coordinate to define a Point(class)
    *          VehicleAxleCenter.
    *          The "XFrontVelUnitComp" computes the X component of front-wheel direction unit vector
    *          whereas the YFrontVelUnitComp calculates the Y component of front-wheel direction unit
    *          vector. Similarly,XVehOrientComp,YVehOrientComp computes the X and Y component of the
    *          vehicle orientation(direction the of the front wheel from the center of the rear
    *          wheels).
    *          VehOrientAngle and ApproachAngle are calculated by taking tan inverse(atan2) of Y and X
    *          component of vehicle orientation and front wheel direction unit vector.
    *          A Steering angle Constraint is defined based upon the minimum value between 30 degree
    *          and the steering angle for a given velocity which can cause vehicle to tuple. The lower
    *          of two is chosen as steering angle constraint.
    *          The Steering angle is then calculated by substracting the ApproachAngle to VehOrientAngle.
    *          A positive value of steering angle indicates vehicle turning toward right direction
    *          (counter-clockwise), whereas the the negative value of the steering angle indicates
    *          vehicle turning toward left direction (clockwise direction).
    *          It is then checked whether the steeringAngle is greater than the steeringAngleConstraint.
    *          If the the magnitude of the steering angle is greater than the magnitude of steering
    *          angle constatint,the  SteeringAngleConstraint is set as the Steering Angle.
    *          vehicleFrontVelocity is computed from the wheelbase, vehicleVelocity SteeringAngle.
    *          AngularVelocity is computed by vehicleFrontVelocity, SteeringAngle and wheelbase.
    *          LeftWheelSpeed and RightWheelSpeed is then calculated from the vehicleVelocity,
    *          AngularVelocity and the trackwidth.
    *          The coordinate of the front wheel(VehFront) is then computed by adding the delta change
    *          after dt time to its existing value. Similarly,the coordinate of the axlecenter
    *          (VehAxleCenter) is then computed by adding the delta change after dt time to its existing
    *          value.
    *          LeftWheel coordinate and right wheel coordinate is then computed from the vehAxleCenter,
    *          VehOrientAngle and AngularVelocity.
    *          The function then returns the  SteeringControlOutput(class) MyOutput having datamembers
    *          LeftWheelSpeed, RightWheelSpeed and SteeringAngle.
    * @param   void
    * @return  returns the  SteeringControlOutput(class) MyOutput having data members
    *          LeftWheelSpeed, RightWheelSpeed and SteeringAngle.
    */
    SteeringControlOutput compute_and_update_coordinate();

   /**
    * @brief   set_vehicle_dimension : takes the input from user and stores it
    * @details Takes the three parameter and stores the value in the data members of SteeringControl
    * @param   wheelbase- wheelbase of the vehile
    * @param   trackwidth of the vehicle
    * @param   cgz - cgz of the vehicle
    * @return  void
    */
    void set_vehicle_dimension(double, double, double);

   /**
    * @brief   get_distance : calculates distance
    * @details calculates the distance between two Points a and b using pythagoras theorum.
    * @param   virtualPoint(class) & a
    * @param   virtualPoint(class) & b
    * @return  double distance betwen the two points.
    */
    double get_distance(virtualPoint &, virtualPoint &);

    /**
    * @brief   has_reached_target :checks for condition
    * @details returns true if the front wheel of the vehicle is within 1 unit radius of the defined
               target.
      @param   void
    * @return  bool
    */
    bool has_reached_target();

    /**
    * @brief   get_front_coordinate : method to return front coordinate
    * @details This method of class SteeringControl returns the x,y coordinates of the front
    *           wheel.The values are passed int the vector xfront and yfront to plot the front wheel
    *           trajectory path.
    * @param   void
    * @return  Point(class) VehFront having two datamembers with x and y value of the front wheel
    */
    Point get_front_coordinate();

   /**
    * @brief   get_left_coordinate : method to return left coordinate
    * @details This method of class SteeringControl returns the x,y coordinates of the left
    *           wheel.The values are passed int the vector xleft and yleft to plot the left wheel
    *           trajectory path.
    * @param   void
    * @return  Point(class) VehLeft having two datamembers with x and y value of the left wheel
    */
    Point get_left_coordinate();

    /**
    * @brief   get_right_coordinate : method to return right coordinate
    * @details This method of class SteeringControl returns the x,y coordinates of the right
    *           wheel.The values are passed int the vector xright and yright to plot the right wheel
    *           trajectory path.
    * @param   void
    * @return  Point(class) VehRight having two datamembers with x and y value of the right wheel
    */
    Point get_right_coordinate();
};
#endif  // INCLUDE_STEERINGCONTROL_H_
