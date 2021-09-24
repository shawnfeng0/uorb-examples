cmake_minimum_required(VERSION 3.5)

project(uorb-examples)

set(CMAKE_CXX_STANDARD 11)

# uorb and uorb_msg
add_subdirectory(src/lib/uorb)
add_subdirectory(src/lib/uorb_msg)

# pthread
find_package(Threads REQUIRED)
link_libraries(Threads::Threads)

include_directories(src/examples)

add_subdirectory(src/examples/cpp_pub_sub)
add_subdirectory(src/examples/orb_quick_define)
