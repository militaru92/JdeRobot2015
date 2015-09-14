cmake_minimum_required(VERSION 2.8.3)
project(RosPCL)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  cv_bridge
  std_msgs
  image_transport
  sensor_msgs
  message_generation
)

find_package(PCL 1.2 REQUIRED)
find_package(OpenCV REQUIRED)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend and a run_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependencies might have been
##     pulled in transitively but can be declared for certainty nonetheless:
##     * add a build_depend tag for "message_generation"
##     * add a run_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

#add_message_files(
 #  FILES
  # RGB_Depth_Image.msg

 #)

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs
# )

 #generate_messages(
 #  DEPENDENCIES
 #  std_msgs
 #  geometry_msgs
 #  sensor_msgs
 #)


###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES RosPCL
  CATKIN_DEPENDS roscpp std_msgs image_transport cv_bridge
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIR}
  /usr/local/include/jderobot
)

link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

find_library(ice_LIBRARY1 Ice)
find_library(ice_LIBRARY2 IceUtil)
find_library(ice_LIBRARY3 IceStorm)
list(APPEND ice_LIBRARIES
    ${ice_LIBRARY1}
    ${ice_LIBRARY2}
    ${ice_LIBRARY3}
)

file(GLOB jderobot_libraries "/usr/local/lib/jderobot/*.so")


## Declare a cpp library
# add_library(RosPCL
#   src/${PROJECT_NAME}/RosPCL.cpp
# )

file(GLOB CPP_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(openni_ros_grabber src/main_ros_grabber.cpp src/RosKinectGrabber.cpp)
#add_dependencies(openni_grabber RosPCL_generate_messages_cpp)
add_executable(openni_ice_interface src/main_ice_interface.cpp)

add_executable(IceRosInterface src/main_ice_grabber.cpp)
add_executable(RosViewer src/main_ros_viewer.cpp src/RosOpenNIViewer.cpp)

 target_link_libraries(openni_ros_grabber
   ${catkin_LIBRARIES}
   ${ice_LIBRARIES}
   #jderobot_interfaces
   ${ZLIB_LIBRARIES}
   #${ZeroCIce_LIBRARIES}
   ${OpenCV_LIBRARIES}
   ${OpenCV_LIBS}
   ${PCL_LIBRARIES}
   ${jderobot_libraries}
 )

 target_link_libraries(openni_ice_interface
   ${catkin_LIBRARIES}
   ${ice_LIBRARIES}
   #jderobot_interfaces
   ${ZLIB_LIBRARIES}
   #${ZeroCIce_LIBRARIES}
   ${OpenCV_LIBRARIES}
   ${OpenCV_LIBS}
   ${PCL_LIBRARIES}
   ${jderobot_libraries}
 )

 target_link_libraries(IceRosInterface
   ${catkin_LIBRARIES}
   ${ice_LIBRARIES}
   #jderobot_interfaces
   ${ZLIB_LIBRARIES}
   #${ZeroCIce_LIBRARIES}
   ${OpenCV_LIBRARIES}
   ${OpenCV_LIBS}
   ${PCL_LIBRARIES}
   ${jderobot_libraries}
 )

 target_link_libraries(RosViewer
   ${catkin_LIBRARIES}
   ${ice_LIBRARIES}
   #jderobot_interfaces
   ${ZLIB_LIBRARIES}
   #${ZeroCIce_LIBRARIES}
   ${OpenCV_LIBRARIES}
   ${OpenCV_LIBS}
   ${PCL_LIBRARIES}
   ${jderobot_libraries}
 )

