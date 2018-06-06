cmake_minimum_required(VERSION 3.7)
project(myls)

find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(myls ${SOURCE_FILES})
target_link_libraries( myls ${Boost_LIBRARIES} )