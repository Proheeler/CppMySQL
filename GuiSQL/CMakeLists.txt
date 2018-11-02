cmake_minimum_required(VERSION 2.8)

project(SQLApp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
FIND_PACKAGE(Boost COMPONENTS program_options REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

include_DIRECTORIES(usr/lib/mysql/)


# Tell CMake to run moc when necessary:
 set(CMAKE_AUTOMOC ON)
 # As moc files are generated in the binary dir, tell CMake
 # to always look for includes there:
 set(CMAKE_INCLUDE_CURRENT_DIR ON)

 # Widgets finds its own dependencies (QtGui and QtCore).
 find_package(Qt5Widgets REQUIRED)

 # The Qt5Widgets_INCLUDES also includes the include directories for
 # dependencies QtCore and QtGui
 include_directories(${Qt5Widgets_INCLUDES})

 # We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5.
 add_definitions(${Qt5Widgets_DEFINITIONS})

 # Executables fail to build with Qt 5 in the default configuration
 # without -fPIE. We add that here.
 set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")


 find_package(Qt5Sql REQUIRED)


 file(GLOB SOURCES
     headers/*.h
     sources/*.cpp
 )


add_executable(SQLApp  ${SRC} "main.cpp" ${SOURCES})
TARGET_LINK_LIBRARIES(SQLApp PUBLIC ${Boost_LIBRARIES} mysqlclient
                        ${Qt5Widgets_LIBRARIES} Qt5::Sql)#



