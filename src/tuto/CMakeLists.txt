cmake_minimum_required(VERSION 3.0.2)
project(tuto)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O3")
## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  pcl_ros
  roscpp
  sensor_msgs
  std_msgs
  tf
  pcl_conversions
  cv_bridge
  image_transport
)

##add_message_files(
  ##FILES
 ## dummy.msg
##)

##generate_messages(
 ##DEPENDENCIES
  ##std_msgs
##)

find_package(PCL REQUIRED QUIET)
find_package(OpenCV REQUIRED QUIET)
find_package(cmake_modules REQUIRED)
find_package(Eigen REQUIRED)

list(
  APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake
)

catkin_package(
 INCLUDE_DIRS include
  LIBRARIES my_project
  DEPENDS Eigen
  CATKIN_DEPENDS
                   pcl_ros 
                   roscpp 
                   sensor_msgs 
                   std_msgs 
                   tf
                   pcl_conversions
                   cv_bridge

#  DEPENDS system_lib
)

include_directories(
	include
	${catkin_INCLUDE_DIRS}
	${PCL_INCLUDE_DIRS}
  ${Eigen_INCLUDE_DIRS}
  ${openCV_INCLUDE_DIRS}


)

link_directories(
	include
  ${catkin_INCLUDE_DIRS}
	${OpenCV_LIBRARY_DIRS}
	${PCL_LIBRARY_DIRS}
  

)



add_executable(convexity src/project_1.cpp  )
                         #/home/kroker/catkin_ss/src/my_project/include/local_convexity.h  
                         #/home/kroker/catkin_ss/src/my_project/include/using_structure.h)
                         
add_dependencies(convexity ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(convexity
                       ${catkin_LIBRARIES}
                       ${Eigen_LIBRARIES}
                       ${OpenCV_LIBRARIES}
                       ${PCL_LIBRARIES}
                       
                       
                      )

