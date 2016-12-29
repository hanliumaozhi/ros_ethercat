cmake_minimum_required(VERSION 2.8)
project(ros)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(CMAKE_CXX_STANDARD 11)

set(ETHERCAT_INCLUDE_DIR /usr/local/include)
set(ETHERCAT_LIBRARY /usr/local/lib/libethercat.so.1.0.0)

include_directories(${ETHERCAT_INCLUDE_DIR})


set(SOURCE_FILES main.cpp motor.cpp motor.h Common.h slave_config.h EcatAdmin.cpp EcatAdmin.h)

add_executable(ros ${SOURCE_FILES})

target_link_libraries(ros ${ETHERCAT_LIBRARY})
