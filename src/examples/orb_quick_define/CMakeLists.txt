project(uorb_quick_define_example)

add_executable(${PROJECT_NAME} main.cc orb_topic.cc orb_topic.h)
target_link_libraries(${PROJECT_NAME} PRIVATE uorb)
