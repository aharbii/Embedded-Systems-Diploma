cmake_minimum_required(VERSION 3.23)
project(VARIABLESAPP VERSION 1.1)

set(SRC_FILES main.c src/calc.c)

add_subdirectory(${CMAKE_SOURCE_DIR}/lib)
add_executable(varapp ${SRC_FILES})

target_include_directories(varapp PUBLIC include/ lib/)
target_link_libraries(varapp PUBLIC wifi_lib)

#######################################################

# 1. Important Variables

message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")

message(STATUS "CMAKE_GENERATOR: ${CMAKE_GENERATOR}")

#######################################################

# 2. Set Values on Built in varaibles

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

message(STATUS "Show C Standarad: ${CMAKE_C_STANDARD}")
message(STATUS "Show C Standarad : ${CMAKE_C_STANDARD_REQUIRED}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message(STATUS "Show C++ Standarad: ${CMAKE_CXX_STANDARD}")
message(STATUS "Show C++ Standarad : ${CMAKE_CXX_STANDARD_REQUIRED}")

#######################################################

# 3. Commands can be uppercase or lowercase

MESSAGE(STATUS "Test")

#######################################################

# 4. Assign on Variables

set(SRC_FILES_TWO "main.c;src/calc.c")

#######################################################

# 5. Environment Variables

message(STATUS "PATH: $ENV{PATH}")

#######################################################

# 6. Set Value on Argument Options

message(STATUS "Argument Value is ${Myvalue}")
message(STATUS "CMAKE_CXX_STANDARD is ${CMAKE_CXX_STANDARD}")

#######################################################

# 7. Configure Files

set(PRODUCT_YEAR "2021")
configure_file(defaultconfig.h.in defaultconfig.h)
target_include_directories(varapp PUBLIC ${PROJECT_BINARY_DIR})

