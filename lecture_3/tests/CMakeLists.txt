add_subdirectory(/usr/src/gtest
					${PROJECT_BINARY_DIR}/gtest)

include(CTest)


add_executable(test_tool test_tool.cpp)

target_link_libraries(test_tool
	tool
	gtest gtest_main
	)

add_test(
	test_tool
	tests/test_tool
	)
