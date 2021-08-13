cmake_minimum_required(VERSION 3.19)
project(tdd)
add_subdirectory(tests)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(${CONAN_LIBS})
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

set(CMAKE_CXX_STANDARD 17)

# add_executable(tdd main.cpp tests/cppu_main.cpp tests/SoundexTest.cpp tests/test.cpp)
add_executable(tdd main.cpp Soundex.h)
