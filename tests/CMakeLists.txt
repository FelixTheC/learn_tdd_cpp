cmake_minimum_required(VERSION 3.19)
project(tests)
set(CMAKE_CXX_STANDARD 17)


if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(${CONAN_LIBS})
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(tests test_main.cpp SoundexTest.cpp ../Soundex.h)

target_link_libraries(tests gmock gtest pthread)
