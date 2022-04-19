cmake_minimum_required(VERSION 3.22)
project(algorithm)

set(CMAKE_CXX_STANDARD 14)

#add_executable(algorithm
#        leetcode/leetcode-m1707.cpp leetcode/leetcode-m1708.cpp)
file(GLOB APP_SOURCES *.cpp */*.cpp *.cc */*.cc)
foreach (testsourcefile ${APP_SOURCES})
    get_filename_component(testname ${testsourcefile} NAME_WE)
    message("${testname}")
    add_executable(${testname} ${testsourcefile})
endforeach (testsourcefile ${APP_SOURCES})