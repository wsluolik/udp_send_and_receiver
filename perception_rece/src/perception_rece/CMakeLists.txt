cmake_minimum_required(VERSION 2.8.3)
project(perception_rece)
SET( CMAKE_BUILD_TYPE "Release" )
## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
             cv_bridge
             genmsg
             pcl_conversions
             pcl_ros
	     roscpp
	     rospy
	     std_msgs
	     geometry_msgs
	     message_generation
		)


## find PCL
find_package(PCL REQUIRED)
include_directories (${PCL_INCLUDE_DIRS})

## Generate messages in the 'msg' folder
 add_message_files(
   FILES
   Localization.msg
   PerceptionMsg.msg
   PerceptionListMsg.msg
 )


## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   std_msgs
   geometry_msgs
  # Or other packages containing msgs
 )



###################################
## catkin specific configuration ##

catkin_package(
		CATKIN_DEPENDS  std_msgs geometry_msgs message_runtime
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# protobuf
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})
link_directories(${PROTOBUF_LIBRARY})


include_directories(
 include
 protoc
 tools/display
 tools/comm
    ${catkin_INCLUDE_DIRS}
    ${EIGEN_INCLUDE_DIRS}
    ${PCL_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS}
)

add_definitions( ${EIGEN_DEFINITIONS} )
add_definitions( ${PCL_DEFINITIONS} )
## Declare a C++ library
add_library(
   rs_tools
   protoc/perceptron.pb.h
   protoc/perceptron.pb.cc
   tools/display/perceptron_show.h
   tools/display/perceptron_show.cpp
   tools/comm/communication.cpp
 )

target_link_libraries(rs_tools ${catkin_LIBRARIES} ${PROTOBUF_LIBRARY} ${PCL_LIBRARIES} ${OpenCV_LIBS})
add_executable( perception_rece
		src/perception_rece.cpp
		)
target_link_libraries(perception_rece rs_tools )



