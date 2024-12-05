cmake_minimum_required(VERSION 3.8)
project(raytrace)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file (GLOB_RECURSE sources
		"${CMAKE_SOURCE_DIR}/*c"
)

add_executable(raytrace ${sources})

target_include_directories(raytrace PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_include_directories(raytrace PUBLIC "${CMAKE_SOURCE_DIR}/utils")
target_link_libraries(raytrace PUBLIC "${CMAKE_SOURCE_DIR}/utils/libutils.a")
target_include_directories(raytrace PUBLIC "${CMAKE_SOURCE_DIR}/libft_42")
target_link_libraries(raytrace PUBLIC "${CMAKE_SOURCE_DIR}/libft_42/libft.a")
target_include_directories(raytrace PUBLIC "${CMAKE_SOURCE_DIR}/mlx_linux")
target_link_libraries(raytrace PUBLIC "${CMAKE_SOURCE_DIR}/mlx_linux/libmlx_linux.a")
