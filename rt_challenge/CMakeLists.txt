cmake_minimum_required(VERSION 3.8)
project(raytrace)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file (GLOB_RECURSE sources
		"${CMAKE_SOURCE_DIR}/*c"
)

add_executable(raytrace ${sources})

target_include_directories(raytrace PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_include_directories(raytrace PUBLIC "${CMAKE_SOURCE_DIR}/tuples")
target_link_libraries(raytrace PUBLIC "${CMAKE_SOURCE_DIR}/tuples/libtuples.a")
