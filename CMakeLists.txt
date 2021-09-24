cmake_minimum_required(VERSION 3.5)

project(uorb-examples)

set(CMAKE_CXX_STANDARD 11)

# uorb library
add_subdirectory(uorb)
link_libraries(uorb)

# pthread
find_package(Threads REQUIRED)
link_libraries(Threads::Threads)

add_subdirectory(examples)
