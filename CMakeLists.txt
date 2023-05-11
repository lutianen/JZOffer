cmake_minimum_required(VERSION 3.20)
project(JZOffer VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILE_FEATURES OFF)

set(CMAKE_GENERATOR "Ninja")
set(CMAKE_BUILD_PARALLEL_LEVEL 16)

# set(CMAKE_CXX_FLAGS "-Wall -Werror")
set(CMAKE_CXX_FLAGS "-Wall")

add_subdirectory(JZOffer)
add_subdirectory(LQ)
add_subdirectory(Utils)
add_subdirectory(Exams)

