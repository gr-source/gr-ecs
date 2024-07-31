cmake_minimum_required(VERSION 3.5.0)
project(gr-ecs VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

set(CMAKE_CXX_STANDARD 17)

set(component_src
    component/transform.cpp
)

add_executable(${PROJECT_NAME} main.cpp ${component_src} ecs/entity.cpp)

