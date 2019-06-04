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
#include <gmock/gmock.h>
#include "../include/SteeringControl.h"
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;


class MockPoint :public virtualPoint {
 public:
     MOCK_METHOD0(get_x, double());
     MOCK_METHOD1(set_x, void(double x_coordinate_value));
     MOCK_METHOD0(get_y, double());
     MOCK_METHOD1(set_y, void(double y_coordinate_value));
};

 /**
  * @brief Tests compute_and_update_coordinate method
  */
TEST(SteeringControlTest, compute_and_update_coordinateTest) {
MockPoint mockpoint;
SteeringControl TestCar(mockpoint, 10);
EXPECT_CALL(mockpoint, get_x())
.Times(AtLeast(1));
/*.WillRepeatedly(Return(0));*/
EXPECT_CALL(mockpoint, set_x(0))
.Times(AtLeast(0));
EXPECT_CALL(mockpoint, set_y(2))
.Times(AtLeast(0));
EXPECT_CALL(mockpoint, get_y())
.Times(AtLeast(1));
TestCar.compute_and_update_coordinate();
}

 /**
  * @brief Tests get_front_coordinate method
  */
TEST(SteeringControlTest, get_front_coordinateTest) {
  Point point;
  point.set_x(0);
  point.set_y(5);
  SteeringControl TestCar(point, 10);
  EXPECT_EQ(0, TestCar.get_front_coordinate().get_x());
  EXPECT_EQ(3, TestCar.get_front_coordinate().get_y());
}

 /**
  * @brief Tests get_left_coordinate method
  */
TEST(SteeringControlTest, get_left_coordinateTest) {
  Point point;
  point.set_x(0);
  point.set_y(5);
  SteeringControl TestCar(point, 10);
  EXPECT_EQ(-1, TestCar.get_left_coordinate().get_x());
  EXPECT_EQ(0, TestCar.get_left_coordinate().get_y());
}

 /**
  * @brief Tests get_right_coordinate method
  */
TEST(SteeringControlTest, get_right_coordinateTest) {
  Point point;
  point.set_x(0);
  point.set_y(5);
  SteeringControl TestCar(point, 10);
  EXPECT_EQ(1, TestCar.get_right_coordinate().get_x());
  EXPECT_EQ(0, TestCar.get_right_coordinate().get_y());
}
/**
 * @brief Tests set_vehicle_dimension method
 */
TEST(SteeringControlTest, set_vehicle_dimensionTest) {
  Point point;
  point.set_x(0);
  point.set_y(5);
  SteeringControl TestCar(point, 10);
  EXPECT_NO_THROW(TestCar.set_vehicle_dimension(5, 3, 1));
}

/**
 * @brief has_reached_target method
 */
TEST(SteeringControlTest, has_reached_targetTest) {
MockPoint mockpoint;
SteeringControl TestCar(mockpoint, 10);
EXPECT_CALL(mockpoint, get_x())
.Times(AtLeast(1))
.WillRepeatedly(Return(0));
EXPECT_CALL(mockpoint, get_y())
.Times(AtLeast(1))
.WillRepeatedly(Return(3));
EXPECT_TRUE(TestCar.has_reached_target());
}

/**
 * @brief get_distance method
 */
TEST(SteeringControlTest, get_distanceTest) {
MockPoint mockpoint;
MockPoint mockpoint_a, mockpoint_b;
SteeringControl TestCar(mockpoint, 10);
EXPECT_CALL(mockpoint_a, get_x())
.Times(AtLeast(1))
.WillRepeatedly(Return(0));
EXPECT_CALL(mockpoint_a, get_y())
.Times(AtLeast(1))
.WillRepeatedly(Return(0));
EXPECT_CALL(mockpoint_b, get_x())
.Times(AtLeast(1))
.WillRepeatedly(Return(3));
EXPECT_CALL(mockpoint_b, get_y())
.Times(AtLeast(1))
.WillRepeatedly(Return(4));
EXPECT_EQ(5, TestCar.get_distance(mockpoint_a, mockpoint_b));
}
