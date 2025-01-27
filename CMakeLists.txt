
cmake_minimum_required(VERSION 3.10)
project(BENJEN)

include(FetchContent)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CORE_DIR "Benjen/src/core")
set(SANDBOX_DIR "Sandbox")
set(VENDOR_DIR "Benjen/src/vendor")
set(INCLUDE_DIR "Benjen/src/include")

find_package(SDL2 QUIET)
if(SDL2_FOUND)
    message(STATUS "SDL2 Found")
else()
    message(STATUS "SDL2 Not Found, Installing...")
    FetchContent_Declare(
        SDL2
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG "SDL2"
    )
    FetchContent_MakeAvailable(SDL2)
endif()

file(GLOB_RECURSE SRC_FILES
    # "${SANDBOX_DIR}/*.cpp"
    "${CORE_DIR}/*.cpp"
    "${CORE_DIR}/*.c"
    "Benjen/src/Renderer/*.cpp"
    "Benjen/src/vendor/glad/glad.c"
    "Benjen/src/include/stb_image/*.cpp"
)

set(INCLUDE_PATHS "${VENDOR_DIR};${INCLUDE_DIR}")
set(COMPILER_FLAGS -Wall -g -v)
include_directories(${INCLUDE_PATHS})
link_directories(${LIBRARY_PATHS})
add_executable(main ${SRC_FILES})
target_compile_options(main PRIVATE ${COMPILER_FLAGS})
target_include_directories(main PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(main PRIVATE SDL2::SDL2)
