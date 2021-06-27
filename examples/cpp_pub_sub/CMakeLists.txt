# Generate uorb message

add_executable(uorb_cpp_example main.cc)

add_subdirectory(uorb_msg)
target_link_libraries(uorb_cpp_example uorb_msg)
