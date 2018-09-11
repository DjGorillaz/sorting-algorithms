find_package(GTest REQUIRED)

add_executable(test_sort test_sort.cpp)

set_target_properties(test_sort PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARTD_REQUIRED ON
)

target_link_libraries(test_sort PRIVATE GTest::GTest GTest::Main)

add_test(TestSort test_sort)

set_tests_properties(TestSort PROPERTIES TIMEOUT 5)