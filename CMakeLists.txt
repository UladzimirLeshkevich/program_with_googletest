cmake_minimum_required(VERSION 3.14)

project(with_googletests)
add_executable(${PROJECT_NAME} main.cpp
                               my_functions.hpp
                               my_functions.cpp
                               unit_tests.hpp
                               )

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

################################
# GTest
################################
ADD_SUBDIRECTORY (googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} gtest gtest_main) 
