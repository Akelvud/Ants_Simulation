cmake_minimum_required(VERSION 3.21)
project(Ants_Simulation)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/lib/SDL/include)
set(SDL2_LIB_DIR ${PROJECT_SOURCE_DIR}/lib/SDL/lib/x86)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(Ants_Simulation main.cpp visualization/Visualizer.cpp visualization/Visualizer.h visualization/Color.cpp visualization/Color.h objects/Ant.cpp objects/Ant.h)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)