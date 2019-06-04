set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    PointTest.cpp
    SteeringControlOutputTest.cpp
    SteeringControlTest.cpp
    ../app/SteeringControl.cpp
    ../app/SteeringControlOutput.cpp
    ../app/Point.cpp
)


target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include cpp-test ../vendor/googletest/googlemock/include
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cpp-test PUBLIC gtest gmock)

