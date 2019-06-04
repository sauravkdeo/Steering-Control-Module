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
#ifndef INCLUDE_VIRTUALPOINT_H_
#define INCLUDE_VIRTUALPOINT_H_
#include<iostream>
using std::cout;
using std::endl;
using std::cin;


class virtualPoint {
 public:
     /*virtual virtualPoint();*/
      /** destructor**/
     virtual ~virtualPoint() {}

  /**
   * @brief   get_x
   * @details returns the stored value of X coordinate of the the point
   * @param   void
   * @return  double
   */
virtual double get_x() = 0;

  /**
   * @brief   set_x
   * @details set the new value of X Coordinate in "X" datamember
   * @param   double
   * @return  void
   */
  virtual void set_x(double x_coordinate_value)= 0;

  /**
   * @brief   get_y
   * @details returns the stored value of Y coordinate of the the point
   * @param   void
   * @return  double stored value of Y Coordinate from "Y" is returned
   */
  virtual double get_y() = 0;

  /**
   * @brief   set_y
   * @details set the new value of Y Coordinate in "Y" datamember
   * @param   double
   * @return  void
   */
  virtual void set_y(double y_coordinate_value) = 0;
};
#endif  // INCLUDE_VIRTUALPOINT_H_
