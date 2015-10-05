cmake_minimum_required(VERSION 2.8.3)
project(ARDroneInterface)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  image_transport
  cv_bridge
  sensor_msgs
  geometry_msgs
)

find_package(OpenCV REQUIRED)

file(GLOB jderobot_libraries "/usr/local/lib/jderobot/*.so")

set(slice_output_dir ${CMAKE_CURRENT_SOURCE_DIR}/interfaces/cpp)

find_library(ice_LIBRARY1 Ice)
find_library(ice_LIBRARY2 IceUtil)
find_library(ice_LIBRARY3 IceStorm)
list(APPEND ice_LIBRARIES
    ${ice_LIBRARY1}
    ${ice_LIBRARY2}
    ${ice_LIBRARY3}
)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${catkin_INCLUDE_DIRS}
  ${slice_output_dir}
  ${slice_output_dir}/jderobot
  /usr/local/include/jderobot
)

file(GLOB CPP_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_executable(ARDroneInterface ${CPP_SRC})

target_link_libraries(ARDroneInterface
   ${catkin_LIBRARIES}
   ${ice_LIBRARIES}
#   ${OpenCV_LIBRARIES}
#   ${OpenCV_LIBS}
   ${jderobot_libraries}
#   ${PCL_LIBRARIES}
#   /usr/local/lib/jderobot/libJderobotInterfaces.so
#   /usr/local/lib/jderobot/libparallelIce.so
#   /usr/local/lib/jderobot/libcolorspaces.so
#   /usr/local/lib/jderobot/libcolorspacesmm.so


 )



