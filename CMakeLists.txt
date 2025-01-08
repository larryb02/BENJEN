include(FetchContent)

cmake_minimum_required(VERSION 3.10)
project(2D_Engine)

#download dependencies
find_package(SDL2 QUIET)
if(SDL2_FOUND)
    message(STATUS "SDL2 found\ncontinuing...")
else()
    FetchContent_Declare(
        # sdl2
        SDL2
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-2.30.3
    )
    message(STATUS "SDL2 not found\ninstalling...")
    FetchContent_MakeAvailable(SDL2)

    find_package(SDL2 REQUIRED)
endif()
message(STATUS "CC=${CMAKE_C_COMPILER}")
# set(CMAKE_OSX_ARCHITECTURES "arm64")

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

# message(STATUS "Source Dir: ${SRC_DIR}")
# message(STATUS "Source files found: ${SRC_FILES}")
# message(STATUS "Include_Paths: ${INCLUDE_PATHS}")
# message(STATUS "COMPILER_FLAGS: ${COMPILER_FLAGS}")
# message(STATUS "SDL2 Include Dirs: ${SDL2_INCLUDE_DIRS}")

# message(STATUS "CC=${CMAKE_C_COMPILER}")

include_directories(${INCLUDE_PATHS})
link_directories(${LIBRARY_PATHS})
add_executable(main ${SRC_FILES})
target_compile_options(main PRIVATE ${COMPILER_FLAGS})
target_include_directories(main PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(main PRIVATE SDL2::SDL2)
