include_directories(../include)

# ###### Error Tests ########
add_executable(error_tests error_tests.cpp)
target_include_directories(error_tests PRIVATE cut::types)

# ###### Result Tests ########
add_executable(result_tests result_tests.cpp)
target_include_directories(error_tests PRIVATE cut::types)