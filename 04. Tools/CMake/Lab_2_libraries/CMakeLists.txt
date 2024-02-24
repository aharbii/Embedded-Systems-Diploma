cmake_minimum_required(VERSION 3.23)

project(WIFIAPP)

set(SRC_FILES main.c src/calc.c)

add_subdirectory(${CMAKE_SOURCE_DIR}/lib)
add_executable(wifiapp ${SRC_FILES})

target_include_directories(wifiapp PUBLIC include/ lib/)
target_link_libraries(wifiapp PUBLIC wifi_lib)