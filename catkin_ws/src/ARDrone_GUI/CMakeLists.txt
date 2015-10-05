cmake_minimum_required(VERSION 2.8.3)
project(ARDrone_GUI)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  rqt_gui
  rqt_gui_cpp
  cv_bridge
  geometry_msgs
  image_transport
  sensor_msgs
  std_msgs
)

find_package(Qt4 REQUIRED)
set(QT_USE_QTUITOOLS TRUE)         # QtUiTools is for dynamic form loading
include(${QT_USE_FILE})            # Include the files Qt needs
add_definitions(${QT_DEFINITIONS})

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES ARDrone_GUI
#  CATKIN_DEPENDS roscpp rospy rqt_gui rqt_gui_py
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)


find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED)

include(${QT_USE_FILE})

file(GLOB ARDrone_GUI_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB ARDrone_GUI_HDRS ${CMAKE_CURRENT_SOURCE_DIR}/include/ARDrone_GUI/*.h)

#set(ARDrone_GUI_HDRS
  #include/ARDrone_GUI/ARDrone_Plugin.h

#)

set(ARDrone_GUI_UIS
  ${CMAKE_CURRENT_SOURCE_DIR}/ui_gui.ui
  ${CMAKE_CURRENT_SOURCE_DIR}/colorFilter.ui
)

set(ARDrone_GUI_INCLUDE_DIRECTORIES
  include
  ${CMAKE_CURRENT_BINARY_DIR}
)

catkin_package(
  INCLUDE_DIRS ${ARDrone_GUI_INCLUDE_DIRECTORIES}
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS rqt_gui rqt_gui_cpp image_transport sensor_msgs cv_bridge
)
#catkin_python_setup()

qt4_wrap_cpp(ARDrone_GUI_MOCS ${ARDrone_GUI_HDRS})
qt4_wrap_ui(ARDrone_GUI_UIS_H ${ARDrone_GUI_UIS})

include_directories(${ARDrone_GUI_INCLUDE_DIRECTORIES} ${catkin_INCLUDE_DIRS})
add_executable(${PROJECT_NAME} ${ARDrone_GUI_SRCS} ${ARDrone_GUI_MOCS} ${ARDrone_GUI_UIS_H})
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_LIBRARIES})

#find_package(class_loader)
#class_loader_hide_library_symbols(${PROJECT_NAME})


