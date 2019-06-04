/**
 * @file      app/main.cpp
 * @brief     Takes target coordinate and vehicle velocity as input and provides individual
 *            wheel speed and steering angle as output until the vehicle has reached the defined
 *            target coordinate.
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
#include <iostream>
#include <vector>
#include "../include/SteeringControl.h"
#define PI 3.14159265

using std::cout;
using std::endl;
using std::cout;
using std::cin;
using std::endl;
using std::vector;




int main() {
/**
* @brief Takes the details of the vehicle parameters such as wheelbase, trackwitdh and the
*        height of center of gravity along with the target coordinate and the vehicle velocity
*/
  double vehicletrackwidth, vehiclewheelbase, centerofgravityheight;
  double targetx, targety, vehiclevelocity;
  cout << "Enter the distance between the front wheel and rear wheel axle :";
  cin >> vehiclewheelbase;
  cout << "Enter the distance between the rear left "
      "wheel and rear right wheel :";
  cin >> vehicletrackwidth;
  cout << "Enter the height of the center of gravity of the vehicle :";
  cin >> centerofgravityheight;
  cout << "Enter the X Coordinate of target location :";
  cin >> targetx;
  cout << "Enter the Y Coordinate of target location :";
  cin >> targety;
  cout << "Enter the vehicle velocity :";
  cin >> vehiclevelocity;

  Point target;
  target.set_x(25);
  target.set_y(25);
/**
 *@brief An object is called of class SteeringControl and its parameters are fed
 */
SteeringControl Vehicle(target, 10);

/**
 *@brief Target and the vehicle velocity is set for the object Vehicle which is taken as input.
 */


/**
 *@brief Loop is run to until the vehicle reach the target coordinate
 */
while (Vehicle.has_reached_target() == false) {
  Vehicle.compute_and_update_coordinate();
    }
return 0;
}
