cmake_minimum_required(VERSION 2.8)

project(SQLApp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
FIND_PACKAGE(Boost COMPONENTS program_options REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

include_DIRECTORIES(usr/lib/mysql/)

add_executable(SQLApp  ${SRC} "main.cpp")
TARGET_LINK_LIBRARIES(SQLApp PUBLIC ${Boost_LIBRARIES} mysqlclient ${Qt5Widgets_LIBRARIES})#



