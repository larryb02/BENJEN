
cmake_minimum_required(VERSION 3.10)
project(BENJEN)

find_package(SDL2 QUIET)
if(SDL2_FOUND)
    message(STATUS "SDL2 found\ncontinuing...")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SRC_DIR "src")
set(SANDBOX_DIR "Sandbox")

file(GLOB_RECURSE SRC_FILES
    "${SANDBOX_DIR}/*.cpp"
    "${SRC_DIR}/*.cpp"
    "${SRC_DIR}/*.c"
    "include/stb_image/*.cpp" #another hack
)

set(INCLUDE_PATHS include)
set(COMPILER_FLAGS -Wall -g)
include_directories(${INCLUDE_PATHS})
link_directories(${LIBRARY_PATHS})
add_executable(main ${SRC_FILES})
target_compile_options(main PRIVATE ${COMPILER_FLAGS})
target_include_directories(main PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(main PRIVATE SDL2::SDL2)