cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_definitions(-DTIXML_USE_STL)
#IF(NOT WIN32)
#add_definitions(-finput-charset=GBK)
#ENDIF()

#uncomment if you have defined messages
#rosbuild_genmsg()
#uncomment if you have defined services
#rosbuild_gensrv()

rosbuild_gensrv()

#common commands for building c++ executables and libraries
#rosbuild_add_library(${PROJECT_NAME} src/example.cpp)
#target_link_libraries(${PROJECT_NAME} another_library)
#rosbuild_add_boost_directories()
#rosbuild_link_boost(${PROJECT_NAME} thread)
#rosbuild_add_executable(example examples/example.cpp)
#target_link_libraries(example ${PROJECT_NAME})

rosbuild_add_boost_directories()
include_directories(
    "include"
    "include/utility/tinyxml"
)

file(GLOB utility_SRCS
    "src/utility/salt/*.cpp"
    "src/utility/tinyxml/*.cpp"
)
rosbuild_add_library(utility ${utility_SRCS})

file(GLOB dialogue_SRCS 
    "src/dialogue/*.cpp"
    "src/dialogue/main.cpp"
)
rosbuild_add_executable(dialogue ${dialogue_SRCS})
rosbuild_link_boost(dialogue thread)
target_link_libraries(dialogue utility)
add_dependencies(dialogue utility)
