cmake_minimum_required(VERSION 3.0.0)
project(zadanie-1 VERSION 0.1.0 LANGUAGES C CXX)
include(FetchContent)

enable_testing()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(fmt-10.2.1 EXCLUDE_FROM_ALL)


add_executable(main main.cpp)
target_link_libraries(main PRIVATE playlist)
target_link_libraries(main PRIVATE song)
target_link_libraries(main PRIVATE player)
