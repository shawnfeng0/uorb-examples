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

# pthread
find_package(Threads REQUIRED)
link_libraries(Threads::Threads)

# Generate uorb message
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/msg)

add_executable(uorb_cpp_example cpp_pub_sub_example.cpp)
target_link_libraries(uorb_cpp_example uorb_examples_msgs)
target_include_directories(uorb_cpp_example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/msg)

add_executable(uorb_quick_define_example orb_quick_define_example.cpp)
