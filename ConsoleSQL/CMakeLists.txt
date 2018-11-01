cmake_minimum_required(VERSION 2.8)

project(Boost_variant)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
FIND_PACKAGE(Boost COMPONENTS program_options REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})


include_DIRECTORIES(/home/vicheslav/Cppdev/Boost_variant)
LINK_DIRECTORIES(/home/vicheslav/Cppdev/Boost_variant)
include_DIRECTORIES(usr/lib/mysql/)

add_executable(Boost_variant  ${SRC} "main.cpp")
TARGET_LINK_LIBRARIES(Boost_variant PUBLIC ${Boost_LIBRARIES} mysqlclient )# ${SQL_LIBRARY}



