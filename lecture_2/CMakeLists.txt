cmake_minimum_required(VERSION 3.23)
project(CppBonn2018)


message(STATUS "!!!!!!!!!!!!!!!!!!!! ${PROJECT_SOURCE_DIR}")

include_directories(${PROJECT_SOURCE_DIR}/src)


add_subdirectory(${PROJECT_SOURCE_DIR}/src)
