cmake_minimum_required(VERSION 3.5)

project(uorb-examples)

set(CMAKE_CXX_STANDARD 11)

# ulog library
add_subdirectory(ulog)
link_libraries(ulog)
include_directories(ulog/include)

# uorb library
add_subdirectory(uorb)
link_libraries(uorb)
include_directories(uorb/include)

# Generate uorb message
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/msg)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/msg)
link_libraries(uorb_examples_msgs)

# pthread
find_package(Threads REQUIRED)
link_libraries(Threads::Threads)

add_executable(uorb_cpp_example main.cpp)
