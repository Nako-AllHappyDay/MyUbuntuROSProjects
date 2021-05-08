# toplevel CMakeLists.txt for a catkin workspace
# catkin/cmake/toplevel.cmake


cmake_minimum_required(VERSION 2.8.3)
project(helloworld_ws)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  rospy
  std_msgs
)

add_message_files(
   #DIRECTORY ~/Roboware_ws/helloworld_ws/src/msg      # 文件的目录, 默认在src下面，需要指明地址
   FILES
   hello.msg
 )

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES publish_subscribe_demo
  CATKIN_DEPENDS  roscpp rospy std_msgs message_runtime
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(hellotalker ~/Roboware_ws/helloworld_ws/src/hellotalker.cpp )
#必须添加add_dependencies，否则找不到自定义的msg产生的头文件
add_dependencies(hellotalker helloworld_ws_generate_messages_cpp)
target_link_libraries(hellotalker ${catkin_LIBRARIES})

add_executable(hellolistener ~/Roboware_ws/helloworld_ws/src/hellolistener.cpp )
add_dependencies(hellolistener helloworld_ws_generate_messages_cpp)
target_link_libraries(hellolistener ${catkin_LIBRARIES})

