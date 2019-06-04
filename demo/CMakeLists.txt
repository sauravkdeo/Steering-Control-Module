add_executable(demo main.cpp ../app/Point.cpp ../app/SteeringControlOutput.cpp ../app/SteeringControl.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

