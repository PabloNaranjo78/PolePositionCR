cmake_minimum_required(VERSION 3.20)
project(GUI C)

set(CMAKE_C_STANDARD 11)
set(SDL2_INCLUDE_DIR SDL2-devel-2.0.20-VC/SDL2-2.0.20/include)
set(SDL2_LIBRARY_DIR SDL2-devel-2.0.20-VC/SDL2-2.0.20/lib/x86)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIBRARY_DIR})

add_executable(GUI main.c)
target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
