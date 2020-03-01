cmake_minimum_required(VERSION 3.0)
project (EUI-64)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE CXX_FLAGS "-Wall")
set(CMAKE_BUILD_TYPE Debug)

SET (SRCS src/main.cpp src/eui-64.cpp)
SET (LIBS )



add_executable(eui-64 ${SRCS})
target_include_directories(eui-64 PRIVATE include)
target_link_libraries(eui-64 ${LIBS})
