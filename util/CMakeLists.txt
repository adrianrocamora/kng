cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Link the project with GTest and Pthreads
add_executable(bigUInt BigUInt.cpp)
target_link_libraries(bigUInt ${GTEST_LIBRARIES} pthread)
