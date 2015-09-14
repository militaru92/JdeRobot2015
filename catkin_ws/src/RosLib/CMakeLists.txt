cmake_minimum_required(VERSION 2.8.3)
project(RosLib)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
#  RosIceMessage
  cv_bridge
  geometry_msgs
  image_transport
  roscpp
  sensor_msgs
  std_msgs
)

find_package(PCL 1.2 REQUIRED)
find_package(OpenCV REQUIRED)
find_package( ZLIB REQUIRED )

file(GLOB jderobot_libraries "/usr/local/lib/jderobot/*.so")

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES RosIceGazebo
#  CATKIN_DEPENDS RosIceMessage
#  DEPENDS system_lib
)

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
  ${catkin_INCLUDE_DIRS}
  ${slice_output_dir}
  ${slice_output_dir}/jderobot
  /usr/local/include/jderobot
  ${OpenCV_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIR}
  #${CMAKE_CURRENT_SOURCE_DIR}/include
)

file(GLOB CPP_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(ros_ice SHARED ${CPP_SRC})
#add_dependencies(ros_ice RosIceMessage_generate_messages_cpp)

 target_link_libraries(ros_ice
   ${catkin_LIBRARIES}
   ${ice_LIBRARIES}
   #jderobot_interfaces
   ${ZLIB_LIBRARIES}
   #${ZeroCIce_LIBRARIES}
   ${OpenCV_LIBRARIES}
   ${OpenCV_LIBS}
   ${jderobot_libraries}
   ${PCL_LIBRARIES}
   /usr/local/lib/jderobot/libJderobotInterfaces.so
   /usr/local/lib/jderobot/libparallelIce.so
   /usr/local/lib/jderobot/libcolorspaces.so
   /usr/local/lib/jderobot/libcolorspacesmm.so


 )

FILE(GLOB HEADER_ROS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)
INSTALL (FILES ${HEADER_ROS_FILES} DESTINATION /usr/local/include/jderobot)
INSTALL (FILES ${CMAKE_CURRENT_SOURCE_DIR}/devel/lib/libros_ice.so DESTINATION /usr/local/lib/jderobot)


