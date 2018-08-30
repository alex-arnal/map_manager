cmake_minimum_required(VERSION 2.8.3)
project(map_manager)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  message_generation
)


## Generate services in the 'srv' folder
add_service_files(
    DIRECTORY srv
    FILES
    SetMap.srv
)

generate_messages(
DEPENDENCIES
   std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES map_manager
#  INCLUDE_DIRS include
#  LIBRARIES map_manager
#  CATKIN_DEPENDS rospy
#  DEPENDS system_lib
)


###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(map_manager src/map_manager.cpp)

target_link_libraries(map_manager
   ${catkin_LIBRARIES}
)

install(
  TARGETS map_manager
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
