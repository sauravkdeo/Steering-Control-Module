 /**
  * @file      test/test.cpp
  * @brief     Tests compute_and_update_coordinateTest, get_front_coordinateTest,
  *            get_left_coordinateTest, get_right_coordinateTest method and get_distanceTest methods
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
#include <gtest/gtest.h>
/*#include <gmock/gmock.h>*/
#include "../include/Point.h"


TEST(PointTest, get_xTest) {
Point Test_a;
  Test_a.set_x(10);
  EXPECT_EQ(10, Test_a.get_x());
}

 /**
  * @brief Tests get_front_coordinate method
  */

 /**
  * @brief Tests get_left_coordinate method
  */
TEST(PointTest, get_yTest) {
  Point Test_a;
    Test_a.set_y(10);
    EXPECT_EQ(10, Test_a.get_y());
}

