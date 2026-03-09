add_executable(main main.cpp)

add_library(tool tool.cpp)
target_link_libraries(main tool)
