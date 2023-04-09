cmake_minimum_required(VERSION 3.0.2)
project(robowars)

find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
)

generate_messages(
  DEPENDENCIES std_msgs  # Or other packages containing msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

catkin_install_python(
  PROGRAMS
  src/robot_control
  src/robot_control_v2
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

