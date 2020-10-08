# Generate uorb message
add_subdirectory(msg)

add_executable(uorb_cpp_example main.cc)
target_link_libraries(uorb_cpp_example uorb_examples_msgs)
target_include_directories(uorb_cpp_example PRIVATE msg)
